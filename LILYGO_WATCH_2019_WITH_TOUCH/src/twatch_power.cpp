#include "twatch_power.h"

const uint32_t INACTIVITY_INTERVAL = MS_PER_SEC * 10;
unsigned long previous_inactivity_millis;
unsigned long current_inactivity_millis;

bool is_inactive = false;

void setup_power_ic()
{
    power = watch->power;

    // ADC monitoring must be enabled to use the AXP202 monitoring function
    power->adc1Enable(AXP202_VBUS_VOL_ADC1 | AXP202_VBUS_CUR_ADC1 | AXP202_BATT_CUR_ADC1 | AXP202_BATT_VOL_ADC1, true);

    pinMode(AXP202_INT, INPUT_PULLUP);
    attachInterrupt(
        AXP202_INT, [] {
            irq_sleep = true;
        },
        FALLING);

    //!Clear IRQ unprocessed  first
    watch->power->enableIRQ(AXP202_PEK_SHORTPRESS_IRQ, true);
    watch->power->clearIRQ();
}

void handle_wakeup_and_sleep()
{
    if (irq_sleep)
    {
        irq_sleep = false;
        watch->power->readIRQ();
        if (watch->power->isPEKShortPressIRQ() || is_inactive)
        {
            // Clean power chip irq status
            watch->power->clearIRQ();

            // Set  touchscreen sleep
            watch->displaySleep();

            watch->powerOff();

            //Set all channel power off
            watch->power->setPowerOutPut(AXP202_LDO3, false);
            watch->power->setPowerOutPut(AXP202_LDO4, false);
            watch->power->setPowerOutPut(AXP202_LDO2, false);
            watch->power->setPowerOutPut(AXP202_EXTEN, false);
            watch->power->setPowerOutPut(AXP202_DCDC2, false);

            // TOUCH SCREEN  Wakeup source
            esp_sleep_enable_ext1_wakeup(GPIO_SEL_38, ESP_EXT1_WAKEUP_ALL_LOW);

            esp_deep_sleep_start();
        }
        watch->power->clearIRQ();
    }
}

void handle_inactivity()
{
    if (digitalRead(TOUCH_INT) == LOW)
    {
        previous_inactivity_millis = current_inactivity_millis;
        is_inactive = false;
    }
    else if ((unsigned long)(current_inactivity_millis - previous_inactivity_millis) >= INACTIVITY_INTERVAL)
    {
        irq_sleep = true;
        is_inactive = true;
    }
    
    update_time_counter();
}