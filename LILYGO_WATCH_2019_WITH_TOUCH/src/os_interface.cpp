#include "os_interface.h"

char buf[128];

void draw_homescreen()
{    
    if ((unsigned long)(current_hms_update_millis - previous_hms_update_millis) >= HOMESCREEN_UPDATE_INTERVAL)
    {
        update_time_helper_struct();
        theme_zeppelin_draw_homescreen();

        previous_hms_update_millis = current_hms_update_millis;
    }
}