#include <Arduino.h>

#include "twatch_configs.h"
#include "aux_functions.h"

#include "twatch_power.h"
#include "twatch_rtc.h"
#include "twatch_step_counter.h"
#include "os_interface.h"

void setup()
{
  setup_twatch();

  // just for setting the time while theres not a menu
  //watch->rtc->setDateTime(2020, 1, 25, 20, 20, 0);

  update_time_counter();
}

void loop()
{
  handle_wakeup_and_sleep();
  handle_inactivity();

  draw_homescreen();

  update_time_counter();
}
