/*************************************************************************
	> File Name: include/bsp_led.h
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时25分20秒
 ************************************************************************/

#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "s3c2440a.h"

#define LED1_GPIO_PIN                       4
#define LED2_GPIO_PIN                       5
#define LED4_GPIO_PIN                       6

#define LED1_ON                             {GPIOF->DAT &= ~(0x1 << LED1_GPIO_PIN);}
#define LED1_OFF                            {GPIOF->DAT |=  (0x1 << LED1_GPIO_PIN);}

#define LED2_ON                             {GPIOF->DAT &= ~(0x1 << LED2_GPIO_PIN);}
#define LED2_OFF                            {GPIOF->DAT |=  (0x1 << LED2_GPIO_PIN);}

#define LED4_ON                             {GPIOF->DAT &= ~(0x1 << LED4_GPIO_PIN);}
#define LED4_OFF                            {GPIOF->DAT |=  (0x1 << LED4_GPIO_PIN);}

void led_init(void);

#endif

