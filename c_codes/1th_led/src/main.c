/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时24分28秒
 ************************************************************************/

#include "bsp_led.h"

void delay(uint32_t count);

int main(void)
{
    led_init();

    while(1)
    {
        nLED1_ON;
        delay(0xFFFF);
        nLED1_OFF;
        
        nLED2_ON;
        delay(0xFFFF);
        nLED2_OFF;

        nLED4_ON;
        delay(0xFFFF);
        nLED4_OFF;
    }

    return 0;
}

void delay(uint32_t count)
{
    for(;count > 0; count--);
}

