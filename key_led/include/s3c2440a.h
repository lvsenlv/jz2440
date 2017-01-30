/*************************************************************************
	> File Name: gpio_register.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月21日 星期六 22时48分52秒
 ************************************************************************/

#ifndef 	_S3C2440A_H
#define 	_S3C2440A_H

#include 	<stdint.h>

typedef struct {
	volatile uint32_t conf;
	volatile uint32_t dat;
	volatile uint32_t up;
}gpio_regis_t;

#define 	GPIO_BASE_ADDR 			(0x56000000)
#define 	GPIOA_ADDR 				(GPIO_BASE_ADDR + 0x0)
#define 	GPIOB_ADDR 				(GPIO_BASE_ADDR + 0x10)
#define 	GPIOC_ADDR 				(GPIO_BASE_ADDR + 0x20)
#define 	GPIOD_ADDR 				(GPIO_BASE_ADDR + 0x30)
#define 	GPIOE_ADDR 				(GPIO_BASE_ADDR + 0x40)
#define 	GPIOF_ADDR 				(GPIO_BASE_ADDR + 0x50)
#define 	GPIOG_ADDR 				(GPIO_BASE_ADDR + 0x60)
#define 	GPIOH_ADDR 				(GPIO_BASE_ADDR + 0x70)
#define 	GPIOJ_ADDR 				(GPIO_BASE_ADDR + 0xd0)

#define 	GPIOA 					((gpio_regis_t *)GPIOA_ADDR)
#define 	GPIOB 					((gpio_regis_t *)GPIOB_ADDR)
#define 	GPIOC 					((gpio_regis_t *)GPIOC_ADDR)
#define 	GPIOD 					((gpio_regis_t *)GPIOD_ADDR)
#define 	GPIOE 					((gpio_regis_t *)GPIOE_ADDR)
#define 	GPIOF 					((gpio_regis_t *)GPIOF_ADDR)
#define 	GPIOG 					((gpio_regis_t *)GPIOG_ADDR)
#define 	GPIOH 					((gpio_regis_t *)GPIOH_ADDR)
#define 	GPIOJ 					((gpio_regis_t *)GPIOJ_ADDR)

#endif 		//_S3C2440A_H
