#include "deep_sleep_twatch.h"

void deep_sleep_twatch()
{
    pinMode(AXP202_INT, INPUT_PULLUP);
    attachInterrupt(
        AXP202_INT, [] {
            irq_sleep = true;
        },
        FALLING);

    // Must be enabled first, and then clear the interrupt status,
    // otherwise abnormal
    power->enableIRQ(AXP202_PEK_SHORTPRESS_IRQ,
                     true);

    //  Clear interrupt status
    power->clearIRQ();

    //tft->println("Press Peek Key to sleep...");

    // Wait for the power button to be pressed
    while (!irq_sleep)
    {
        loop();
    }
    /*
    After the AXP202 interrupt is triggered, the interrupt status must be cleared,
    * otherwise the next interrupt will not be triggered
    */
    power->clearIRQ();

    // for (int i = 5; i > 0; i--)
    // {
    //     tft->print("Go to sleep after ");
    //     tft->print(i);
    //     tft->println(" seconds");
    //     delay(1000);
    // }

    //tft->println("Sleep now ...");
    delay(500);

    // Set screen and touch to sleep mode
    watch->displaySleep();

    /*
    When using T - Watch2020V1, you can directly call power->powerOff(),
    if you use the 2019 version of TWatch, choose to turn off
    according to the power you need to turn off
    */
#ifdef LILYGO_WATCH_2020_V1
    watch->powerOff();
    // LDO2 is used to power the display, and LDO2 can be turned off if needed
    // power->setPowerOutPut(AXP202_LDO2, false);
#else
    power->setPowerOutPut(AXP202_LDO3, false);
    power->setPowerOutPut(AXP202_LDO4, false);
    power->setPowerOutPut(AXP202_LDO2, false);
    // The following power channels are not used
    power->setPowerOutPut(AXP202_EXTEN, false);
    power->setPowerOutPut(AXP202_DCDC2, false);
#endif

    // Use ext0 for external wakeup
    // esp_sleep_enable_ext0_wakeup((gpio_num_t)AXP202_INT, LOW);

    // Use ext1 for external wakeup
    esp_sleep_enable_ext1_wakeup(GPIO_SEL_35, ESP_EXT1_WAKEUP_ALL_LOW);

    esp_deep_sleep_start();
}