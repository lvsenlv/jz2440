/*************************************************************************
	> File Name: key.h
	> Author: 
	> Mail: 
	> Created Time: 2017年03月22日 星期三 16时00分43秒
 ************************************************************************/

#ifndef __KEY_H
#define __KEY_H

#include    "s3c2440a.h"
#include    "s3c2440a_gpio.h"

#define     KEY0                            (1 << 0)
#define     KEY2                            (1 << 2)
#define     KEY11                           (1 << 3)

#define     EINT0_STATUS                    (GPIOF->dat & KEY0)
#define     EINT2_STATUS                    (GPIOF->dat & KEY2)
#define     EINT11_STATUS                   (GPIOG->dat & KEY11)

#define     IS_PRESS                        0

void key_init(void);

#endif //__KEY_H
