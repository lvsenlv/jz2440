/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月09日 星期一 23时27分59秒
 ************************************************************************/
#include <stdint.h>

#define GPFCON (*(volatile uint32_t *)0x56000050)
#define GPFDAT (*(volatile uint32_t *)0x56000054)
#define GPF4   (1 << 4*2)
#define GPF5   (1 << 5*2)
#define GPF6   (1 << 6*2)

int main(void)
{
    GPFCON= GPF4 | GPF5 | GPF6;
    GPFDAT = 0x50;

    return 0;
}
