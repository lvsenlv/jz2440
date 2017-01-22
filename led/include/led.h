/*************************************************************************
	> File Name: led.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月21日 星期六 22时42分15秒
 ************************************************************************/

#ifndef 	_LED_H
#define 	_LED_H

#include 	"s3c2440a.h"
#include 	"s3c2440a_gpio.h"

#define 	LED1_ON 					( GPIOF->dat &= (~(1 << 4)) )
#define 	LED1_OFF 					( GPIOF->dat |= (1 << 4) )

#define 	LED2_ON 					( GPIOF->dat &= (~(1 << 5)) )
#define 	LED2_OFF 					( GPIOF->dat |= (1 << 5) )

#define 	LED4_ON 					( GPIOF->dat &= (~(1 << 6)) )
#define 	LED4_OFF 					( GPIOF->dat |= (1 << 6) )

void 		led_init(void);

#endif 		//_LED_H

