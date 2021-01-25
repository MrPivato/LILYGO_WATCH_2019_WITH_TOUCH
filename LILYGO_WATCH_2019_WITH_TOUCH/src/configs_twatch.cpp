#include "configs_twatch.h"

TTGOClass *watch;
TFT_eSPI *tft;
AXP20X_Class *power;
bool irq = false;

void setup_twatch()
{
    // Get TTGOClass instance
    watch = TTGOClass::getWatch();

    // Initialize the hardware, the BMA423 sensor has been initialized internally
    watch->begin();

    // Turn on the backlight
    watch->openBL();

    //Receive objects for easy writing
    tft = watch->tft;
    power = watch->power;

    tft->setTextColor(TFT_GREEN);
}