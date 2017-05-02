/*************************************************************************
	> File Name: s3c2440a.h
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时30分58秒
 ************************************************************************/

#ifndef _S3C2440A_H
#define _S3C2440A_H

#include <stdint.h>

#define __IO                                volatile

#define GPIO_BASE                           ((uint32_t)0x56000000)
#define GPIOF_BASE                          (GPIO_BASE + 0x50)

#define GPIOF                               ((GPIO_REG_PT)GPIOF_BASE)

typedef struct {
    __IO uint32_t CON;
    __IO uint32_t DAT;
    __IO uint32_t UP;
}GPIO_REG_T, *GPIO_REG_PT;

#endif

