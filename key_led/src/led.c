/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月09日 星期一 23时27分59秒
 ************************************************************************/
#include "led.h"

void delay(volatile unsigned long count);
int led_main(void);

int led_main(void)
{
	led_init();
	delay(0xFFFF);
	while(1)
	{
		//delay(0xFFFF);
		//LED1_ON;
		LED1_TOGGLE;
		delay(0xFFFF);
		//LED1_OFF;
		LED1_TOGGLE;
		//delay(0xFFFF);	
		//LED2_ON;
		LED2_TOGGLE;
		delay(0xFFFF);
		//LED2_OFF;
		LED2_TOGGLE;
		//delay(0xFFFF);
		//LED4_ON;
		LED4_TOGGLE;
		delay(0xFFFF);
		//LED4_OFF;
		LED4_TOGGLE;
	}
	
	return 0;
}

void delay(volatile unsigned long count)
{
	for(; count > 0; count--);
}

void led_init(void)
{
	gpio_regis_t *regis = GPIOF;
	regis->conf |= GPF4_OUT | GPF5_OUT | GPF6_OUT;
	LED1_OFF;
	LED2_OFF;
	LED4_OFF;
}

