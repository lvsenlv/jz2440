/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时24分28秒
 ************************************************************************/

#include "bsp_led.h"
#include "bsp_nand.h"

void delay(uint32_t count);

int main(void)
{
    led_init();

    while(1)
    {
        LED1_ON;
        delay(0xFFFF);
        LED1_OFF;
        LED2_ON;
        delay(0xFFFF);
        LED2_OFF;
        LED4_ON;
        delay(0xFFFF);
        LED4_OFF;
    }
    
    return 0;
}

void delay(uint32_t count)
{
    for(;count > 0; count--);
}

