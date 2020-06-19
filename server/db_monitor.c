#if CONFIG_DBSERVER

#include <errno.h>
#include <gdbus.h>
#include <glib.h>
#include <linux/kernel.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "call_fun_ipc.h"
#include "config.h"
#include "mediactl/mediactl.h"
#include "json-c/json.h"
#include "db_monitor.h"
#include "rkaiq/uAPI/rk_aiq_user_api_imgproc.h"
#include "rkaiq/uAPI/rk_aiq_user_api_sysctl.h"
#include "dbserver.h"

extern char *aiq_NR_mode;
extern char *aiq_FEC_mode;
extern rk_aiq_sys_ctx_t *aiq_ctx;

static DBusConnection *connection = 0;

#define DBSERVER  "rockchip.dbserver"
#define DBSERVER_PATH      "/"

#define DBSERVER_MEDIA_INTERFACE  DBSERVER ".media"

#define TABLE_IMAGE_SCENARIO "image_scenario"
#define TABLE_IMAGE_ADJUSTMENT "image_adjustment"
#define TABLE_IMAGE_EXPOSURE "image_exposure"
#define TABLE_IMAGE_NIGHT_TO_DAY "image_night_to_day"
#define TABLE_IMAGE_BLC "image_blc"
#define TABLE_IMAGE_WHITE_BLANCE "image_white_blance"
#define TABLE_IMAGE_ENHANCEMENT "image_enhancement"
#define TABLE_IMAGE_VIDEO_ADJUSTMEN "image_video_adjustment"

static void DataChanged(char *json_str)
{
    printf("DataChanged, json is %s\n", json_str);
    json_object *j_cfg;
    json_object *j_key = 0;
    json_object *j_data = 0;
    char *table = 0;

    j_cfg = json_tokener_parse(json_str);
    table = (char *)json_object_get_string(json_object_object_get(j_cfg, "table"));
    j_key = json_object_object_get(j_cfg, "key");
    j_data = json_object_object_get(j_cfg, "data");
    char *cmd = (char *)json_object_get_string(json_object_object_get(j_cfg, "cmd"));

    if (g_str_equal(table, TABLE_IMAGE_BLC)) {
        if (!g_str_equal(cmd, "Update"))
            return;
        json_object *sHDR = json_object_object_get(j_data, "sHDR");
        if (sHDR) {
            char *HDR_mode = (char *)json_object_get_string(sHDR);
            printf("%s, HDR_mode is %s\n", __func__, HDR_mode);
        }
        // if (!strcmp(HDR_mode, "close"))
        //     rk_aiq_uapi_setHDRMode(aiq_ctx, OP_AUTO);
        // else
        //     rk_aiq_uapi_setHDRMode(aiq_ctx, OP_MANUALl);
    } else if (g_str_equal(table, TABLE_IMAGE_ENHANCEMENT)) {
        if (!g_str_equal(cmd, "Update"))
            return;
        json_object *sNoiseReduceMode = json_object_object_get(j_data, "sNoiseReduceMode");
        json_object *sFEC = json_object_object_get(j_data, "sFEC");
        if (sNoiseReduceMode) {
            char *NR_mode = (char *)json_object_get_string(sNoiseReduceMode);
            NR_mode_set(NR_mode);
        }
        if (sFEC) {
            char *FEC_mode = (char *)json_object_get_string(sFEC);
            FEC_mode_set(FEC_mode);
        }
    } else if (g_str_equal(table, TABLE_IMAGE_ADJUSTMENT)) {
        if (!g_str_equal(cmd, "Update"))
            return;
        json_object *iBrightness = json_object_object_get(j_data, "iBrightness");
        json_object *iContrast = json_object_object_get(j_data, "iContrast");
        json_object *iSaturation = json_object_object_get(j_data, "iSaturation");
        json_object *iSharpness = json_object_object_get(j_data, "iSharpness");
        if (iBrightness) {
            int brightness = json_object_get_int(iBrightness);
            rk_aiq_uapi_setBrightness(aiq_ctx, brightness);
        }
        if (iContrast) {
            int contrast = json_object_get_int(iContrast);
            rk_aiq_uapi_setContrast(aiq_ctx, contrast);
        }
        if (iSaturation) {
            int saturation = json_object_get_int(iSaturation);
            rk_aiq_uapi_setSaturation(aiq_ctx, saturation);
        }
        if (iSharpness) {
            int sharpness = json_object_get_int(iSharpness);
            rk_aiq_uapi_setSharpness(aiq_ctx, sharpness);
        }
    }

    json_object_put(j_cfg);
}

static DBusHandlerResult database_monitor_changed(
    DBusConnection *connection,
    DBusMessage *message, void *user_data)
{
    printf("database_monitor_changed\n");
    bool *enabled = user_data;
    DBusMessageIter iter;
    DBusHandlerResult handled;

    handled = DBUS_HANDLER_RESULT_HANDLED;
    if (dbus_message_is_signal(message, DBSERVER_MEDIA_INTERFACE,
                               "DataChanged")) {
        char *json_str;

        dbus_message_iter_init(message, &iter);
        dbus_message_iter_get_basic(&iter, &json_str);
        DataChanged(json_str);

        return handled;
    }

    return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}

char *dbserver_image_hdr_mode_get(void)
{
    char *json_str = NULL;
    json_str = dbserver_media_get(TABLE_IMAGE_BLC);
    // printf("%s, json_str is %s\n", __func__, json_str);
    if (json_str == NULL) {
        printf("image blc table is null\n");
        return NULL;
    }
    json_object *j_cfg = json_tokener_parse(json_str);
    json_object *j_data_array = json_object_object_get(j_cfg, "jData");
    json_object *j_data = json_object_array_get_idx(j_data_array, 0);
    char *HDR_mode = (char *)json_object_get_string(json_object_object_get(j_data, "sHDR"));

    free(json_str);
    return HDR_mode;
}

char *dbserver_image_nr_mode_get(void)
{
    char *json_str = NULL;
    json_str = dbserver_media_get(TABLE_IMAGE_ENHANCEMENT);
    // printf("%s, json_str is %s\n", __func__, json_str);
    if (json_str == NULL) {
        printf("image enhancement table is null\n");
        return NULL;
    }
    json_object *j_cfg = json_tokener_parse(json_str);
    json_object *j_data_array = json_object_object_get(j_cfg, "jData");
    json_object *j_data = json_object_array_get_idx(j_data_array, 0);
    char *NR_mode = (char *)json_object_get_string(json_object_object_get(j_data, "sNoiseReduceMode"));

    free(json_str);
    return NR_mode;
}

char *dbserver_image_fec_mode_get(void)
{
    char *json_str = NULL;
    json_str = dbserver_media_get(TABLE_IMAGE_ENHANCEMENT);
    // printf("%s, json_str is %s\n", __func__, json_str);
    if (json_str == NULL) {
        printf("image enhancement table is null\n");
        return NULL;
    }
    json_object *j_cfg = json_tokener_parse(json_str);
    json_object *j_data_array = json_object_object_get(j_cfg, "jData");
    json_object *j_data = json_object_array_get_idx(j_data_array, 0);
    char *FEC_mode = (char *)json_object_get_string(json_object_object_get(j_data, "sFEC"));

    free(json_str);
    return FEC_mode;
}

void dbserver_image_adjustment_get(int *brightness, int *contrast, int *saturation, int *sharpness)
{
    char *json_str = NULL;
    json_str = dbserver_media_get(TABLE_IMAGE_ADJUSTMENT);
    printf("%s, json_str is %s\n", __func__, json_str);
    if (json_str == NULL) {
        printf("image enhancement table is null\n");
        return NULL;
    }
    json_object *j_cfg = json_tokener_parse(json_str);
    json_object *j_data_array = json_object_object_get(j_cfg, "jData");
    json_object *j_data = json_object_array_get_idx(j_data_array, 0);
    *brightness = (int)json_object_get_int(json_object_object_get(j_data, "iBrightness"));
    *contrast = (int)json_object_get_int(json_object_object_get(j_data, "iContrast"));
    *saturation = (int)json_object_get_int(json_object_object_get(j_data, "iSaturation"));
    *sharpness = (int)json_object_get_int(json_object_object_get(j_data, "iSharpness"));

    free(json_str);
}

void NR_mode_set(char *mode)
{
    printf("%s, mode is %s\n", __func__, mode);
    if (!strcmp(mode,"close"))
        rk_aiq_uapi_sysctl_setModuleCtl(aiq_ctx, RK_MODULE_TNR, false);
    else
        rk_aiq_uapi_sysctl_setModuleCtl(aiq_ctx, RK_MODULE_TNR, true);
}

void FEC_mode_set(char *mode)
{
    printf("%s, mode is %s\n", __func__, mode);
    if (!strcmp(mode,"close"))
        rk_aiq_uapi_sysctl_setModuleCtl(aiq_ctx, RK_MODULE_FEC, false);
    else
        rk_aiq_uapi_sysctl_setModuleCtl(aiq_ctx, RK_MODULE_FEC, true);
}

void database_init(void)
{
    printf("database_init\n");
    DBusError err;

    dbus_error_init(&err);
    connection = g_dbus_setup_bus(DBUS_BUS_SYSTEM, NULL, &err);

    dbus_connection_add_filter(connection,
                               database_monitor_changed, NULL, NULL);
    dbus_bus_add_match(connection,
                       "type='signal',interface='rockchip.dbserver.media'", &err);
    if (dbus_error_is_set(&err)) {
        fprintf(stderr, "Error: %s\n", err.message);
        return;
    }

    printf("database_init over\n");
}

#endif
