#pragma once

#include "configs_twatch.h"

extern bool rtcIrq;

struct TIME_HELPER
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    char weekday[4];
};

extern struct TIME_HELPER time_helper;

void update_time_helper_struct();