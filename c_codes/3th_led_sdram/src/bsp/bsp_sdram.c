/*************************************************************************
	> File Name: bsp_sdram.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 16时21分19秒
 ************************************************************************/

#include "bsp_sdram.h"

//this function may cost much times under low system clock frequence
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

