/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月22日 星期三 14时49分55秒
 ************************************************************************/

#include "led.h"
#include "key.h"

int main(void)
{
    led_init();
    key_init();

    while(1)
    {
       (EINT0_STATUS) ? nLED_4_OFF : nLED_4_ON;
       (EINT2_STATUS) ? nLED_2_OFF : nLED_2_ON;
       (EINT11_STATUS) ? nLED_1_OFF : nLED_1_ON;
    }
    
    return 0;
}

