/*
 *  Copyright (c) 2019 Rockchip Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef _RK_AIQ_UAPI_IMGPROC_H_
#define _RK_AIQ_UAPI_IMGPROC_H_
#include "base/xcam_common.h"
#include "rk_aiq_user_api_awb.h"
#include "rk_aiq_uapi_aec.h"
#include "rk_aiq_uapi_af.h"
#include "rk_aiq_uapi_anr.h"
#include "rk_aiq_uapi_ahdr.h"
#include "rk_aiq_uapi_adhz.h"
#include "rk_aiq_user_api_alsc.h"
#include "rk_aiq_user_api_accm.h"
#include "rk_aiq_user_api_a3dlut.h"
#include "rk_aiq_user_api_agamma.h"

/*
*****************************
* Common
*****************************
*/

typedef enum dayNightScene_e {
    DAYNIGHT_SCENE_DAY = 0,
    DAYNIGHT_SCENE_NIGHT= 1,
    DAYNIGHT_SCENE_INVAL
} dayNightScene_t;

RKAIQ_BEGIN_DECLARE

/*
**********************************************************
* Exposure
**********************************************************
*/

/*
*****************************
*
* Desc: set exposure control mode
* Argument:
*   mode:  auto: auto exposure
*          manual: manual exposure
*****************************
*/
XCamReturn rk_aiq_uapi_setExpMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
    
     return 0;
}

XCamReturn rk_aiq_uapi_getExpMode(const rk_aiq_sys_ctx_t* ctx, opMode_t *mode) {
    
    return 0;
}

/*
*****************************
*
* Desc: set auto exposure mode
* Argument:
*   mode:
*
*****************************
*/
XCamReturn rk_aiq_uapi_setAeMode(const rk_aiq_sys_ctx_t* ctx, aeMode_t mode) {
     
     return 0;
}

XCamReturn rk_aiq_uapi_getAeMode(const rk_aiq_sys_ctx_t* ctx, aeMode_t *mode) {
 
     return 0;
}

/*
*****************************
*
* Desc: set exposure parameter
* Argument:
*    auto exposure mode:
*      exposure gain will be adjust between [gain->min, gain->max]；
*    manual exposure mode:
*      gain->min == gain->max
*
*****************************
*/
XCamReturn rk_aiq_uapi_setExpGainRange(const rk_aiq_sys_ctx_t* ctx, paRange_t *gain) {
   
   return 0;
}

XCamReturn rk_aiq_uapi_getExpGainRange(const rk_aiq_sys_ctx_t* ctx, paRange_t *gain) {

    return 0;
}
/*
*****************************
*
* Desc: set exposure parameter
* Argument:
*    auto exposure mode:
*       exposure time will be adjust between [time->min, time->max]；
*    manual exposure mode:
*       exposure time will be set gain->min == gain->max;
*
*****************************
*/
XCamReturn rk_aiq_uapi_setExpTimeRange(const rk_aiq_sys_ctx_t* ctx, paRange_t *time) {

    return 0;
}

XCamReturn rk_aiq_uapi_getExpTimeRange(const rk_aiq_sys_ctx_t* ctx, paRange_t *time) {
  
   return 0;
}

/*
**********************************************************
* Auto exposure advanced features
**********************************************************
*/
/*
*****************************
*
* Desc: blacklight compensation
* Argument:
*      on:  1  on
*           0  off
*      rect: blacklight compensation area
*
*****************************
*/
XCamReturn rk_aiq_uapi_setBLCMode(const rk_aiq_sys_ctx_t* ctx, bool on, paRect_t *rect) {
    
    return 0;
}

/*
*****************************
*
* Desc: highlight compensation
* Argument:
*      on:  1  on
*           0  off
*      rect: blacklight compensation area
*
*****************************
*/
XCamReturn rk_aiq_uapi_setHLCMode(const rk_aiq_sys_ctx_t* ctx, bool on, paRect_t *rect) {
    return 0;
}
/*
*****************************
*
* Desc: set lowlight exposure mode
* Argument:
*    mode:
*       auto: auto lowlight mode
*       manual: manual lowlight mode
*
*****************************
*/
XCamReturn rk_aiq_uapi_setLExpMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
    return 0;   
}
XCamReturn rk_aiq_uapi_getLExpMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
    return 0;
}

/*
*****************************
*
* Desc: set manual lowlight exposure time ratio
* Argument:
*    ratio:  [1.0, 128.0]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMLExp(const rk_aiq_sys_ctx_t* ctx, unsigned int ratio) {
    return 0;
}
XCamReturn rk_aiq_uapi_getMLExp(const rk_aiq_sys_ctx_t* ctx, unsigned int ratio) {
    return 0;
} 

/*
*****************************
*
* Desc: set power line frequence
* Argument:
*    freq
*
*****************************
*/
XCamReturn rk_aiq_uapi_setExpPwrLineFreqMode(const rk_aiq_sys_ctx_t* ctx, expPwrLineFreq_t freq) {
    return 0;
}
XCamReturn rk_aiq_uapi_getExpPwrLineFreqMode(const rk_aiq_sys_ctx_t* ctx, expPwrLineFreq_t freq) {
    return 0;
}


/*
*****************************
*
* Desc: set day night switch mode
* Argument:
*    mode
*
*****************************
*/
XCamReturn rk_aiq_uapi_setDayNSwMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
    return 0;
}
XCamReturn rk_aiq_uapi_getDayNSwMode(const rk_aiq_sys_ctx_t* ctx, opMode_t *mode) {
    return 0;
}

/*
*****************************
*
* Desc: set manual day night scene
*    this function is active for DayNSw is manual mode
* Argument:
*    scene
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMDNScene(const rk_aiq_sys_ctx_t* ctx, dayNightScene_t scene) {
   return 0;
}
XCamReturn rk_aiq_uapi_getMDNScene(const rk_aiq_sys_ctx_t* ctx, dayNightScene_t *scene) {
   return 0;
}


/*
*****************************
*
* Desc: set auto day night switch sensitivity
*    this function is active for DayNSw is auto mode
* Argument:
*    level: [1, 3]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setADNSens(const rk_aiq_sys_ctx_t* ctx, unsigned    int level) {
    return 0;
}
XCamReturn rk_aiq_uapi_getADNSens(const rk_aiq_sys_ctx_t* ctx, unsigned int *level) {
    return 0;
}


/*
*****************************
*
* Desc: set fill light mode
* Argument:
*    mode
*
*****************************
*/
XCamReturn rk_aiq_uapi_setFLightMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
    return 0;
}
XCamReturn rk_aiq_uapi_getFLightMode(const rk_aiq_sys_ctx_t* ctx, opMode_t *mode) {
   return 0;
}


/*
*****************************
*
* Desc: set maual fill light mode
* Argument:
*    on:  1: on
*         0: off
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMFLight(const rk_aiq_sys_ctx_t* ctx, bool on) {
    return 0;
}
XCamReturn rk_aiq_uapi_getMFLight(const rk_aiq_sys_ctx_t* ctx, bool *on) {
    return 0;
}



/*
**********************************************************
* White balance & Color
**********************************************************
*/

/*
*****************************
*
* Desc: set white balance mode
* Argument:
*   mode:  auto: auto white balance
*          manual: manual white balance
*****************************
*/
XCamReturn rk_aiq_uapi_setWBMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
    return 0;
}
XCamReturn rk_aiq_uapi_getWBMode(const rk_aiq_sys_ctx_t* ctx, opMode_t *mode) {
    return 0;
}


/*
*****************************
*
* Desc: lock/unlock auto white balance
* Argument:
*
*
*****************************
*/
XCamReturn rk_aiq_uapi_lockAWB(const rk_aiq_sys_ctx_t* ctx, void) {
    return 0;
}
XCamReturn rk_aiq_uapi_unlockAWB(const rk_aiq_sys_ctx_t* ctx, void) {
    return 0;
}


/*
*****************************
*
* Desc: set auto white balance mode
* Argument:
*
*
*****************************
*/
XCamReturn rk_aiq_uapi_setAWBRange(const rk_aiq_sys_ctx_t* ctx, awbRange_t range) {
   return 0;
}
XCamReturn rk_aiq_uapi_getAWBRange(const rk_aiq_sys_ctx_t* ctx, awbRange_t *range) {
   return 0;
}


/*
*****************************
*
* Desc: set manual white balance scene mode
* Argument:
*   ct_scene:
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMWBScene(const rk_aiq_sys_ctx_t* ctx, wbCTScene_t ct_scene) {
   return 0;
}
XCamReturn rk_aiq_uapi_getMWBScene(const rk_aiq_sys_ctx_t* ctx, wbCTScene_t *ct_scene) {
   return 0;
}


/*
*****************************
*
* Desc: set manual white balance r/b gain
* Argument:
*   ct_scene:
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMWBGain(const rk_aiq_sys_ctx_t* ctx, wbGain_t *gain) {
   return 0;
}
XCamReturn rk_aiq_uapi_getMWBGain(const rk_aiq_sys_ctx_t* ctx, wbGain_t *gain){
   return 0;
}

/*
*****************************
*
* Desc: set manual white balance color temperature
* Argument:
*   ct: color temperature value [2800, 7500]K
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMWBCT(const rk_aiq_sys_ctx_t* ctx, int ct){
   return 0;
}
XCamReturn rk_aiq_uapi_getMWBCT(const rk_aiq_sys_ctx_t* ctx, int *ct) {
 return 0;
}


/*
*****************************
*
* Desc: set color supperssion level
* Argument:
*   level: [0, 100]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setCrSuppsn(const rk_aiq_sys_ctx_t* ctx, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getCrSuppsn(const rk_aiq_sys_ctx_t* ctx, unsigned int *level) {
 return 0;
}

/*
**********************************************************
* Focus & Zoom
**********************************************************
*/
/*
*****************************
*
* Desc: set focus mode
* Argument:
*   mode:  auto: auto focus
*          manual: manual focus
*          semi-auto: semi-auto focus
*****************************
*/
XCamReturn rk_aiq_uapi_setFocusMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
 return 0;
}
XCamReturn rk_aiq_uapi_getFocusMode(const rk_aiq_sys_ctx_t* ctx, opMode_t *mode) {
 return 0;
}


/*
*****************************
*
* Desc: set minimum focus distance
* Argument:
*   disrance:  unint is cm
*****************************
*/
XCamReturn rk_aiq_uapi_setMinFocusDis(const rk_aiq_sys_ctx_t* ctx, unsigned int distance) {
 return 0;
}
XCamReturn rk_aiq_uapi_getMinFocusDis(const rk_aiq_sys_ctx_t* ctx, unsigned int distance) {
 return 0;
}


/*
*****************************
*
* Desc: set optical zoom range
* Argument:
*   range:  [1.0, 100.0]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setOpZoomRange(const rk_aiq_sys_ctx_t* ctx, paRange_t *range) {
 return 0;
}
XCamReturn rk_aiq_uapi_getOpZoomRange(const rk_aiq_sys_ctx_t* ctx, paRange_t *range){
 return 0;
}

/*
*****************************
*
* Desc: set optical zoom speed
* Argument:
*   level:  [1, 10]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setOpZoomSpeed(const rk_aiq_sys_ctx_t* ctx, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getOpZoomSpeed(const rk_aiq_sys_ctx_t* ctx, unsigned int *level) {
 return 0;
}

/*
**********************************************************
* HDR
**********************************************************
*/
/*
*****************************
*
* Desc: set hdr mode
* Argument:
*   mode:
*     auto: auto hdr mode
*     manual：manual hdr mode
*
*****************************
*/
XCamReturn rk_aiq_uapi_setHDRMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
 return 0;
}
XCamReturn rk_aiq_uapi_getHDRMode(const rk_aiq_sys_ctx_t* ctx, opMode_t *mode) {
 return 0;
}

/*
*****************************
*
* Desc: set manual hdr strength
*    this function is active for HDR is manual mode
* Argument:
*   on:   1: on
*         0: off
*   level: [0, 10]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMHDRStrth(const rk_aiq_sys_ctx_t* ctx, bool on, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getMHDRStrth(const rk_aiq_sys_ctx_t* ctx, bool *on, unsigned int *level) {
 return 0;
}

/*
**********************************************************
* Noise reduction
**********************************************************
*/
/*
*****************************
*
* Desc: set noise reduction mode
* Argument:
*   mode:
*     auto: auto noise reduction
*     manual：manual noise reduction
*
*****************************
*/
XCamReturn rk_aiq_uapi_setNRMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
 return 0;
}
XCamReturn rk_aiq_uapi_getNRMode(const rk_aiq_sys_ctx_t* ctx, opMode_t *mode) {
 return 0;
}


/*
*****************************
*
* Desc: set auto noise reduction strength
* Argument:
*   level: [0, 10]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setANRStrth(const rk_aiq_sys_ctx_t* ctx, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getANRStrth(const rk_aiq_sys_ctx_t* ctx, unsigned int *level) {
 return 0;
}

/*
*****************************
*
* Desc: set manual spatial noise reduction strength
*    this function is active for NR is manual mode
* Argument:
*   on: 1:on
*      0: off
*   level: [0, 10]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMSpaNRStrth(const rk_aiq_sys_ctx_t* ctx, bool on, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getMSpaNRStrth(const rk_aiq_sys_ctx_t* ctx, bool *on, unsigned int *level) {
 return 0;
}

/*
*****************************
*
* Desc: set manual time noise reduction strength
*     this function is active for NR is manual mode
* Argument:
*   level: [0, 10]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMTNRStrth(const rk_aiq_sys_ctx_t* ctx, bool on, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getMTNRStrth(const rk_aiq_sys_ctx_t* ctx, bool *on, unsigned int *level) {
 return 0;
}

/*
**********************************************************
* Dehazer
**********************************************************
*/
/*
*****************************
*
* Desc: set dehaze mode
* Argument:
*   mode:
*     auto: auto dehaze
*     manual：manual dehaze
*
*****************************
*/
XCamReturn rk_aiq_uapi_setDhzMode(const rk_aiq_sys_ctx_t* ctx, opMode_t mode) {
 return 0;
}
XCamReturn rk_aiq_uapi_getDhzMode(const rk_aiq_sys_ctx_t* ctx, opMode_t *mode) {
 return 0;
}

/*
*****************************
*
* Desc: set manual dehaze strength
*     this function is active for dehaze is manual mode
* Argument:
*   level: [0, 10]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMDhzStrth(const rk_aiq_sys_ctx_t* ctx, bool on, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getMDhzStrth(const rk_aiq_sys_ctx_t* ctx, bool *on, unsigned int *level) {
 return 0;
}
/*
**********************************************************
* Image adjust
**********************************************************
*/

/*
*****************************
*
* Desc: Adjust image contrast level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
XCamReturn rk_aiq_uapi_setContrast(const rk_aiq_sys_ctx_t* ctx, unsigned int level){
 return 0;
}
XCamReturn rk_aiq_uapi_getContrast(const rk_aiq_sys_ctx_t* ctx, unsigned int *level) {
 return 0;
}

/*
*****************************
*
* Desc: Adjust image brightness level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
XCamReturn rk_aiq_uapi_setBrightness(const rk_aiq_sys_ctx_t* ctx, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getBrightness(const rk_aiq_sys_ctx_t* ctx, unsigned int *level) {
 return 0;
}
/*
*****************************
*
* Desc: Adjust image saturation level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
XCamReturn rk_aiq_uapi_setSaturation(const rk_aiq_sys_ctx_t* ctx, float level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getSaturation(const rk_aiq_sys_ctx_t* ctx, float* level) {
 return 0;
}
/*
*****************************
*
* Desc: Adjust image sharpness level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
XCamReturn rk_aiq_uapi_setSharpness(const rk_aiq_sys_ctx_t* ctx, unsigned int level) {
 return 0;
}
XCamReturn rk_aiq_uapi_getSharpness(const rk_aiq_sys_ctx_t* ctx, unsigned int *level) {
 return 0;
}


RKAIQ_END_DECLARE

#endif
