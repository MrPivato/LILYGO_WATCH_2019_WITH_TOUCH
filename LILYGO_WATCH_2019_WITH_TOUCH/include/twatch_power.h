#pragma once

#include "twatch_configs.h"
#include "aux_functions.h"

void setup_power_ic();
void handle_wakeup_and_sleep();
void handle_inactivity();

extern const uint32_t INACTIVITY_INTERVAL;
extern unsigned long previous_inactivity_millis;
extern unsigned long current_inactivity_millis;

extern bool is_inactive;
