#include "rtc_twatch.h"

bool rtcIrq = false;

struct TIME_HELPER time_helper;

void update_time_helper_struct()
{
    RTC_Date rtc_time = watch->rtc->getDateTime();
    
    time_helper.year = rtc_time.year;
    time_helper.month = rtc_time.month;
    time_helper.day = rtc_time.day;
    time_helper.hour = rtc_time.hour;
    time_helper.minute = rtc_time.minute;
    time_helper.second = rtc_time.second;

    uint32_t weekday_code = watch->rtc->getDayOfWeek(time_helper.day, time_helper.month, time_helper.year);

    switch (weekday_code)
    {
    case 0:
        strcpy(time_helper.weekday, "SUN");
        break;
    case 1:
        strcpy(time_helper.weekday, "MON");
        break;
    case 2:
        strcpy(time_helper.weekday, "TUE");
        break;
    case 3:
        strcpy(time_helper.weekday, "WED");
        break;
    case 4:
        strcpy(time_helper.weekday, "THU");
        break;
    case 5:
        strcpy(time_helper.weekday, "FRI");
        break;
    case 6:
        strcpy(time_helper.weekday, "SAT");
        break;
    default:
        strcpy(time_helper.weekday, "ERR");
        break;
    }
}