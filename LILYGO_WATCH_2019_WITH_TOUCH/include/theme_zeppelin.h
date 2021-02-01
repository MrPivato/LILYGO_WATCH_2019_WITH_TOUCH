#pragma once

#include "twatch_configs.h"
#include "twatch_rtc.h"
#include "twatch_step_counter.h"

/* Fonts *********************************************/
#include "fonts_custom/Comfortaa_SemiBold15pt7b.h"
// #include "fonts_custom/Comfortaa_SemiBold17pt7b.h"
// #include "fonts_custom/Comfortaa_SemiBold19pt7b.h"
// #include "fonts_custom/Comfortaa_SemiBold20pt7b.h"
// #include "fonts_custom/Comfortaa_SemiBold24pt7b.h"
#include "fonts_custom/Comfortaa_SemiBold50pt7b.h"
// #include "fonts_custom/Comfortaa_SemiBold52pt7b.h"
// #include "fonts_custom/Comfortaa_SemiBold54pt7b.h"
/*****************************************************/
/* Icons *********************************************/
#include "icons_custom/icon_alarm.h"
#include "icons_custom/icon_battery.h"
#include "icons_custom/icon_cloud_sun.h"
#include "icons_custom/icon_steps.h"
#include "icons_custom/icon_temperature_mid.h"
/*****************************************************/

extern char buf[128];

void theme_zeppelin_homescreen();