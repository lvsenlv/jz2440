/*************************************************************************
	> File Name: include/bsp_led.h
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时25分20秒
 ************************************************************************/

#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "s3c2440a.h"

#define nLED1_GPIO_PIN                      4
#define nLED2_GPIO_PIN                      5
#define nLED4_GPIO_PIN                      6

#define nLED1_ON                            {GPIOF->DAT &= ~(0x1 << nLED1_GPIO_PIN);}
#define nLED1_OFF                           {GPIOF->DAT |=  (0x1 << nLED1_GPIO_PIN);}

#define nLED2_ON                            {GPIOF->DAT &= ~(0x1 << nLED2_GPIO_PIN);}
#define nLED2_OFF                           {GPIOF->DAT |=  (0x1 << nLED2_GPIO_PIN);}

#define nLED4_ON                            {GPIOF->DAT &= ~(0x1 << nLED4_GPIO_PIN);}
#define nLED4_OFF                           {GPIOF->DAT |=  (0x1 << nLED4_GPIO_PIN);}

void led_init(void);

#endif

