/*************************************************************************
	> File Name: led.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月21日 星期六 22时42分15秒
 ************************************************************************/

#ifndef     __LED_H
#define     __LED_H

#include    "s3c2440a.h"
#include    "s3c2440a_gpio.h"

#define     LED1                            (1 << 4)
#define     LED2                            (1 << 5)
#define     LED4                            (1 << 6)

#define     nLED_1_ON                       ( GPIOF->dat &= ~LED1)
#define     nLED_1_OFF                      ( GPIOF->dat |= LED1 )
#define     nLED_1_TOGGLE                   ( GPIOF->dat ^= LED1 )

#define     nLED_2_ON                       ( GPIOF->dat &= ~LED2 )
#define     nLED_2_OFF                      ( GPIOF->dat |= LED2 )
#define     nLED_2_TOGGLE                   ( GPIOF->dat ^= LED2 )

#define     nLED_4_ON                       ( GPIOF->dat &= ~LED4 )
#define     nLED_4_OFF                      ( GPIOF->dat |= LED4 )
#define     nLED_4_TOGGLE                   ( GPIOF->dat ^= LED4 )

void        led_init(void);

#endif      //__LED_H

