#ifndef _RK_AIQ_USER_API_AWB_PTL_H_
#define _RK_AIQ_USER_API_AWB_PTL_H_

#include "awb/rk_aiq_uapi_awb_int.h"

typedef struct
rk_aiq_user_api_awb_SetAttrib{unsigned int sys_ctx, rk_aiq_wb_attrib_t attr;} rk_aiq_user_api_awb_SetAttrib_t;
typedef struct
rk_aiq_user_api_awb_GetAttrib{unsigned int sys_ctx, rk_aiq_wb_attrib_t attr;} rk_aiq_user_api_awb_GetAttrib_t;
typedef struct
rk_aiq_user_api_awb_GetCCT{unsigned int sys_ctx, rk_aiq_wb_cct_t cct;} rk_aiq_user_api_awb_GetCCT_t;
typedef struct
rk_aiq_user_api_awb_QueryWBInfo{unsigned int sys_ctx, rk_aiq_wb_querry_info_t wb_querry_info;} rk_aiq_user_api_awb_QueryWBInfo_t;

#endif
