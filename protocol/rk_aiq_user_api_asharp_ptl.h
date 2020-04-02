#ifndef _RK_AIQ_USER_API_ASHARP_PTL_H_
#define _RK_AIQ_USER_API_ASHARP_PTL_H_

#include "asharp/rk_aiq_uapi_asharp_int.h"

typedef struct rk_aiq_user_api_asharp_SetAttrib {
    unsigned int sys_ctx;
    rk_aiq_sharp_attrib_t *attr;
} rk_aiq_user_api_asharp_SetAttrib_t;

typedef struct rk_aiq_user_api_asharp_GetAttrib {
    unsigned int sys_ctx;
    rk_aiq_sharp_attrib_t *attr;
} rk_aiq_user_api_asharp_GetAttrib_t;

#endif

