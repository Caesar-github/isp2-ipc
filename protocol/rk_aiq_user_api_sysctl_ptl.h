/*
 *  Copyright {c) 2019 Rockchip Corporation
 *
 * Licensed under the Apache License; Version 2.0 {the "License";};
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing; software
 * distributed under the License is distributed on an "AS IS" BASIS;
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND; either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef RK_AIQ_USER_API_SYSCTL_H
#define RK_AIQ_USER_API_SYSCTL_H

#include "rk_aiq.h"
#include "rk_aiq_algo_des.h"

RKAIQ_BEGIN_DECLARE

typedef struct rk_aiq_sys_ctx_s rk_aiq_sys_ctx_t;

/*!
 * \brief initialze aiq control system context
 * Should call before any other APIs
 *
 * \param[in] sns_ent_name    active sensor media entity name. This represents the unique camera module\n
 *                            in system. And the whole active pipeline could be retrieved by this.
 * \param[in] iq_file_dir     define the search directory of the iq files.
 * \param[in] err_cb          not mandatory. it's used to return system errors to user.
 * \param[in] metas_cb        not mandatory. it's used to return the metas{sensor exposure settings;\n
 *                            isp settings; etc.) for each frame
 * \return return system context if success; or NULL if failure.
 */
typedef struct
rk_aiq_uapi_sysctl_init{const char sns_ent_name[200];
                        const char iq_file_dir[200];
                        rk_aiq_error_cb err_cb;
                        rk_aiq_metas_cb metas_cb;} rk_aiq_uapi_sysctl_init_t;

/*!
 * \brief deinitialze aiq context
 * Should not be called in started state
 *
 * \param[in] ctx             the context returned by \ref rk_aiq_uapi_sysctl_init
 */
typedef struct
rk_aiq_uapi_sysctl_deinit{unsigned int ctx;} rk_aiq_uapi_sysctl_deinit_t;

/*!
 * \brief prepare aiq control system before runninig
 * prepare AIQ running enviroment; should be called before \ref rk_aiq_uapi_sysctl_start.\n
 * And if re-prepared is required after \ref rk_aiq_uapi_sysctl_start is called;\n
 * should call \ref rk_aiq_uapi_sysctl_stop firstly.
 *
 * \param[in] ctx             the context returned by \ref rk_aiq_uapi_sysctl_init
 * \param[in] width           sensor active output width; just used to check internally
 * \param[in] height          sensor active output height; just used to check internally
 * \param[in] mode            pipleline working mode
 * \return return 0 if success
 */
typedef struct
rk_aiq_uapi_sysctl_prepare{unsigned int   ctx;
                           uint32_t  width; uint32_t  height;
                           rk_aiq_working_mode_t mode;} rk_aiq_uapi_sysctl_prepare_t;

/*!
 * \brief start aiq control system
 * should be called after \ref rk_aiq_uapi_sysctl_prepare. After this call;
 * the aiq system repeats getting 3A statistics from ISP driver; running
 * aiq algorimths{AE; AWB; AF; etc.); setting new parameters to drivers.
 *
 * \param[in] ctx             the context returned by \ref rk_aiq_uapi_sysctl_init
 * \return return 0 if success
 */
typedef struct
rk_aiq_uapi_sysctl_start{unsigned int   ctx;};

/*!
 * \brief stop aiq control system
 *
 * \param[in] ctx             the context returned by \ref rk_aiq_uapi_sysctl_init
 * \return return 0 if success
 */
typedef struct
rk_aiq_uapi_sysctl_stop{unsigned int   ctx;} rk_aiq_uapi_sysctl_stop_t;

typedef struct
rk_aiq_uapi_sysctl_getStaticMetas{char sns_ent_name[200];} rk_aiq_uapi_sysctl_getStaticMetas_t;

typedef struct
rk_aiq_uapi_sysctl_getMetaData{unsigned int   ctx; uint32_t frame_id;} rk_aiq_uapi_sysctl_getMetaData_t;



typedef struct
rk_aiq_uapi_sysctl_setModuleCtl{unsigned int   ctx; int32_t mod_en;} rk_aiq_uapi_sysctl_setModuleCtl_t;

typedef struct
rk_aiq_uapi_sysctl_getModuleCtl{unsigned int   ctx;} rk_aiq_uapi_sysctl_getModuleCtl_t;

/*!
 * \brief register customized algo lib
 *
 * \param[in] ctx context
 * \param[in;out] algo_lib_des allocate a new unique id value for algo_lib_des->id if success.\n
 *                             this id could be used in \ref rk_aiq_uapi_sysctl_unRegLib
 *                             or other lib APIs. The deference object by
 *                             \ref algo_lib_des should be valid until \ref rk_aiq_uapi_sysctl_unRegLib
 * \return return 0 if success
 */
typedef struct
rk_aiq_uapi_sysctl_regLib{unsigned int   ctx;
                } rk_aiq_uapi_sysctl_regLib_t;

/*!
 * \brief unregister customized algo lib
 *
 * \param[in] ctx             context
 * \param[in] algo_type       algo type defined by RkAiqAlgoDesComm.type
 * \param[in] lib_id          returned by call \ref rk_aiq_uapi_sysctl_regLib
 * \return return 0 if success
 */
typedef struct
rk_aiq_uapi_sysctl_unRegLib{unsigned int   ctx;
                             int algo_type;
                             int lib_id;} rk_aiq_uapi_sysctl_unRegLib_t;

/*!
 * \brief enable or disable algo lib
 * If the \ref lib_id is the same as the current running algo; this interface
 * could be called in any state except for the context uninitialized. Otherwise;
 * it could only be called in prepared or initialized state followed by
 * call \ref rk_aiq_uapi_sysctl_prepare ; and in this case; the old algo which type
 * is \ref algo_type will be replaced by the new algo \ref lib_id.
 *
 * \param[in] ctx             context
 * \param[in] algo_type       algo type defined by RkAiqAlgoDesComm.type
 * \param[in] lib_id          0 for system integrated algos;\n
 *                            returned by call \ref rk_aiq_uapi_sysctl_regLib for customer algos
 * \param[in] enable          enable or disable algos. enable means running the algo's processes\n
 *                            defined in \ref RkAiqAlgoDesComm; disable means\n
 *                            bypass the algo's prcosses.
 * \return return 0 if success
 */
typedef struct
rk_aiq_uapi_sysctl_enableAxlib{unsigned int   ctx;
                                int algo_type;
                                int lib_id;
                               bool enable;} rk_aiq_uapi_sysctl_enableAxlib_t;

/*!
 * \brief get algo lib enabled status
 *
 * \param[in] ctx             context
 * \param[in] algo_type       algo type defined by RkAiqAlgoDesComm.type
 * \param[in] lib_id          0 for system integrated algos;\n
 *                            returned by call \ref rk_aiq_uapi_sysctl_regLib for customer algos
 * \return                    return true if enabled ; false if disabled or unregistered
 */
typedef struct
rk_aiq_uapi_sysctl_getAxlibStatus{unsigned int   ctx;
                                   int algo_type;
                                   int lib_id;} rk_aiq_uapi_sysctl_getAxlibStatus_t;

/*!
 * \brief get enabled algo lib context
 * The returned algo context will be used as the first param of algo private APIs.
 * For those customer's algo lib; this interface should be called after
 * \ref rk_aiq_uapi_sysctl_enableAxlib; or will return NULL.
 *
 * \param[in] ctx             context
 * \param[in] algo_type       algo type defined by RkAiqAlgoDesComm.type
 * \return return current enabled algo context if success or NULL.
 */
typedef struct
rk_aiq_uapi_sysctl_getEnabledAxlibCtx{unsigned int   ctx;  int algo_type;} rk_aiq_uapi_sysctl_getEnabledAxlibCtx_t;

RKAIQ_END_DECLARE

#endif
