#ifndef _RK_AIQ_USER_API_AGAMMA_IPC_H_
#define _RK_AIQ_USER_API_AGAMMA_IPC_H_

#include "rk_aiq_user_api_agamma.h"

XCamReturn
rk_aiq_user_api_agamma_SetAttrib_ipc(rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_gamma_attrib_t attr);
XCamReturn
rk_aiq_user_api_agamma_GetAttrib_ipc(rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_gamma_attrib_t *attr);

#endif
