#pragma once

#include "configs_twatch.h"

//const uint32_t MS_PER_HOUR = 3600000;
//const uint16_t MS_PER_MIN = 60000;
extern const uint16_t MS_PER_SEC;

extern const uint32_t HOMESCREEN_UPDATE_INTERVAL;
extern unsigned long previous_hms_update_millis;
extern unsigned long current_hms_update_millis;

void update_time_counter();