/*************************************************************************
	> File Name: key.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月30日 星期一 16时20分01秒
 ************************************************************************/

#include "key.h"
#include "led.h"

int main(void)
{
	led_init();
	key_init();
	while(1)
	{
		(GPIOF->dat & (1 << 0)) ? LED4_OFF : LED4_ON;
		(GPIOF->dat & (1 << 2)) ? LED2_OFF : LED2_ON;
		(GPIOG->dat & (1 << 3)) ? LED1_OFF : LED1_ON;
			
	}

	return 0;
}

void key_init(void)
{
	gpio_regis_t *regis = GPIOF;
	regis->conf &= GPF0_IN;
	regis->conf &= GPF2_IN;
	
	regis = GPIOG;
	regis->conf &= GPG3_IN;
}

