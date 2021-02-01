#pragma once

#include <LilyGoWatch.h>

#include "twatch_step_counter.h"

extern TTGOClass *watch;
extern TFT_eSPI *tft;
extern AXP20X_Class *power;
extern BMA *sensor;

extern bool irq_sleep;
extern bool irq_step;

void setup_twatch();