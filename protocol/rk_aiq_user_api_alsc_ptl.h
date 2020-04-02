#ifndef _RK_AIQ_USER_API_ALSC_H_
#define _RK_AIQ_USER_API_ALSC_H_

#include "alsc/rk_aiq_uapi_alsc_int.h"

typedef struct
rk_aiq_user_api_alsc_SetAttrib{unsigned int sys_ctx, rk_aiq_lsc_attrib_t attr;} rk_aiq_user_api_alsc_SetAttrib_t;
typedef struct
rk_aiq_user_api_alsc_GetAttrib{unsigned int sys_ctx, rk_aiq_lsc_attrib_t attr;} rk_aiq_user_api_alsc_GetAttrib_t;
typedef struct
rk_aiq_user_api_alsc_QueryLscInfo{unsigned int sys_ctx, rk_aiq_lsc_querry_info_t lsc_querry_info;} rk_aiq_user_api_alsc_QueryLscInfo_t;

#endif
