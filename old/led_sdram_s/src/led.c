/*************************************************************************
	> File Name: led.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月09日 星期一 23时27分59秒
 ************************************************************************/
#include "led.h"

void led_init(void)
{
	GPIOF->conf |= GPF4_OUT | GPF5_OUT | GPF6_OUT;

    //close all leds
    GPIOF->dat |= LED1 | LED2 | LED4;

    //open all leds
    //GPIOF->dat &= ~(LED1 | LED2 | LED4);
}

