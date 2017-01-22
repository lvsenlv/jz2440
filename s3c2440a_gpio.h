/*************************************************************************
	> File Name: s3c2440a_gpio.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月22日 星期日 15时20分45秒
 ************************************************************************/

#ifndef 	_S3C2440A_GPIO_H
#define 	_S3C2440A_GPIO_H

typedef enum {
			GPF0_OUT = 1 << 0,
			GPF1_OUT = 1 << 1*2,
			GPF2_OUT = 1 << 2*2,
			GPF3_OUT = 1 << 3*2,
			GPF4_OUT = 1 << 4*2,
			GPF5_OUT = 1 << 5*2,
			GPF6_OUT = 1 << 6*2,
			GPF7_OUT = 1 << 7*2,
}gpio_mode_e;

#endif 		//_S3C2440A_GPIO_H

