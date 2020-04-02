#ifndef _RK_AIQ_USER_API_ADPCC_H_
#define _RK_AIQ_USER_API_ADPCC_H_

#include "adpcc/rk_aiq_uapi_adpcc_int.h"

typedef struct rk_aiq_user_api_adpcc_SetAttrib{
	 unsigned int sys_ctx; 
	 rk_aiq_dpcc_attrib_t attr;
}rk_aiq_user_api_adpcc_SetAttrib_t;
	 
typedef struct rk_aiq_user_api_adpcc_GetAttrib{
	unsigned int   sys_ctx;
    rk_aiq_dpcc_attrib_t attr;
}rk_aiq_user_api_adpcc_GetAttrib_t;

#endif

