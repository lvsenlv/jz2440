/*************************************************************************
	> File Name: system_init.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月02日 星期二 19时33分44秒
 ************************************************************************/

#ifndef __SYSTEM_INIT_H
#define __SYSTEM_INIT_H

#include "bsp_sdram.h"
#include "bsp_nand.h"
#include "bsp_led.h"

#define SYS_CLOCK_FREQUENCE                 12 //unit: MHZ

#define CODE_SIZE                           ((uint32_t)1024*4) //4kib
#define CODE_START_ADDR                     ((uint32_t)4096) //4Kib
/*************************************************************************
                     instruction about CODE_START_ADDR
Except start_up.s and system_init.c, all codes' load address depends on 
the value in "AT(xxxx)", which could be consulted in file named "lds". 
Assume the value is 4096, and use the tools of openjtag to download the 
code. Openjtag wolud copy codes from 4096. It means copy codes from the 
page 2. If use the function of sys_nand_read to copy codes, the operation 
of "4096 >> 12" is invalid. "4096 >> 12" means the start address is page 1.
Therefore, "4096 >> 11" is means page 2. 
At least but not last, while using the tools of openjtag, it needs to input
the target block number. But it takes no effect whatever you input. The 
real load address rely on the value in "AT(xxxx)"
 ************************************************************************/



#endif

