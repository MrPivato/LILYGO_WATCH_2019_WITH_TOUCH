#include "theme_zeppelin.h"

void theme_zeppelin_homescreen()
{
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
    snprintf(buf, sizeof(buf), "%s, %02u", time_helper.weekday, time_helper.day);
    watch->tft->drawString(buf, 0, 185);

    // Print Month and Year
    watch->tft->setTextColor(TFT_CYAN, TFT_BLACK);
    snprintf(buf, sizeof(buf), "%02u/%u", time_helper.month, time_helper.year);
    watch->tft->setFreeFont(&Comfortaa_SemiBold15pt7b);
    watch->tft->drawString(buf, 0, 215);

    // Print Battery
    watch->tft->drawXBitmap(121, 10, icon_battery_bits, icon_battery_width, icon_battery_height, TFT_GREEN, TFT_BLACK);
    watch->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    snprintf(buf, sizeof(buf), "%02u%%", power->getBattPercentage());
    watch->tft->setFreeFont(&Comfortaa_SemiBold15pt7b);
    watch->tft->drawString(buf, 153, 10);

    // Pint Temperature
    watch->tft->drawXBitmap(121, 62, icon_temperature_mid_bits, icon_temperature_mid_width, icon_temperature_mid_height, TFT_ORANGE, TFT_BLACK);
    watch->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    snprintf(buf, sizeof(buf), "%02u \260C", 27);
    watch->tft->setFreeFont(&Comfortaa_SemiBold15pt7b);
    watch->tft->drawString(buf, 153, 62);

    // Print Weather
    watch->tft->drawXBitmap(156, 96, icon_cloud_sun_bits, icon_cloud_sun_width, icon_cloud_sun_height, TFT_WHITE, TFT_BLACK);

    // Print Steps
    watch->tft->drawXBitmap(121, 154, icon_steps_bits, icon_steps_width, icon_steps_height, TFT_DARKGREEN, TFT_BLACK);
    watch->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    snprintf(buf, sizeof(buf), "%05u", sensor->getCounter());
    watch->tft->setFreeFont(&Comfortaa_SemiBold15pt7b);
    watch->tft->drawString(buf, 153, 154);

    // Print Alarm
    watch->tft->drawXBitmap(121, 198, icon_alarm_bits, icon_alarm_width, icon_alarm_height, TFT_RED, TFT_BLACK);
    watch->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    snprintf(buf, sizeof(buf), "%02u:%02u", time_helper.hour, time_helper.minute);
    watch->tft->setFreeFont(&Comfortaa_SemiBold15pt7b);
    watch->tft->drawString(buf, 153, 198);
}