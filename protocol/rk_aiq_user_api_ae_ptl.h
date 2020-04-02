#ifndef __RK_AIQ_USER_API_AE_H__
#define __RK_AIQ_USER_API_AE_H__

#include "ae/rk_aiq_uapi_ae_int.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct rk_aiq_user_api_ae_setExpSwAttr{unsigned int ctx; const Uapi_ExpSwAttr_t pExpSwAttr;} rk_aiq_user_api_ae_setExpSwAttr_t;
typedef struct rk_aiq_user_api_ae_getExpSwAttr{unsigned int ctx; Uapi_ExpSwAttr_t pExpSwAttr;} rk_aiq_user_api_ae_getExpSwAttr_t;
typedef struct rk_aiq_user_api_ae_setLinAeRouteAttr{unsigned int ctx; const Uapi_LinAeRouteAttr_t pLinAeRouteAttr;}rk_aiq_user_api_ae_setLinAeRouteAttr_t;
typedef struct rk_aiq_user_api_ae_getLinAeRouteAttr{unsigned int ctx; Uapi_LinAeRouteAttr_t pLinAeRouteAttr;}rk_aiq_user_api_ae_getLinAeRouteAttr_t;
typedef struct rk_aiq_user_api_ae_setHdrAeRouteAttr{unsigned int ctx; const Uapi_HdrAeRouteAttr_t pHdrAeRouteAttr;} rk_aiq_user_api_ae_setHdrAeRouteAttr_t;
typedef struct rk_aiq_user_api_ae_getHdrAeRouteAttr{unsigned int ctx; Uapi_HdrAeRouteAttr_t pHdrAeRouteAttr;}rk_aiq_user_api_ae_getHdrAeRouteAttr_t;
typedef struct rk_aiq_user_api_ae_queryExpResInfo{unsigned int ctx; Uapi_ExpQueryInfo_t pExpResInfo;}rk_aiq_user_api_ae_queryExpResInfo_t;

typedef struct rk_aiq_user_api_ae_setLinExpAttr{unsigned int ctx; const Uapi_LinExpAttr_t pLinExpAttr;} rk_aiq_user_api_ae_setLinExpAttr_t;
typedef struct rk_aiq_user_api_ae_getLinExpAttr{unsigned int ctx; Uapi_LinExpAttr_t pLinExpAttr;} rk_aiq_user_api_ae_getLinExpAttr_t;
typedef struct rk_aiq_user_api_ae_setHdrExpAttr{unsigned int ctx; const Uapi_HdrExpAttr_t pHdrExpAttr;} rk_aiq_user_api_ae_setHdrExpAttr_t;
typedef struct rk_aiq_user_api_ae_getHdrExpAttr{unsigned int ctx; Uapi_HdrExpAttr_t pHdrExpAttr;} rk_aiq_user_api_ae_getHdrExpAttr_t;


#ifdef __cplusplus
}
#endif





#endif /__RK_AIQ_USER_API_AE_H__/
