/*************************************************************************
	> File Name: system_init.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月29日 星期六 14时26分16秒
 ************************************************************************/

#include "system_init.h"

void sys_sdram_init(void);
void sys_cp_sram_to_sdram(void);
void sys_nand_init(void);
NAND_STATUS sys_nand_read(uint8_t *target_ptr, uint32_t size, uint32_t src_addr);


void sys_init(void)
{
    sys_sdram_init();
    //sys_cp_sram_to_sdram();
    sys_nand_init();
    //copy codes from nand flash to sdram
    sys_nand_read((uint8_t *)SDRAM_START_ADDR, CODE_SIZE, CODE_START_ADDR);
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



/*************************************************************************
                          about nand flash
 ************************************************************************/

void sys_nand_init(void)
{
    NAND_CTRL_REG_PT reg = NAND_CTRL;

    reg->NFCONF |= (NFCONF_BIT_TACLS << 11) | 
                   (NFCONF_BIT_WRPRH0 << 8) | 
                   (NFCONF_BIT_WRPRH1 << 4); 

    reg->NFCONT |= (NFCONT_BIT_INIT_ECC << 4) | 
                   (NFCONT_BIT_CE << 1) | 
                   (NFCONT_BIT_MODE << 0);

    nand_select();
    nand_write_cmd(NAND_CMD_RESET);
    nand_wait_idle();
    nand_deselect();
}

//copy codes from nand flash to sdram
NAND_STATUS sys_nand_read(uint8_t *target_ptr, uint32_t size, uint32_t src_addr)
{
    if(src_addr & NAND_PAGE_MASK)
        return NAND_STATUS_INVALID_ADDR;

    if(size & NAND_PAGE_MASK)
        return NAND_STATUS_INVALID_SIZE;
    
    nand_select();

    __IO uint8_t *ptr = (uint8_t *)&NAND_CTRL->NFADDR;
    uint32_t i = 0, j = 0;
    uint32_t tmp_addr;
    
    for(i = src_addr; i < src_addr+size; i+= NAND_PAGE_SIZE)
    {
        nand_write_cmd(NAND_CMD_READ_1st);
        tmp_addr = i;
        *ptr = (uint8_t )0x0;       //column address: A0 - A7
        *ptr = (uint8_t )0x0;       //column address: A8 - A11
        tmp_addr >>= 11;            
        //"tmp_addr >>= 12" is error, more details is in system_init.h named 
        //"CODE_START_ADDR"
        *ptr = tmp_addr & 0xFF;     //row address: A12 - A19
        tmp_addr >>= 8;
        *ptr = tmp_addr & 0xFF;     //row address: A20 - A27
        tmp_addr >>= 8;
        *ptr = tmp_addr & 0x0F ;    //row address: A28
        nand_delay();
        
        nand_write_cmd(NAND_CMD_READ_2nd);
        nand_wait_idle();
        

        for(j = 0; j < NAND_PAGE_SIZE; j++)
        {
            *target_ptr++ = nand_read_data();
        }
    }

    nand_deselect();
    return NAND_STATUS_OK;
}

