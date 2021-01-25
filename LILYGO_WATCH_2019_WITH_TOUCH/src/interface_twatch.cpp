#include "interface_twatch.h"

char buf[128];

void draw_time()
{
    // Print DATE
    watch->tft->setTextColor(TFT_GREEN, TFT_BLACK);
    watch->tft->setTextSize(2);
    snprintf(buf, sizeof(buf), "%s", watch->rtc->formatDateTime(4));
    watch->tft->drawString(buf, 15, 100, 1);

    // Print TIME
    watch->tft->setTextColor(TFT_ORANGE, TFT_BLACK);
    watch->tft->setTextSize(1);
    snprintf(buf, sizeof(buf), "%s", watch->rtc->formatDateTime());
    watch->tft->drawString(buf, 11, 118, 7);
}