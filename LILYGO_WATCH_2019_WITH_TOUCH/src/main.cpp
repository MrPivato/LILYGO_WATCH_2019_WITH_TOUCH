#include <Arduino.h>

#include "configs_twatch.h"
#include "deep_sleep_twatch.h"
#include "rtc_twatch.h"
#include "interface_twatch.h"

void setup()
{
  setup_twatch();
  
  // just for setting the time while theres not a menu
  //watch->rtc->setDateTime(2020, 1, 25, 20, 20, 0);

  deep_sleep_twatch();
}

void loop()
{
  draw_time();

  delay(1000);
}
