/*************************************************************************
	> File Name: s3c2440a_gpio.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月22日 星期日 15时20分45秒
 ************************************************************************/

#ifndef     __S3C2440A_GPIO_H
#define     __S3C2440A_GPIO_H

#define	    GPF4_OUT                        ((uint16_t)(0x1 << 4*2))
#define	    GPF5_OUT                        ((uint16_t)(0x1 << 5*2))
#define	    GPF6_OUT                        ((uint16_t)(0x1 << 6*2))
#define	    GPF4_IN                         ~GPF4_OUT
#define	    GPF5_IN                         ~GPF5_OUT
#define	    GPF6_IN                         ~GPF6_OUT

#endif      //__S3C2440A_GPIO_H

