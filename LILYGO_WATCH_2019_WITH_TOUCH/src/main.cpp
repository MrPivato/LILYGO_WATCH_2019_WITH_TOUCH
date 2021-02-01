#include <Arduino.h>

#include "twatch_configs.h"
#include "aux_functions.h"

#include "twatch_deep_sleep.h"
#include "twatch_rtc.h"
#include "twatch_step_counter.h"
#include "os_interface.h"

void setup()
{
  setup_twatch();

  // just for setting the time while theres not a menu
  //watch->rtc->setDateTime(2020, 1, 25, 20, 20, 0);

  twatch_deep_sleep();

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
