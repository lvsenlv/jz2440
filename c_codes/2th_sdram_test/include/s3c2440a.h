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

#define SYS_CLOCK_FREQUENCE                 12 //unit: MHZ

#define GPIO_BASE                           ((uint32_t)0x56000000)
#define GPIOF_BASE                          (GPIO_BASE + 0x50)
#define MEM_CTL_BASE                        ((uint32_t)0x48000000)

#define GPIOF                               ((GPIO_REG_PT)GPIOF_BASE)
#define MEM_CTRL                            ((MEM_CTRL_PT)MEM_CTL_BASE)
#define MEM_CTRL_BANK6                      6 //sdram is connetted to bank6

typedef enum {
    STAT_OK = 0,
    STAT_ERR = !STAT_OK,
}G_STATUS;

typedef struct {
    __IO uint32_t CON;
    __IO uint32_t DAT;
    __IO uint32_t UP;
}GPIO_REG_T, *GPIO_REG_PT;

typedef struct {
    __IO uint32_t BWSCON;
    __IO uint32_t BANKCON0;
    __IO uint32_t BANKCON1;
    __IO uint32_t BANKCON2;
    __IO uint32_t BANKCON3;
    __IO uint32_t BANKCON4;
    __IO uint32_t BANKCON5;
    __IO uint32_t BANKCON6;
    __IO uint32_t BANKCON7;
    __IO uint32_t REFRESH;
    __IO uint32_t BANKSIZE;
    __IO uint32_t MRSRB6;
    __IO uint32_t MRSRB7;
}MEM_CTRL_T, *MEM_CTRL_PT;

#endif

