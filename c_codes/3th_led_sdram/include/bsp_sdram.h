/*************************************************************************
	> File Name: bsp_sdram.h
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 16时21分28秒
 ************************************************************************/

#ifndef __BSP_SDRAM_H
#define __BSP_SDRAM_H

#include "s3c2440a.h"

#define SRAM_START_ADDR                     ((uint32_t)0x0)
#define SRAM_CAPACITY                       ((uint16_t)(1024*4))

#define SDRAM_START_ADDR                    ((uint32_t)0x30000000)
#define SDRAM_CAPACITY                      ((uint32_t)(64*1024*1024)) //64MiB
#define SDRAM_REFRESH_CYCLE                 ((float)64000/8192)

#define BANKCON_BIT_MT                      0x3 //Determine the memory type 
#define BANKCON_BIT_TRCD                    0x1 //RAS to CAS delay
#define BANKCON_BIT_SCAN                    0x1 //Column address number

#define REFRESH_BIT_REFEN                   0x1 //SDRAM Refresh Enable
#define REFRESH_BIT_TREFMD                  0x0 //SDRAM Refresh Mode
#define REFRESH_BIT_TRP                     0x1 //SDRAM RAS pre-charge Time
#define REFRESH_BIT_TSR                     0x3 //SDRAM Semi Row cycle time
#define REFRESH_BIT_COUNT \
    ((uint16_t)2049 - (uint16_t)(SYS_CLOCK_FREQUENCE*SDRAM_REFRESH_CYCLE + 0.5f)) 
                                            //SDRAM refresh count value

#define BANKSIZE_BIT_BURST_EN               0x1 //ARM core burst operation enable
#define BANKSIZE_BIT_SCKE_EN                0x1 //SDRAM power down mode enable control by SCKE
#define BANKSIZE_BIT_SCLK_EN                0x1 //SCLK is enabled only during SDRAM access cycle for reducing power consumption
#define BANKSIZE_BIT_BK76MAP                0x1 //BANK6/7 memory map

#define MRSRB_BIT_CL                        0x3 //CAS latency

G_STATUS sdram_bulk_test(void);

#endif

