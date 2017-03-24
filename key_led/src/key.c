/*************************************************************************
	> File Name: key.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月22日 星期三 16时00分53秒
 ************************************************************************/

#include "key.h"

void key_init(void)
{
    GPIOF->conf &= GPF0_IN & GPF2_IN;
    GPIOG->conf &= GPG3_IN;
}

