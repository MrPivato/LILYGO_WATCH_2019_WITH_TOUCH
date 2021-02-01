#include "aux_functions.h"

//const uint32_t MS_PER_HOUR = 3600000;
//const uint16_t MS_PER_MIN = 60000;
const uint16_t MS_PER_SEC = 1000;

const uint32_t HOMESCREEN_UPDATE_INTERVAL = MS_PER_SEC;
unsigned long previous_hms_update_millis;
unsigned long current_hms_update_millis;

void update_time_counter()
{
  current_hms_update_millis = millis();
}