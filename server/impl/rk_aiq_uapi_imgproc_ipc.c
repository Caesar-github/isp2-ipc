/*
 *  Copyright (c) 2019 Rockchip Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License"){return 0;}
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
XCamReturn rk_aiq_uapi_setExpMode(void *args){
    return 0;
return 0;}

XCamReturn rk_aiq_uapi_getExpMode(void *args){
   return 0;
return 0;}

/*
*****************************
*
* Desc: set auto exposure mode
* Argument:
*   mode:
*
*****************************
*/
XCamReturn rk_aiq_uapi_setAeMode(void *args){

return 0;}
XCamReturn rk_aiq_uapi_getAeMode(void *args){

    
return 0;}

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
XCamReturn rk_aiq_uapi_setExpGainRange(void *args){return 0;}
XCamReturn rk_aiq_uapi_getExpGainRange(void *args){return 0;}
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
XCamReturn rk_aiq_uapi_setExpTimeRange(void *args){return 0;}
XCamReturn rk_aiq_uapi_getExpTimeRange(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setBLCMode(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setHLCMode(void *args){return 0;}
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
XCamReturn rk_aiq_uapi_setLExpMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getLExpMode(void *args){return 0;}

/*
*****************************
*
* Desc: set manual lowlight exposure time ratio
* Argument:
*    ratio:  [1.0, 128.0]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMLExp(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMLExp(void *args){return 0;}

/*
*****************************
*
* Desc: set power line frequence
* Argument:
*    freq
*
*****************************
*/
XCamReturn rk_aiq_uapi_setExpPwrLineFreqMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getExpPwrLineFreqMode(void *args){return 0;}


/*
*****************************
*
* Desc: set day night switch mode
* Argument:
*    mode
*
*****************************
*/
XCamReturn rk_aiq_uapi_setDayNSwMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getDayNSwMode(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setMDNScene(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMDNScene(void *args){return 0;}


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
XCamReturn rk_aiq_uapi_setADNSens(void *args){return 0;}
XCamReturn rk_aiq_uapi_getADNSens(void *args){return 0;}


/*
*****************************
*
* Desc: set fill light mode
* Argument:
*    mode
*
*****************************
*/
XCamReturn rk_aiq_uapi_setFLightMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getFLightMode(void *args){return 0;}


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
XCamReturn rk_aiq_uapi_setMFLight(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMFLight(void *args){return 0;}



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
XCamReturn rk_aiq_uapi_setWBMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getWBMode(void *args){return 0;}


/*
*****************************
*
* Desc: lock/unlock auto white balance
* Argument:
*
*
*****************************
*/
XCamReturn rk_aiq_uapi_lockAWB(void *args){return 0;}
XCamReturn rk_aiq_uapi_unlockAWB(void *args){return 0;}


/*
*****************************
*
* Desc: set auto white balance mode
* Argument:
*
*
*****************************
*/
XCamReturn rk_aiq_uapi_setAWBRange(void *args){return 0;}
XCamReturn rk_aiq_uapi_getAWBRange(void *args){return 0;}


/*
*****************************
*
* Desc: set manual white balance scene mode
* Argument:
*   ct_scene:
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMWBScene(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMWBScene(void *args){return 0;}


/*
*****************************
*
* Desc: set manual white balance r/b gain
* Argument:
*   ct_scene:
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMWBGain(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMWBGain(void *args){return 0;}

/*
*****************************
*
* Desc: set manual white balance color temperature
* Argument:
*   ct: color temperature value [2800, 7500]K
*
*****************************
*/
XCamReturn rk_aiq_uapi_setMWBCT(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMWBCT(void *args){return 0;}


/*
*****************************
*
* Desc: set color supperssion level
* Argument:
*   level: [0, 100]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setCrSuppsn(void *args){return 0;}
XCamReturn rk_aiq_uapi_getCrSuppsn(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setFocusMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getFocusMode(void *args){return 0;}


/*
*****************************
*
* Desc: set minimum focus distance
* Argument:
*   disrance:  unint is cm
*****************************
*/
XCamReturn rk_aiq_uapi_setMinFocusDis(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMinFocusDis(void *args){return 0;}


/*
*****************************
*
* Desc: set optical zoom range
* Argument:
*   range:  [1.0, 100.0]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setOpZoomRange(void *args){return 0;}
XCamReturn rk_aiq_uapi_getOpZoomRange(void *args){return 0;}

/*
*****************************
*
* Desc: set optical zoom speed
* Argument:
*   level:  [1, 10]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setOpZoomSpeed(void *args){return 0;}
XCamReturn rk_aiq_uapi_getOpZoomSpeed(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setHDRMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getHDRMode(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setMHDRStrth(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMHDRStrth(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setNRMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getNRMode(void *args){return 0;}

/*
*****************************
*
* Desc: set auto noise reduction strength
* Argument:
*   level: [0, 10]
*
*****************************
*/
XCamReturn rk_aiq_uapi_setANRStrth(void *args){return 0;}
XCamReturn rk_aiq_uapi_getANRStrth(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setMSpaNRStrth(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMSpaNRStrth(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setMTNRStrth(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMTNRStrth(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setDhzMode(void *args){return 0;}
XCamReturn rk_aiq_uapi_getDhzMode(void *args){return 0;}

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
XCamReturn rk_aiq_uapi_setMDhzStrth(void *args){return 0;}
XCamReturn rk_aiq_uapi_getMDhzStrth(void *args){return 0;}
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
XCamReturn rk_aiq_uapi_setContrast(void *args){return 0;}
XCamReturn rk_aiq_uapi_getContrast(void *args){return 0;}

/*
*****************************
*
* Desc: Adjust image brightness level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
XCamReturn rk_aiq_uapi_setBrightness(void *args){return 0;}
XCamReturn rk_aiq_uapi_getBrightness(void *args){return 0;}
/*
*****************************
*
* Desc: Adjust image saturation level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
XCamReturn rk_aiq_uapi_setSaturation(void *args){return 0;}
XCamReturn rk_aiq_uapi_getSaturation(void *args){return 0;}
/*
*****************************
*
* Desc: Adjust image sharpness level
* Argument:
*    level: contrast level, [0, 100]
*****************************
*/
XCamReturn rk_aiq_uapi_setSharpness(void *args){return 0;}
XCamReturn rk_aiq_uapi_getSharpness(void *args){return 0;}


