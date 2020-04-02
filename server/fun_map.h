#ifndef _RK_AIQ_USER_API_FUN_MAP_H_
#define _RK_AIQ_USER_API_FUN_MAP_H_
#if 0
#include "rk_aiq_upi_imgproc_ipc.h"
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
#endif
#include "rk_aiq_user_api_sysctl_ipc.h"

struct FunMap map[] = {
#if 0
    //rk_aiq_upi_imgproc_ipc
    {"rk_aiq_uapi_setExpMode", &rk_aiq_uapi_setExpMode},
    {"rk_aiq_uapi_getExpMode", &rk_aiq_uapi_getExpMode},
    {"rk_aiq_uapi_setAeMode", &rk_aiq_uapi_setAeMode},
    {"rk_aiq_uapi_getAeMode", &rk_aiq_uapi_getAeMode},
    {"rk_aiq_uapi_setExpGainRange", &rk_aiq_uapi_setExpGainRange},
    {"rk_aiq_uapi_getExpGainRange", &rk_aiq_uapi_getExpGainRange},
    {"rk_aiq_uapi_setExpTimeRange", &rk_aiq_uapi_setExpTimeRange},
    {"rk_aiq_uapi_getExpTimeRange", &rk_aiq_uapi_getExpTimeRange},
    {"rk_aiq_uapi_setHLCMode", &rk_aiq_uapi_setHLCMode},
    {"rk_aiq_uapi_setLExpMode", &rk_aiq_uapi_setLExpMode},
    {"rk_aiq_uapi_getLExpMode", &rk_aiq_uapi_getLExpMode},
    {"rk_aiq_uapi_setMLExp", &rk_aiq_uapi_setMLExp},
    {"rk_aiq_uapi_getMLExp", &rk_aiq_uapi_getMLExp},
    {"rk_aiq_uapi_setExpPwrLineFreqMode", &rk_aiq_uapi_setExpPwrLineFreqMode},
    {"rk_aiq_uapi_getExpPwrLineFreqMode", &rk_aiq_uapi_getExpPwrLineFreqMode},
    {"rk_aiq_uapi_setDayNSwMode", &rk_aiq_uapi_setDayNSwMode},
    {"rk_aiq_uapi_getDayNSwMode", &rk_aiq_uapi_getDayNSwMode},
    {"rk_aiq_uapi_setMDNScene", &rk_aiq_uapi_setMDNScene},
    {"rk_aiq_uapi_getMDNScene", &rk_aiq_uapi_getMDNScene},
    {"rk_aiq_uapi_setADNSens", &rk_aiq_uapi_setADNSens},
    {"rk_aiq_uapi_getADNSens", &rk_aiq_uapi_getADNSens},
    {"rk_aiq_uapi_setFLightMode", &rk_aiq_uapi_setFLightMode},
    {"rk_aiq_uapi_getFLightMode", &rk_aiq_uapi_getFLightMode},
    {"rk_aiq_uapi_setMFLight", &rk_aiq_uapi_setMFLight},
    {"rk_aiq_uapi_getMFLight", &rk_aiq_uapi_getMFLight},
    {"rk_aiq_uapi_setWBMode", &rk_aiq_uapi_setWBMode},
    {"rk_aiq_uapi_getWBMode", &rk_aiq_uapi_getWBMode},
    {"rk_aiq_uapi_lockAWB", &rk_aiq_uapi_lockAWB},
    {"rk_aiq_uapi_unlockAWB", &rk_aiq_uapi_unlockAWB},
    {"rk_aiq_uapi_setAWBRange", &rk_aiq_uapi_setAWBRange},
    {"rk_aiq_uapi_getAWBRange", &rk_aiq_uapi_getAWBRange},
    {"rk_aiq_uapi_setMWBScene", &rk_aiq_uapi_setMWBScene},
    {"rk_aiq_uapi_getMWBScene", &rk_aiq_uapi_getMWBScene},
    {"rk_aiq_uapi_setMWBGain", &rk_aiq_uapi_setMWBGain},
    {"rk_aiq_uapi_getMWBGain", &rk_aiq_uapi_getMWBGain},
    {"rk_aiq_uapi_setMWBCT", &rk_aiq_uapi_setMWBCT},
    {"rk_aiq_uapi_getMWBCT", &rk_aiq_uapi_getMWBCT},
    {"rk_aiq_uapi_setCrSuppsn", &rk_aiq_uapi_setCrSuppsn},
    {"rk_aiq_uapi_getCrSuppsn", &rk_aiq_uapi_getCrSuppsn},
    {"rk_aiq_uapi_setFocusMode"    ,&rk_aiq_uapi_setFocusMode      },
    {"rk_aiq_uapi_getFocusMode"    ,&rk_aiq_uapi_getFocusMode      },
    {"rk_aiq_uapi_setMinFocusDis",&rk_aiq_uapi_setMinFocusDis  },
    {"rk_aiq_uapi_getMinFocusDis"    ,&rk_aiq_uapi_getMinFocusDis  },
    {"rk_aiq_uapi_setOpZoomRange"    ,&rk_aiq_uapi_setOpZoomRange  } ,                    
    {"rk_aiq_uapi_getOpZoomRange"    ,&rk_aiq_uapi_getOpZoomRange  },                     
    {"rk_aiq_uapi_setOpZoomSpeed"    ,&rk_aiq_uapi_setOpZoomSpeed  },
    {"rk_aiq_uapi_getOpZoomSpeed"    ,&rk_aiq_uapi_getOpZoomSpeed  },
    {"rk_aiq_uapi_setHDRMode"    ,&rk_aiq_uapi_setHDRMode          },
    {"rk_aiq_uapi_getHDRMode"    ,&rk_aiq_uapi_getHDRMode          },
    {"rk_aiq_uapi_setMHDRStrth"    ,&rk_aiq_uapi_setMHDRStrth      },
    {"rk_aiq_uapi_getMHDRStrth"    ,&rk_aiq_uapi_getMHDRStrth      },
    {"rk_aiq_uapi_setNRMode"    ,&rk_aiq_uapi_setNRMode            },
    {"rk_aiq_uapi_getNRMode"    ,&rk_aiq_uapi_getNRMode            },
    {"rk_aiq_uapi_setANRStrth"    ,&rk_aiq_uapi_setANRStrth        },
    {"rk_aiq_uapi_getANRStrth"    ,&rk_aiq_uapi_getANRStrth        },
    {"rk_aiq_uapi_setMSpaNRStrth"    ,&rk_aiq_uapi_setMSpaNRStrth  },
    {"rk_aiq_uapi_getMSpaNRStrth"    ,&rk_aiq_uapi_getMSpaNRStrth  },
    {"rk_aiq_uapi_setMTNRStrth"    ,&rk_aiq_uapi_setMTNRStrth      },
    {"rk_aiq_uapi_getMTNRStrth"    ,&rk_aiq_uapi_getMTNRStrth      },
    {"rk_aiq_uapi_setDhzMode"    ,&rk_aiq_uapi_setDhzMode          },
    {"rk_aiq_uapi_getDhzMode"    ,&rk_aiq_uapi_getDhzMode          },
    {"rk_aiq_uapi_setMDhzStrth"    ,&rk_aiq_uapi_setMDhzStrth      },
    {"rk_aiq_uapi_getMDhzStrth"    ,&rk_aiq_uapi_getMDhzStrth      },
    {"rk_aiq_uapi_setContrast"    ,&rk_aiq_uapi_setContrast        },
    {"rk_aiq_uapi_getContrast"    ,&rk_aiq_uapi_getContrast        },
    {"rk_aiq_uapi_setBrightness"    ,&rk_aiq_uapi_setBrightness    },
    {"rk_aiq_uapi_getBrightness"    ,&rk_aiq_uapi_getBrightness    },
    {"rk_aiq_uapi_setSaturation"    ,&rk_aiq_uapi_setSaturation    },
    {"rk_aiq_uapi_getSaturation"    ,&rk_aiq_uapi_getSaturation    },
    {"rk_aiq_uapi_setSharpness"    ,&rk_aiq_uapi_setSharpness      },
    {"rk_aiq_uapi_getSharpness"    ,&rk_aiq_uapi_getSharpness      },

     //rk_aiq_user_api_a3dlut_ipc
    {"rk_aiq_user_api_a3dlut_SetAttrib" , &rk_aiq_user_api_a3dlut_SetAttrib            },
    {"rk_aiq_user_api_a3dlut_GetAttrib" , &rk_aiq_user_api_a3dlut_GetAttrib            },
    {"rk_aiq_user_api_a3dlut_Query3dlutInfo" , &rk_aiq_user_api_a3dlut_Query3dlutInfo  },

    //rk_aiq_user_api_ablc_ipc
    {"rk_aiq_user_api_ablc_SetAttrib_ipc" ,  &rk_aiq_user_api_ablc_SetAttrib_ipc},
    {"rk_aiq_user_api_ablc_GetAttrib_ipc" ,   &rk_aiq_user_api_ablc_GetAttrib_ipc  },

   //rk_aiq_user_api_accm_ipc
    {"rk_aiq_user_api_accm_SetAttrib_ipc"  ,   &rk_aiq_user_api_accm_SetAttrib_ipc},
    {"rk_aiq_user_api_accm_GetAttrib_ipc"  ,   &rk_aiq_user_api_accm_GetAttrib_ipc},
    {"rk_aiq_user_api_accm_QueryCcmInfo_ipc" , &rk_aiq_user_api_accm_GetAttrib_ipc},
     
   //rk_aiq_user_api_adebayer_ipc
    {"rk_aiq_user_api_adebayer_SetAttrib", &rk_aiq_user_api_adebayer_SetAttrib},
    //rk_aiq_user_api_adehaze_ipc
    {"rk_aiq_user_api_adehaze_setSwAttrib_ipc"  ,   &rk_aiq_user_api_adehaze_setSwAttrib_ipc},
    {"rk_aiq_user_api_adehaze_getSwAttrib_ipc" , &rk_aiq_user_api_adehaze_getSwAttrib_ipc},

    //rk_aiq_user_api_adpcc_ipc
    {"rk_aiq_user_api_adpcc_SetAttrib_ipc"  ,   &rk_aiq_user_api_adpcc_SetAttrib_ipc},
    {"rk_aiq_user_api_adpcc_GetAttrib_ipc" , &rk_aiq_user_api_adpcc_GetAttrib_ipc},
    
   //rk_aiq_user_api_ae_ipc
    {"rk_aiq_user_api_adpcc_SetAttrib_ipc"  ,   &rk_aiq_user_api_adpcc_SetAttrib_ipc},
    {"rk_aiq_user_api_adpcc_GetAttrib_ipc" , &rk_aiq_user_api_adpcc_GetAttrib_ipc},
    {"rk_aiq_user_api_ae_setExpSwAttr_ipc"  ,   &rk_aiq_user_api_ae_setExpSwAttr_ipc},
    {"rk_aiq_user_api_ae_getExpSwAttr_ipc"  ,   &rk_aiq_user_api_ae_getExpSwAttr_ipc},
    {"rk_aiq_user_api_ae_setLinAeRouteAttr_ipc"  ,   &rk_aiq_user_api_ae_setLinAeRouteAttr_ipc  },
    {"rk_aiq_user_api_ae_getLinAeRouteAttr_ipc"  ,   &rk_aiq_user_api_ae_getLinAeRouteAttr_ipc  },
    {"rk_aiq_user_api_ae_setHdrAeRouteAttr_ipc"  ,   &rk_aiq_user_api_ae_setHdrAeRouteAttr_ipc  },
    {"rk_aiq_user_api_ae_getHdrAeRouteAttr_ipc"  ,   &rk_aiq_user_api_ae_getHdrAeRouteAttr_ipc  },
    {"rk_aiq_user_api_ae_queryExpResInfo_ipc"  ,   &rk_aiq_user_api_ae_queryExpResInfo_ipc},
    {"rk_aiq_user_api_ae_setLinExpAttr_ipc"  ,   &rk_aiq_user_api_ae_setLinExpAttr_ipc},
    {"rk_aiq_user_api_ae_getLinExpAttr_ipc"  ,   &rk_aiq_user_api_ae_getLinExpAttr_ipc},
    {"rk_aiq_user_api_ae_setHdrExpAttr_ipc"  ,   &rk_aiq_user_api_ae_setHdrExpAttr_ipc},
    {"rk_aiq_user_api_ae_getHdrExpAttr_ipc"  ,   &rk_aiq_user_api_ae_getHdrExpAttr_ipc},
  //rk_aiq_user_api_agamma_ipc
    {"rk_aiq_user_api_agamma_SetAttrib"  ,   &rk_aiq_user_api_agamma_SetAttrib},
    {"rk_aiq_user_api_agamma_GetAttrib"  ,   &rk_aiq_user_api_agamma_GetAttrib},

    //rk_aiq_user_api_ahdr_ipc
    {"rk_aiq_user_api_ahdr_SetAttrib_ipc"  ,   &rk_aiq_user_api_ahdr_SetAttrib_ipc},
    //rk_aiq_user_api_alsc_ipc
    {"rk_aiq_user_api_alsc_SetAttrib_ipc"  ,   &rk_aiq_user_api_alsc_SetAttrib_ipc},
    {"rk_aiq_user_api_alsc_GetAttrib_ipc"  ,   &rk_aiq_user_api_alsc_GetAttrib_ipc},
    {"rk_aiq_user_api_alsc_QueryLscInfo_ipc"  ,   &rk_aiq_user_api_alsc_QueryLscInfo_ipc},
    //rk_aiq_user_api_anr_ipc
    {"rk_aiq_user_api_anr_SetAttrib_ipc"  ,   &rk_aiq_user_api_anr_SetAttrib_ipc},
    {"rk_aiq_user_api_anr_GetAttrib_ipc"  ,   &rk_aiq_user_api_anr_GetAttrib_ipc},

    //rk_aiq_user_api_asharp_ipc
    {"rk_aiq_user_api_asharp_SetAttrib_ipc"  ,   &rk_aiq_user_api_asharp_SetAttrib_ipc},
    {"rk_aiq_user_api_asharp_GetAttrib_ipc"  ,   &rk_aiq_user_api_asharp_GetAttrib_ipc},
    //rk_aiq_user_api_awb_ipc
    {"rk_aiq_user_api_awb_SetAttrib_ipc"  ,   &rk_aiq_user_api_awb_SetAttrib_ipc},
    {"rk_aiq_user_api_awb_GetAttrib_ipc"  ,   &rk_aiq_user_api_awb_GetAttrib_ipc},
    {"rk_aiq_user_api_awb_GetCCT_ipc"  ,   &rk_aiq_user_api_awb_GetCCT_ipc},
    {"rk_aiq_user_api_awb_QueryWBInfo_ipc"  ,   &rk_aiq_user_api_awb_QueryWBInfo_ipc},
#endif
    //rk_aiq_user_api_sysctl_ipc
    {"rk_aiq_uapi_sysctl_init_ipc"   ,&rk_aiq_uapi_sysctl_init_ipc},
    {"rk_aiq_uapi_sysctl_deinit_ipc"   ,&rk_aiq_uapi_sysctl_deinit_ipc},
    {"rk_aiq_uapi_sysctl_prepare_ipc"   ,&rk_aiq_uapi_sysctl_prepare_ipc},
    {"rk_aiq_uapi_sysctl_start_ipc"   ,&rk_aiq_uapi_sysctl_start_ipc},
    {"rk_aiq_uapi_sysctl_stop_ipc"   ,&rk_aiq_uapi_sysctl_stop_ipc},
    {"rk_aiq_uapi_sysctl_getStaticMetas_ipc "   ,&rk_aiq_uapi_sysctl_getStaticMetas_ipc},
    {"rk_aiq_uapi_sysctl_getMetaData_ipc"   ,&rk_aiq_uapi_sysctl_getMetaData_ipc},
    {"rk_aiq_uapi_sysctl_setModuleCtl_ipc"   ,&rk_aiq_uapi_sysctl_setModuleCtl_ipc},
    {"rk_aiq_uapi_sysctl_getModuleCtl_ipc"   ,&rk_aiq_uapi_sysctl_getModuleCtl_ipc},
    {"rk_aiq_uapi_sysctl_regLib_ipc"   ,&rk_aiq_uapi_sysctl_regLib_ipc},
    {"rk_aiq_uapi_sysctl_unRegLib_ipc"   ,&rk_aiq_uapi_sysctl_unRegLib_ipc},
    {"rk_aiq_uapi_sysctl_enableAxlib_ipc"   ,&rk_aiq_uapi_sysctl_enableAxlib_ipc},
    {"rk_aiq_uapi_sysctl_getAxlibStatus_ipc"   ,&rk_aiq_uapi_sysctl_getAxlibStatus_ipc},
    {"rk_aiq_uapi_sysctl_getEnabledAxlibCtx_ipc",&rk_aiq_uapi_sysctl_getEnabledAxlibCtx_ipc},

};

#endif