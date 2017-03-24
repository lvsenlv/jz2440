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

#define	    GPF0_IN                         (~(uint16_t)(0x3 << 0))
#define	    GPF2_IN                         (~(uint16_t)(0x3 << 2*2))
#define	    GPG3_IN                         (~(uint16_t)(0x3 << 3*2))

#endif      //__S3C2440A_GPIO_H

