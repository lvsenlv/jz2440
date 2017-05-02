/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月22日 星期三 14时49分55秒
 ************************************************************************/

#include "led.h"

void delay(uint32_t count);

int main(void)
{
    led_init();

    while(1)
    {
        nLED_1_ON;
        delay(0xFFFF);
        nLED_1_OFF;
        nLED_2_ON;
        delay(0xFFFF);
        nLED_2_OFF;
        nLED_4_ON;
        delay(0xFFFF);
        nLED_4_OFF;
    }
    
    return 0;
}

void delay(uint32_t count)
{
    for(;count > 0; count--);
}
