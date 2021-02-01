#pragma once

#include <LilyGoWatch.h>

#include "step_counter_twatch.h"

extern TTGOClass *watch;
extern TFT_eSPI *tft;
extern AXP20X_Class *power;
extern BMA *sensor;

extern bool irq_sleep;
extern bool irq_step;

void setup_twatch();