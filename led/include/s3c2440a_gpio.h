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
			GPF2_OUT = 1 << 2*2,
			GPF4_OUT = 1 << 4*2,
			GPF5_OUT = 1 << 5*2,
			GPF6_OUT = 1 << 6*2,
			GPF0_IN = ~GPF0_OUT,
			GPF2_IN = ~GPF2_OUT,
			GPF4_IN = ~GPF4_OUT,
			GPF5_IN = ~GPF5_OUT,
			GPF6_IN = ~GPF6_OUT,

			GPG3_OUT = 1 << 3*2,
			GPG3_IN = ~GPG3_OUT,
}gpio_mode_e;

#endif 		//_S3C2440A_GPIO_H

