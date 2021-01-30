#include "interface_twatch.h"

char buf[128];

void draw_time()
{
    // Fazer função
    RTC_Date rtc_time = watch->rtc->getDateTime();
    time_helper.year = rtc_time.year;
    time_helper.month = rtc_time.month;
    time_helper.day = rtc_time.day;
    time_helper.hour = rtc_time.hour;
    time_helper.minute = rtc_time.minute;
    time_helper.second = rtc_time.second;

    // Print Hour
    watch->tft->setTextColor(TFT_YELLOW, TFT_BLACK);
    watch->tft->setFreeFont(&Comfortaa_SemiBold50pt7b);
    snprintf(buf, sizeof(buf), "%02u", time_helper.hour);
    watch->tft->drawString(buf, 0, 0);

    // Print Minute
    watch->tft->setTextColor(TFT_YELLOW, TFT_BLACK);
    watch->tft->setFreeFont(&Comfortaa_SemiBold50pt7b);
    snprintf(buf, sizeof(buf), "%02u", time_helper.minute);
    watch->tft->drawString(buf, 0, 90);

    // Print Weekday and Day
    watch->tft->setTextColor(TFT_CYAN, TFT_BLACK);
    watch->tft->setFreeFont(&Comfortaa_SemiBold15pt7b);
    snprintf(buf, sizeof(buf), "SAT, %02u", /*time_helper.day,*/ time_helper.day);
    watch->tft->drawString(buf, 0, 185);

    // Print Month and Year
    watch->tft->setTextColor(TFT_CYAN, TFT_BLACK);
    snprintf(buf, sizeof(buf), "%02u/%u", time_helper.month, time_helper.year);
    watch->tft->setFreeFont(&Comfortaa_SemiBold15pt7b);
    watch->tft->drawString(buf, 0, 215);

    watch->tft->drawFastVLine(120, 0, 240, TFT_BLUE);
}