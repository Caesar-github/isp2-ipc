#ifndef __RK_AIQ_USER_API_AE_PTL_H__
#define __RK_AIQ_USER_API_AE_PTL_H__

//#include "ae/rk_aiq_uapi_ae_int.h"
#include "rk_aiq_user_api_ae.h"
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct rk_aiq_user_api_ae_setExpSwAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
    Uapi_ExpSwAttr_t attr;
    XCamReturn returnvalue;
} rk_aiq_user_api_ae_setExpSwAttr_t;

typedef struct rk_aiq_user_api_ae_getExpSwAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
    Uapi_ExpSwAttr_t attr;
    XCamReturn returnvalue;
} rk_aiq_user_api_ae_getExpSwAttr_t;

typedef struct rk_aiq_user_api_ae_setLinAeRouteAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
     Uapi_LinAeRouteAttr_t attr;
     XCamReturn returnvalue;
} rk_aiq_user_api_ae_setLinAeRouteAttr_t;

typedef struct rk_aiq_user_api_ae_getLinAeRouteAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
    Uapi_LinAeRouteAttr_t attr;
    XCamReturn returnvalue;
} rk_aiq_user_api_ae_getLinAeRouteAttr_t;

typedef struct rk_aiq_user_api_ae_setHdrAeRouteAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
     Uapi_HdrAeRouteAttr_t attr;
     XCamReturn returnvalue;
} rk_aiq_user_api_ae_setHdrAeRouteAttr_t;

typedef struct rk_aiq_user_api_ae_getHdrAeRouteAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
    Uapi_HdrAeRouteAttr_t attr;
    XCamReturn returnvalue;
} rk_aiq_user_api_ae_getHdrAeRouteAttr_t;

typedef struct rk_aiq_user_api_ae_queryExpResInfo {
    rk_aiq_sys_ctx_t*   sys_ctx;
    Uapi_ExpQueryInfo_t attr;
    XCamReturn returnvalue;
} rk_aiq_user_api_ae_queryExpResInfo_t;

typedef struct rk_aiq_user_api_ae_setLinExpAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
     Uapi_LinExpAttr_t attr;
     XCamReturn returnvalue;
} rk_aiq_user_api_ae_setLinExpAttr_t;

typedef struct rk_aiq_user_api_ae_getLinExpAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
    Uapi_LinExpAttr_t attr;
    XCamReturn returnvalue;
} rk_aiq_user_api_ae_getLinExpAttr_t;

typedef struct rk_aiq_user_api_ae_setHdrExpAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
     Uapi_HdrExpAttr_t attr;
     XCamReturn returnvalue;
} rk_aiq_user_api_ae_setHdrExpAttr_t;

typedef struct rk_aiq_user_api_ae_getHdrExpAttr {
    rk_aiq_sys_ctx_t*   sys_ctx;
    Uapi_HdrExpAttr_t attr;
    XCamReturn returnvalue;
} rk_aiq_user_api_ae_getHdrExpAttr_t;

#ifdef __cplusplus
}
#endif
#endif /__RK_AIQ_USER_API_AE_H__/
