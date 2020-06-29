#include <ctype.h>
#include <errno.h>
#include <fcntl.h> /* low-level i/o */
#include <inttypes.h>
#include <linux/videodev2.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

#include "rk_aiq_uapi_imgproc_ipc_ipc.h"
#include "rk_aiq_user_api_a3dlut_ipc.h"
#include "rk_aiq_user_api_ablc_ipc.h"
#include "rk_aiq_user_api_accm_ipc.h"
#include "rk_aiq_user_api_adebayer_ipc.h"
#include "rk_aiq_user_api_adehaze_ipc.h"
#include "rk_aiq_user_api_adpcc_ipc.h"
#include "rk_aiq_user_api_ae_ipc.h"
#include "rk_aiq_user_api_agamma_ipc.h"
#include "rk_aiq_user_api_ahdr_ipc.h"
#include "rk_aiq_user_api_alsc_ipc.h"
#include "rk_aiq_user_api_anr_ipc.h"
#include "rk_aiq_user_api_asharp_ipc.h"
#include "rk_aiq_user_api_awb_ipc.h"
#include "rk_aiq_user_api_sysctl_ipc.h"
#include "mediactl/mediactl.h"

#include "config.h"
#include "../utils/log.h"

#if CONFIG_DBUS
#include <gdbus.h>
#include "call_fun_ipc.h"
#include "fun_map.h"
#endif

#if CONFIG_DBSERVER
#include "db_monitor.h"
#endif

enum {
  LOG_ERROR,
  LOG_WARN,
  LOG_INFO,
  LOG_DEBUG
};

int enable_minilog = 0;
#define LOG_TAG "ispserver"
int ispserver_log_level = LOG_INFO;

#define CLEAR(x) memset(&(x), 0, sizeof(x))

/* Private v4l2 event */
#define CIFISP_V4L2_EVENT_STREAM_START (V4L2_EVENT_PRIVATE_START + 1)
#define CIFISP_V4L2_EVENT_STREAM_STOP (V4L2_EVENT_PRIVATE_START + 2)

#define RKAIQ_FILE_PATH_LEN 64
#define RKAIQ_CAMS_NUM_MAX 2
#define RKAIQ_FLASH_NUM_MAX 2

rk_aiq_sys_ctx_t *aiq_ctx = NULL;
rk_aiq_working_mode_t mode = RK_AIQ_WORKING_MODE_ISP_HDR2;
static int silent = 0;
static int width = 2688;
static int height = 1520;
static const char *mdev_path = NULL;
static bool need_sync_db = true;
#if CONFIG_OEM
const char *iq_file_dir = "/oem/etc/iqfiles/";
#else
const char *iq_file_dir = "/etc/iqfiles/";
#endif


struct rkaiq_media_info {
  char sd_isp_path[RKAIQ_FILE_PATH_LEN];
  char vd_params_path[RKAIQ_FILE_PATH_LEN];
  char vd_stats_path[RKAIQ_FILE_PATH_LEN];
  char sd_ispp_path[RKAIQ_FILE_PATH_LEN];

  struct {
    char sd_sensor_path[RKAIQ_FILE_PATH_LEN];
    char sd_lens_path[RKAIQ_FILE_PATH_LEN];
    char sd_flash_path[RKAIQ_FLASH_NUM_MAX][RKAIQ_FILE_PATH_LEN];
    bool link_enabled;
    char sensor_entity_name[32];
  } cams[RKAIQ_FLASH_NUM_MAX];
};

static struct rkaiq_media_info media_info;

static void errno_exit(const char *s) {
  LOG_INFO("%s error %d, %s\n", s, errno, strerror(errno));
  exit(EXIT_FAILURE);
}

static int xioctl(int fh, int request, void *arg) {
  int r;

  do {
    r = ioctl(fh, request, arg);
  } while (-1 == r && EINTR == errno);

  return r;
}

static int rkaiq_get_devname(struct media_device *device, const char *name,
                             char *dev_name) {
  const char *devname;
  struct media_entity *entity = NULL;

  entity = media_get_entity_by_name(device, name, strlen(name));
  if (!entity)
    return -1;

  devname = media_entity_get_devname(entity);

  if (!devname) {
    LOG_ERROR("can't find %s device path!", name);
    return -1;
  }

  strncpy(dev_name, devname, RKAIQ_FILE_PATH_LEN);

  LOG_INFO("get %s devname: %s\n", name, dev_name);

  return 0;
}

static int rkaiq_enumrate_modules(struct media_device *device,
                                  struct rkaiq_media_info *media_info) {
  uint32_t nents, i;
  const char *dev_name = NULL;
  int active_sensor = -1;

  nents = media_get_entities_count(device);
  for (i = 0; i < nents; ++i) {
    int module_idx = -1;
    struct media_entity *e;
    const struct media_entity_desc *ef;
    const struct media_link *link;

    e = media_get_entity(device, i);
    ef = media_entity_get_info(e);

    if (ef->type != MEDIA_ENT_T_V4L2_SUBDEV_SENSOR &&
        ef->type != MEDIA_ENT_T_V4L2_SUBDEV_FLASH &&
        ef->type != MEDIA_ENT_T_V4L2_SUBDEV_LENS)
      continue;

    if (ef->name[0] != 'm' && ef->name[3] != '_') {
      LOG_ERROR("sensor/lens/flash entity name format is incorrect,"
                      "pls check driver version !\n");
      return -1;
    }

    /* Retrive the sensor index from sensor name,
      * which is indicated by two characters after 'm',
      *	 e.g.  m00_b_ov13850 1-0010
      *			^^, 00 is the module index
      */
    module_idx = atoi(ef->name + 1);
    if (module_idx >= RKAIQ_CAMS_NUM_MAX) {
      LOG_ERROR("sensors more than two not supported, %s\n", ef->name);
      continue;
    }

    dev_name = media_entity_get_devname(e);

    switch (ef->type) {
    case MEDIA_ENT_T_V4L2_SUBDEV_SENSOR:
      strncpy(media_info->cams[module_idx].sd_sensor_path, dev_name,
              RKAIQ_FILE_PATH_LEN);

      link = media_entity_get_link(e, 0);
      if (link && (link->flags & MEDIA_LNK_FL_ENABLED)) {
        media_info->cams[module_idx].link_enabled = true;
        active_sensor = module_idx;
        strcpy(media_info->cams[module_idx].sensor_entity_name, ef->name);
      }
      break;
    case MEDIA_ENT_T_V4L2_SUBDEV_FLASH:
      // TODO, support multiple flashes attached to one module
      strncpy(media_info->cams[module_idx].sd_flash_path[0], dev_name,
              RKAIQ_FILE_PATH_LEN);
      break;
    case MEDIA_ENT_T_V4L2_SUBDEV_LENS:
      strncpy(media_info->cams[module_idx].sd_lens_path, dev_name,
              RKAIQ_FILE_PATH_LEN);
      break;
    default:
      break;
    }
  }

  if (active_sensor < 0) {
    LOG_ERROR("Not sensor link is enabled, does sensor probe correctly?\n");
    return -1;
  }

  return 0;
}

int rkaiq_get_media0_info(struct rkaiq_media_info *media_info) {
  struct media_device *device = NULL;
  int ret;

  device = media_device_new("/dev/media0");
  if (!device)
    return -ENOMEM;
  /* Enumerate entities, pads and links. */
  ret = media_device_enumerate(device);
  if (ret)
    return ret;
  if (!ret) {
    /* Try rkisp */
    ret =
        rkaiq_get_devname(device, "rkisp-isp-subdev", media_info->sd_isp_path);
    ret |= rkaiq_get_devname(device, "rkisp-input-params",
                             media_info->vd_params_path);
    ret |= rkaiq_get_devname(device, "rkisp-statistics",
                             media_info->vd_stats_path);
  }
  if (ret) {
    media_device_unref(device);
    return ret;
  }

  ret = rkaiq_enumrate_modules(device, media_info);
  media_device_unref(device);

  return ret;
}

int rkaiq_get_media1_info(struct rkaiq_media_info *media_info) {
  struct media_device *device = NULL;
  int ret;

  device = media_device_new("/dev/media1");
  if (!device)
    return -ENOMEM;
  /* Enumerate entities, pads and links. */
  ret = media_device_enumerate(device);
  if (ret)
    return ret;
  if (!ret) {
    /* Try rkisp */
    ret = rkaiq_get_devname(device, "rkispp_input_params",
                            media_info->sd_ispp_path);
  }
  if (ret) {
    media_device_unref(device);
    return ret;
  }

  media_device_unref(device);

  return ret;
}

static void init_engine(void) {
  int index;

#if CONFIG_DBSERVER
if (need_sync_db) {
  char *hdr_mode_db = dbserver_image_hdr_mode_get();
  while (!hdr_mode_db) {
    LOG_INFO("Get data is empty, please start dbserver\n");
    hdr_mode_db = dbserver_image_hdr_mode_get();
    sleep(1);
  }
  LOG_INFO("hdr_mode_db: %s \n", hdr_mode_db);
  if (!strcmp(hdr_mode_db, "close"))
    setenv("HDR_MODE", "0", 1);
  else
    setenv("HDR_MODE", "1", 1);
}
#endif

  char *hdr_mode = getenv("HDR_MODE");
  if (hdr_mode) {
    LOG_INFO("hdr mode: %s \n", hdr_mode);
    if (0 == atoi(hdr_mode))
      mode = RK_AIQ_WORKING_MODE_NORMAL;
    else if (1 == atoi(hdr_mode))
      mode = RK_AIQ_WORKING_MODE_ISP_HDR2;
    else if (2 == atoi(hdr_mode))
      mode = RK_AIQ_WORKING_MODE_ISP_HDR3;
  }

  for (index = 0; index < RKAIQ_CAMS_NUM_MAX; index++)
    if (media_info.cams[index].link_enabled)
      break;

  aiq_ctx = rk_aiq_uapi_sysctl_init(media_info.cams[index].sensor_entity_name,
                                    iq_file_dir, NULL, NULL);

  if (rk_aiq_uapi_sysctl_prepare(aiq_ctx, width, height, mode)) {
    LOG_INFO("rkaiq engine prepare failed !\n");
    exit(-1);
  }

#if CONFIG_DBSERVER
if (need_sync_db) {
  /* BLC */
  int hdr_level = 0;
  dbserver_image_blc_get(NULL, &hdr_level);
  blc_hdr_level_set(hdr_level);
  /* IMAGE_ADJUSTMENT */
  int brightness = 50;
  int contrast = 50;
  int saturation = 50;
  int sharpness = 50;
  dbserver_image_adjustment_get(&brightness, &contrast, &saturation, &sharpness);
  LOG_INFO("brightness:%d, contrast:%d, saturation:%d, sharpness:%d\n\n",
         brightness, contrast, saturation, sharpness);
  rk_aiq_uapi_setBrightness(aiq_ctx, brightness);
  rk_aiq_uapi_setContrast(aiq_ctx, contrast);
  rk_aiq_uapi_setSaturation(aiq_ctx, saturation);
  rk_aiq_uapi_setSharpness(aiq_ctx, sharpness);
  /* EXPOSURE */
  char exposure_time [20] = "1";
  int exposure_gain = 0;
  dbserver_image_exposure_get(exposure_time, &exposure_gain);
  LOG_INFO("exposure_time is %s, exposure_gain is %d\n\n", exposure_time, exposure_gain);
  exposure_time_set(exposure_time);
  exposure_gain_set(exposure_gain);
  /* WHITE_BALANCE */
  char white_balance_style [20];
  dbserver_image_white_balance_get(white_balance_style, NULL, NULL);
  LOG_INFO("white_balance_style is %s\n\n", white_balance_style);
  white_balance_style_set(white_balance_style);
  /* IMAGE_ENHANCEMENT */
  char nr_mode [20] = "close";
  char fec_mode [20] = "close";
  char dehaze_mode [20] = "close";
  int denoise_level = 0;
  int spatial_level = 0;
  int temporal_level = 0;
  int dehaze_level = 0;
  dbserver_image_enhancement_get(nr_mode, fec_mode, dehaze_mode, &denoise_level, &spatial_level, &temporal_level, &dehaze_level);
  LOG_INFO("nr_mode:%s, fec_mode:%s, dehaze_mode:%s, denoise_level:%d, spatial_level:%d, temporal_level:%d, dehaze_level:%d\n\n",
          nr_mode, fec_mode, dehaze_mode, denoise_level, spatial_level, temporal_level, dehaze_level);
  nr_mode_set(nr_mode);
  fec_mode_set(fec_mode);
  dehaze_mode_set(dehaze_mode);
  /* IMAGE_ADJUSTMENT */
  char frequency_mode[20] = "PAL(50HZ)";
  dbserver_image_video_adjustment_get(frequency_mode);
  LOG_INFO("frequency_mode is %s\n\n", frequency_mode);
  frequency_mode_set(frequency_mode);
  /* NIGHT_TO_DAY*/
  night_to_day_param_cap_set_db();
  night_to_day_param_set();

}
#endif
}

static void start_engine(void) {
  rk_aiq_uapi_sysctl_start(aiq_ctx);
  if (aiq_ctx == NULL) {
    LOG_INFO("rkisp_init engine failed\n");
    exit(-1);
  } else {
    LOG_INFO("rkisp_init engine succeed\n");
  }
}

static void stop_engine(void) { rk_aiq_uapi_sysctl_stop(aiq_ctx); }

static void deinit_engine(void) { rk_aiq_uapi_sysctl_deinit(aiq_ctx); }

// blocked func
static int wait_stream_event(int fd, unsigned int event_type, int time_out_ms) {
  int ret;
  struct v4l2_event event;

  CLEAR(event);

  do {
    /*
     * xioctl instead of poll.
     * Since poll() cannot wait for input before stream on,
     * it will return an error directly. So, use ioctl to
     * dequeue event and block until sucess.
     */
    ret = xioctl(fd, VIDIOC_DQEVENT, &event);
    if (ret == 0 && event.type == event_type) {
      return 0;
    }
  } while (true);

  return -1;
}

static int subscrible_stream_event(int fd, bool subs) {
  struct v4l2_event_subscription sub;
  int ret = 0;

  CLEAR(sub);
  sub.type = CIFISP_V4L2_EVENT_STREAM_START;
  ret = xioctl(fd, subs ? VIDIOC_SUBSCRIBE_EVENT : VIDIOC_UNSUBSCRIBE_EVENT,
               &sub);
  if (ret) {
    LOG_INFO("can't subscribe %s start event!\n", media_info.sd_ispp_path);
    exit(EXIT_FAILURE);
  }

  CLEAR(sub);
  sub.type = CIFISP_V4L2_EVENT_STREAM_STOP;
  ret = xioctl(fd, subs ? VIDIOC_SUBSCRIBE_EVENT : VIDIOC_UNSUBSCRIBE_EVENT,
               &sub);
  if (ret) {
    LOG_INFO("can't subscribe %s stop event!\n", media_info.vd_params_path);
  }

  LOG_INFO("subscribe events from %s success !\n", media_info.vd_params_path);

  return 0;
}

void *thread_func(void *arg) {
  int ret = 0;
  int isp_fd;
  unsigned int stream_event = -1;



  /* Line buffered so that printf can flash every line if redirected to
   * no-interactive device.
   */
  setlinebuf(stdout);

  for (;;) {
    /* Refresh media info so that sensor link status updated */
    if (rkaiq_get_media0_info(&media_info))
      errno_exit("Bad media0 topology\n");
    if (rkaiq_get_media1_info(&media_info))
      errno_exit("Bad media1 topology\n");

    //isp_fd = open(media_info.vd_params_path, O_RDWR);
    isp_fd = open(media_info.sd_ispp_path, O_RDWR);
    if (isp_fd < 0) {
      LOG_INFO("open %s failed %s\n", media_info.sd_ispp_path, strerror(errno));
      pthread_exit(0);
    }

    subscrible_stream_event(isp_fd, true);
    init_engine();
    LOG_INFO("wait stream start event...\n");
    wait_stream_event(isp_fd, CIFISP_V4L2_EVENT_STREAM_START, -1);
    LOG_INFO("wait stream start event success ...\n");
    rk_aiq_state_t aiq_state = rk_aiq_get_state();
    LOG_INFO("state=%d\n", aiq_state);
    if (aiq_state == AIQ_STATE_INVALID) {
      LOG_INFO("start engine...\n");
      start_engine();
    }

    LOG_INFO("wait stream stop event...\n");
    wait_stream_event(isp_fd, CIFISP_V4L2_EVENT_STREAM_STOP, -1);
    LOG_INFO("wait stream stop event success ...\n");
    if (aiq_state == AIQ_STATE_INVALID) {
      LOG_INFO("stop engine...\n");
      stop_engine();
    }
    deinit_engine();
    subscrible_stream_event(isp_fd, false);
    close(isp_fd);
    LOG_INFO("----------------------------------------------\n\n");
  }
}

static void main_exit(void) {
  LOG_INFO("server %s\n", __func__);
  if (aiq_ctx) {
     LOG_INFO("stop engine...\n");
     stop_engine();
     LOG_INFO("deinit engine...\n");
     deinit_engine();
     aiq_ctx = NULL;
}
#if CONFIG_DBUS
  call_fun_ipc_server_deinit();
#endif
}

void signal_crash_handler(int sig) {
#if CONFIG_DBUS
  call_fun_ipc_server_deinit();
#endif
  exit(-1);
}

void signal_exit_handler(int sig) {
#if CONFIG_DBUS
  call_fun_ipc_server_deinit();
#endif
  exit(0);
}

int main(int argc, char **argv) {
#ifdef ENABLE_MINILOGGER
    enable_minilog = 1;
    __minilog_log_init(argv[0], NULL, false, false, "ispserver","1.0.0");
#endif

  argv += 1;
  if (*argv) {
     if (strcmp(*argv, "-no-sync-db") == 0)
         need_sync_db = false;
  }
  pthread_t tidp;
  if (pthread_create(&tidp, NULL, thread_func, NULL) != 0)
    return -1;

#if CONFIG_DBUS
  pthread_detach(pthread_self());
  GMainLoop *main_loop;
  atexit(main_exit);
  signal(SIGTERM, signal_exit_handler);
  signal(SIGINT, signal_exit_handler);
  signal(SIGPIPE, SIG_IGN);
  signal(SIGBUS, signal_crash_handler);
  signal(SIGSEGV, signal_crash_handler);
  signal(SIGFPE, signal_crash_handler);
  signal(SIGABRT, signal_crash_handler);

  call_fun_ipc_server_init(map, sizeof(map) / sizeof(struct FunMap), DBUS_NAME,
                           DBUS_IF, DBUS_PATH, 0);

  main_loop = g_main_loop_new(NULL, FALSE);

#if CONFIG_DBSERVER
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, (void*)database_init, NULL);
#endif

  LOG_INFO("call_fun_ipc_demo_server init\n");

  g_main_loop_run(main_loop);
  if (main_loop)
    g_main_loop_unref(main_loop);
#else
  void* ret;
  pthread_join(tidp,&ret);
#endif
  return 0;
}
