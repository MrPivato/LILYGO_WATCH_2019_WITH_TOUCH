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
    power = watch->power;
    

    // ADC monitoring must be enabled to use the AXP202 monitoring function
    power->adc1Enable(AXP202_VBUS_VOL_ADC1 | AXP202_VBUS_CUR_ADC1 | AXP202_BATT_CUR_ADC1 | AXP202_BATT_VOL_ADC1, true);

    setup_step_counter();
}