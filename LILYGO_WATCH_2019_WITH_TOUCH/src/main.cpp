#include <Arduino.h>

#include "configs_twatch.h"
#include "aux_functions.h"

#include "deep_sleep_twatch.h"
#include "rtc_twatch.h"
#include "step_counter_twatch.h"
#include "interface_twatch.h"

void setup()
{
  setup_twatch();

  // just for setting the time while theres not a menu
  //watch->rtc->setDateTime(2020, 1, 25, 20, 20, 0);

  deep_sleep_twatch();

  update_time_counter();
}

void loop()
{

  if ((unsigned long)(current_hms_update_millis - previous_hms_update_millis) >= HOMESCREEN_UPDATE_INTERVAL)
  {
    draw_homescreen();
    previous_hms_update_millis = current_hms_update_millis;
  }

  update_time_counter();
}
