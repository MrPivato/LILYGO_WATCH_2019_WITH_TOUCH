#include "interface_twatch.h"

char buf[128];

void draw_homescreen()
{
    update_time_helper_struct();

    theme_zeppelin_homescreen();
}