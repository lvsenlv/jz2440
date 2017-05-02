/*************************************************************************
	> File Name: system_init.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月29日 星期六 14时26分16秒
 ************************************************************************/

#include "system_init.h"

void sys_sdram_init(void);
void sys_cp_sram_to_sdram(void);

void sys_init(void)
{
    sys_sdram_init();
    sys_cp_sram_to_sdram();
}



/*************************************************************************
                            about sdram
 ************************************************************************/

void sys_sdram_init(void)
{
    MEM_CTRL_REG_PT reg = MEM_CTRL;
    uint32_t tmp = 0;
    
    reg->BWSCON |= ((uint32_t)0x2 << MEM_CTRL_BANK6*4);

    tmp = 0;
    tmp |= BANKCON_BIT_MT;
    tmp <<= 13;
    tmp |= BANKCON_BIT_TRCD;
    tmp <<= 2;
    tmp |= BANKCON_BIT_SCAN;
    reg->BANKCON6 = tmp;

    tmp = 0;
    tmp |= REFRESH_BIT_REFEN;
    tmp <<= 1;
    tmp |= REFRESH_BIT_TREFMD;
    tmp <<= 2;
    tmp |= REFRESH_BIT_TRP;
    tmp <<= 2;
    tmp |= REFRESH_BIT_TSR;
    tmp <<= 18;
    tmp |= REFRESH_BIT_COUNT;
    reg->REFRESH = tmp;

    tmp = 0;
    tmp |= BANKSIZE_BIT_BURST_EN;
    tmp <<= 2;
    tmp |= BANKSIZE_BIT_SCKE_EN;
    tmp <<= 1;
    tmp |= BANKSIZE_BIT_SCLK_EN;
    tmp <<= 4;
    tmp |= BANKSIZE_BIT_BK76MAP;
    reg->BANKSIZE = tmp;

    reg->MRSRB6 |= ((uint16_t)MRSRB_BIT_CL << 4);
}

void sys_cp_sram_to_sdram(void)
{
    uint32_t *src_ptr = (uint32_t *)(SRAM_START_ADDR + 1024);
    uint32_t *target_ptr = (uint32_t *)0x30000000;
    uint32_t i = 0;
    uint32_t size = (SRAM_CAPACITY-1024)/sizeof(uint32_t);

    for(i = 0; i < size; i++)
    {
        *target_ptr++ = *src_ptr++;
    }
}

