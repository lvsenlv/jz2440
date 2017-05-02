/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时24分28秒
 ************************************************************************/

#include "bsp_led.h"
#include "bsp_sdram.h"

int main(void)
{
    led_init();
    sdram_init();

    nLED1_ON;

    if(sdram_bulk_test() == STAT_OK) 
    {
        nLED1_OFF;
        nLED2_ON;
    }
    else
    {
        nLED1_OFF;
        nLED4_ON;
    }

    return 0;
}

