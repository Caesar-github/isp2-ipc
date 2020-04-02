/*
 *  Copyright (c) 2019 Rockchip Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License";};
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

#ifndef _RK_AIQ_UAPI_IMGPROC_PTL_H_
#define _RK_AIQ_UAPI_IMGPROC_PTL_H_
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
    DAYNIGHT_SCENE_NIGHT = 1,
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
typedef struct rk_aiq_uapi_setExpMode {
    unsigned int ctx;
    opMode_t mode;
} rk_aiq_uapi_setExpMode_t;

typedef struct rk_aiq_uapi_getExpMode {
    unsigned int ctx;
    opMode_t mode;
} rk_aiq_uapi_getExpMode_t;

/*
*****************************
*
* Desc: set auto exposure mode
* Argument:
*   mode:
*
*****************************
*/

typedef struct rk_aiq_uapi_setAeMode {
    unsigned int ctx;
    aeMode_t mode;
} rk_aiq_uapi_setAeMode_t;

typedef struct rk_aiq_uapi_getAeMode {
    unsigned int ctx;
    aeMode_t  mode;
} rk_aiq_uapi_getAeMode_t;

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
typedef struct rk_aiq_uapi_setExpGainRange {
    unsigned int ctx;
    paRange_t  gain;
} rk_aiq_uapi_setExpGainRange_t;

typedef struct rk_aiq_uapi_getExpGainRange {
    unsigned int ctx;
    paRange_t  gain
} rk_aiq_uapi_getExpGainRange_t;
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
typedef struct rk_aiq_uapi_setExpTimeRange {
    unsigned int ctx;
    paRange_t  time;
} rk_aiq_uapi_setExpTimeRange_t;

typedef struct rk_aiq_uapi_getExpTimeRange {
    unsigned int ctx;
    paRange_t  time;
} rk_aiq_uapi_getExpTimeRange_t;

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
typedef struct rk_aiq_uapi_setBLCMode {
    unsigned int ctx;
    bool on;
    paRect_t rect;
} rk_aiq_uapi_setBLCMode_t;

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
typedef struct rk_aiq_uapi_setHLCMode {
    unsigned int ctx;
    bool on;
    paRect_t rect;
} rk_aiq_uapi_setHLCMode_t;
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
typedef struct rk_aiq_uapi_setLExpMode {
    unsigned int ctx;
    opMode_t mode;
} rk_aiq_uapi_setLExpMode_t;

typedef struct rk_aiq_uapi_getLExpMode {
    unsigned int ctx;
    opMode_t mode;

} rk_aiq_uapi_getLExpMode_t;

/*
*****************************
*
* Desc: set manual lowlight exposure time ratio
* Argument:
*    ratio:  [1.0, 128.0]
*
*****************************
*/
typedef struct rk_aiq_uapi_setMLExp {
    unsigned int ctx;
    unsigned int ratio;
} rk_aiq_uapi_setMLExp_t;

typedef struct rk_aiq_uapi_getMLExp {

    unsigned int ctx;
    unsigned int ratio;
} rk_aiq_uapi_getMLExp;

/*
*****************************
*
* Desc: set power line frequence
* Argument:
*    freq
*
*****************************
*/
typedef struct rk_aiq_uapi_setExpPwrLineFreqMode {
    unsigned int ctx;
    expPwrLineFreq_t freq;
} rk_aiq_uapi_setExpPwrLineFreqMode_t;

typedef struct rk_aiq_uapi_getExpPwrLineFreqMode {
    unsigned int ctx;
    expPwrLineFreq_t freq;
} rk_aiq_uapi_getExpPwrLineFreqMode_t;


/*
*****************************
*
* Desc: set day night switch mode
* Argument:
*    mode
*
*****************************
*/
typedef struct rk_aiq_uapi_setDayNSwMode {

    unsigned int ctx;
    opMode_t mode;

} rk_aiq_uapi_setDayNSwMode;

typedef struct rk_aiq_uapi_getDayNSwMode {
    unsigned int ctx;
    opMode_t mode;
} rk_aiq_uapi_getDayNSwMode_t;

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
typedef struct rk_aiq_uapi_setMDNScene {
    unsigned int ctx;
    dayNightScene_t scene;
} rk_aiq_uapi_setMDNScene_t;

typedef struct rk_aiq_uapi_getMDNScene {
    unsigned int ctx;
    dayNightScene_t scene;
} rk_aiq_uapi_getMDNScene_t;


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
typedef struct rk_aiq_uapi_setADNSens {
    unsigned int ctx;
    unsigned    int level;
} rk_aiq_uapi_setADNSens_t;

typedef struct rk_aiq_uapi_getADNSens {
    unsigned int ctx;
    unsigned int level;
} rk_aiq_uapi_getADNSens_t;


/*
*****************************
*
* Desc: set fill light mode
* Argument:
*    mode
*
*****************************
*/
typedef struct rk_aiq_uapi_setFLightMode {
    unsigned int ctx;
    opMode_t mode
} rk_aiq_uapi_setFLightMode_t;

typedef struct rk_aiq_uapi_getFLightMode {
    unsigned int ctx;
    opMode_t  mode;
} rk_aiq_uapi_getFLightMode_t;


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
typedef struct rk_aiq_uapi_setMFLight {
    unsigned int ctx;
    bool on;
} rk_aiq_uapi_setMFLight_t;

typedef struct rk_aiq_uapi_getMFLight {
    unsigned int ctx;
    bool  on;
} rk_aiq_uapi_getMFLight_t;



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
typedef struct rk_aiq_uapi_setWBMode {
    unsigned int ctx;
    opMode_t mode;
} rk_aiq_uapi_setWBMode_t;

typedef struct rk_aiq_uapi_getWBMode {
    unsigned int ctx;
    opMode_t  mode;
} rk_aiq_uapi_getWBMode_t;


/*
*****************************
*
* Desc: lock/unlock auto white balance
* Argument:
*
*
*****************************
*/
typedef struct rk_aiq_uapi_lockAWB {
    unsigned int ctx;
    void abort;
} rk_aiq_uapi_lockAWB_t;

typedef struct rk_aiq_uapi_unlockAWB {
    unsigned int ctx;
    void abort;
} rk_aiq_uapi_unlockAWB_t;


/*
*****************************
*
* Desc: set auto white balance mode
* Argument:
*
*
*****************************
*/
typedef struct rk_aiq_uapi_setAWBRange {
    unsigned int ctx;
    awbRange_t range;
} rk_aiq_uapi_setAWBRange_t;

typedef struct rk_aiq_uapi_getAWBRange {

    unsigned int ctx;
    awbRange_t  range;

} rk_aiq_uapi_getAWBRange_t;


/*
*****************************
*
* Desc: set manual white balance scene mode
* Argument:
*   ct_scene:
*
*****************************
*/
typedef struct rk_aiq_uapi_setMWBScene {
    unsigned int ctx;
    wbCTScene_t ct_scene;
} rk_aiq_uapi_setMWBScene_t;

typedef struct rk_aiq_uapi_getMWBScene {
    unsigned int ctx;
    wbCTScene_t  ct_scene;
} rk_aiq_uapi_getMWBScene_t;


/*
*****************************
*
* Desc: set manual white balance r/b gain
* Argument:
*   ct_scene:
*
*****************************
*/
typedef struct rk_aiq_uapi_setMWBGain {
    unsigned int ctx;
    wbGain_t  gain
} rk_aiq_uapi_setMWBGain_t;

typedef struct rk_aiq_uapi_getMWBGain {
    unsigned int ctx;
    wbGain_t  gain;
} rk_aiq_uapi_getMWBGain_t;

/*
*****************************
*
* Desc: set manual white balance color temperature
* Argument:
*   ct: color temperature value [2800, 7500]K
*
*****************************
*/
typedef struct rk_aiq_uapi_setMWBCT {
    unsigned int ctx;
    int ct
} rk_aiq_uapi_setMWBCT_t;

typedef struct rk_aiq_uapi_getMWBCT {
    unsigned int ctx;
    int  ct;
} rk_aiq_uapi_getMWBCT_t;


/*
*****************************
*
* Desc: set color supperssion level
* Argument:
*   level: [0, 100]
*
*****************************
*/
typedef struct rk_aiq_uapi_setCrSuppsn {
    unsigned int ctx;
    unsigned int level;
} rk_aiq_uapi_setCrSuppsn_t;

typedef struct rk_aiq_uapi_getCrSuppsn {
    unsigned int ctx;
    unsigned int  level;
} rk_aiq_uapi_getCrSuppsn_t;

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
typedef struct rk_aiq_uapi_setFocusMode {
    unsigned int ctx;
    opMode_t mode;
} rk_aiq_uapi_setFocusMode_t;

typedef struct rk_aiq_uapi_getFocusMode {
    unsigned int ctx;
    opMode_t  mode;
} rk_aiq_uapi_getFocusMode_t;


/*
*****************************
*
* Desc: set minimum focus distance
* Argument:
*   disrance:  unint is cm
*****************************
*/
typedef struct rk_aiq_uapi_setMinFocusDis {
    unsigned int ctx;
    unsigned int distance;
} rk_aiq_uapi_setMinFocusDis_t;

typedef struct rk_aiq_uapi_getMinFocusDis {
    unsigned int ctx;
    unsigned int distance;
} rk_aiq_uapi_getMinFocusDis_t;


/*
*****************************
*
* Desc: set optical zoom range
* Argument:
*   range:  [1.0, 100.0]
*
*****************************
*/
typedef struct rk_aiq_uapi_setOpZoomRange {
    unsigned int ctx;
    paRange_t  range;
} rk_aiq_uapi_setOpZoomRange_t ;

typedef struct rk_aiq_uapi_getOpZoomRange {
    unsigned int ctx;
    paRange_t  range;
} rk_aiq_uapi_getOpZoomRange_t;

/*
*****************************
*
* Desc: set optical zoom speed
* Argument:
*   level:  [1, 10]
*
*****************************
*/
typedef struct rk_aiq_uapi_setOpZoomSpeed {
    unsigned int ctx;
    unsigned int level;
} rk_aiq_uapi_setOpZoomSpeed_t;

typedef struct rk_aiq_uapi_getOpZoomSpeed { unsigned int ctx; unsigned int  level;} rk_aiq_uapi_getOpZoomSpeed_t;

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
typedef struct rk_aiq_uapi_setHDRMode { unsigned int ctx; opMode_t mode;} rk_aiq_uapi_setHDRMode_t;
typedef struct rk_aiq_uapi_getHDRMode { unsigned int ctx; opMode_t  mode;} rk_aiq_uapi_getHDRMode_t;

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
typedef struct rk_aiq_uapi_setMHDRStrth { unsigned int ctx; bool on, unsigned int level;} rk_aiq_uapi_setMHDRStrth_t;
typedef struct rk_aiq_uapi_getMHDRStrth { unsigned int ctx; bool *on, unsigned int  level;} rk_aiq_uapi_getMHDRStrth_t;

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
typedef struct rk_aiq_uapi_setNRMode { unsigned int ctx; opMode_t mode;} rk_aiq_uapi_setNRMode_t;
typedef struct rk_aiq_uapi_getNRMode { unsigned int ctx; opMode_t  mode;} rk_aiq_uapi_getNRMode_t;

/*
*****************************
*
* Desc: set auto noise reduction strength
* Argument:
*   level: [0, 10]
*
*****************************
*/
typedef struct rk_aiq_uapi_setANRStrth { unsigned int ctx; unsigned int level;} rk_aiq_uapi_setANRStrth_t;
typedef struct rk_aiq_uapi_getANRStrth { unsigned int ctx; unsigned int  level;} rk_aiq_uapi_getANRStrth_t;

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
typedef struct rk_aiq_uapi_setMSpaNRStrth { unsigned int ctx; bool on, unsigned int level;} rk_aiq_uapi_setMSpaNRStrth_t;
typedef struct rk_aiq_uapi_getMSpaNRStrth { unsigned int ctx; bool *on, unsigned int  level;} rk_aiq_uapi_getMSpaNRStrth_t;

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
typedef struct rk_aiq_uapi_setMTNRStrth { unsigned int ctx; bool on, unsigned int level;} rk_aiq_uapi_setMTNRStrth_t;
typedef struct rk_aiq_uapi_getMTNRStrth { unsigned int ctx; bool *on, unsigned int  level;} rk_aiq_uapi_getMTNRStrth_t;

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
typedef struct rk_aiq_uapi_setDhzMode { unsigned int ctx; opMode_t mode;} rk_aiq_uapi_setDhzMode_t;
typedef struct rk_aiq_uapi_getDhzMode { unsigned int ctx; opMode_t  mode;} rk_aiq_uapi_getDhzMode_t;

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
typedef struct rk_aiq_uapi_setMDhzStrth { unsigned int ctx; bool on, unsigned int level;} rk_aiq_uapi_setMDhzStrth_t;
typedef struct rk_aiq_uapi_getMDhzStrth { unsigned int ctx; bool on, unsigned int  level;} rk_aiq_uapi_getMDhzStrth_t;
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
typedef struct rk_aiq_uapi_setContrast { unsigned int ctx; unsigned int level;} rk_aiq_uapi_setContrast_t;
typedef struct rk_aiq_uapi_getContrast { unsigned int ctx; unsigned int  level;} rk_aiq_uapi_getContrast_t;

/*
*****************************
*
* Desc: Adjust image brightness level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
typedef struct rk_aiq_uapi_setBrightness { unsigned int ctx; unsigned int level;} rk_aiq_uapi_setBrightness_t;
typedef struct rk_aiq_uapi_getBrightness { unsigned int ctx; unsigned int  level;} rk_aiq_uapi_getBrightness_t;
/*
*****************************
*
* Desc: Adjust image saturation level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
typedef struct rk_aiq_uapi_setSaturation { unsigned int ctx; float level;} rk_aiq_uapi_setSaturation_t;
typedef struct rk_aiq_uapi_getSaturation { unsigned int ctx; float level;} rk_aiq_uapi_getSaturation_t;
/*
*****************************
*
* Desc: Adjust image sharpness level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
typedef struct rk_aiq_uapi_setSharpness { unsigned int ctx; unsigned int level;} rk_aiq_uapi_setSharpness_t;
typedef struct rk_aiq_uapi_getSharpness { unsigned int ctx; unsigned int  level;} rk_aiq_uapi_getSharpness_t;

RKAIQ_END_DECLARE

#endif
