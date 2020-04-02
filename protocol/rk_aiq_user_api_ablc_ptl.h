#ifndef _RK_AIQ_USER_API_ABLC_PTL_H_
#define _RK_AIQ_USER_API_ABLC_PTL_H_

#include "ablc/rk_aiq_uapi_ablc_int.h"

typedef struct
rk_aiq_user_api_ablc_SetAttrib{unsigned int sys_ctx; rk_aiq_blc_attrib_t attr;} rk_aiq_user_api_ablc_SetAttrib_t;
typedef struct
rk_aiq_user_api_ablc_GetAttrib{unsigned int sys_ctx; rk_aiq_blc_attrib_t attr;} rk_aiq_user_api_ablc_GetAttrib_t;

#endif

