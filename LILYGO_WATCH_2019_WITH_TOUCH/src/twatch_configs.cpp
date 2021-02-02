#include "twatch_configs.h"

TTGOClass *watch;
TFT_eSPI *tft;
AXP20X_Class *power;

bool irq_sleep = false;
bool irq_step = false;

void setup_twatch()
{
    // Get TTGOClass instance
    watch = TTGOClass::getWatch();
    // Initialize the hardware
    watch->begin();
    // Turn on the backlight
    watch->openBL();
    //Receive objects for easy writing
    tft = watch->tft;

    setup_power_ic();
    setup_step_counter();
}