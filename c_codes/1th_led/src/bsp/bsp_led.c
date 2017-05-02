/*************************************************************************
	> File Name: bsp_led.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时25分06秒
 ************************************************************************/

#include "bsp_led.h"

void led_init(void)
{
    GPIO_REG_PT reg = GPIOF;
    reg->CON |= ((0x1 << nLED1_GPIO_PIN*2) |
                    (0x1 << nLED2_GPIO_PIN*2) |
                    (0x1 << nLED4_GPIO_PIN*2));

    reg->DAT |= ((0x1 << nLED1_GPIO_PIN) |
                    (0x1 << nLED2_GPIO_PIN) |
                    (0x1 << nLED4_GPIO_PIN));
}

