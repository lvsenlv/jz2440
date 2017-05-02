/*************************************************************************
	> File Name: bsp_sdram.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 16时21分19秒
 ************************************************************************/

#include "bsp_sdram.h"

void sdram_init(void)
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

//this function may cost much times unther low system clock frequence
G_STATUS sdram_bulk_test(void)
{
    uint32_t *ptr = (uint32_t *)SDRAM_START_ADDR;
    uint32_t i = 0;

    for(i = 0; i < SDRAM_CAPACITY/4; i++)
    {
        ptr[i] = i;
    }

    for(i = 0; i < SDRAM_CAPACITY/4; i++)
    {
        if(ptr[i] != i)
            return STAT_ERR;
    }

    return STAT_OK;
}

