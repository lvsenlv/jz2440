/*************************************************************************
	> File Name: bsp_nand.h
	> Author: 
	> Mail: 
	> Created Time: 2017年05月02日 星期二 13时46分11秒
 ************************************************************************/

#ifndef __BSP_NAND_H
#define __BSP_NAND_H

#include "s3c2440a.h"

#define NFCONF_BIT_TACLS                    0x0 //CLE & ALE duration setting value (0~3
#define NFCONF_BIT_WRPRH0                   0x3 //TWRPH0 duration setting value (0~7)
#define NFCONF_BIT_WRPRH1                   0x0 //TWRPH1 duration setting value (0~7)

#define NFCONT_BIT_INIT_ECC                 0x1 //Initialize ECC decoder/encoder(Write-only)
#define NFCONT_BIT_CE                       0x1 //NAND Flash Memory nFCE signal control
#define NFCONT_BIT_MODE                     0x1 //NAND flash controller operating mode 

//from datasheet
#define NAND_CMD_RESET                      0xFF
#define NAND_CMD_READ_1st                   0x0 
#define NAND_CMD_READ_2nd                   0x30

#define NAND_PAGE_SIZE                      2048
#define NAND_PAGE_MASK                      (NAND_PAGE_SIZE - 1) //0x7FF

typedef enum {
    NAND_STATUS_OK                          = 0,
    NAND_STATUS_INVALID_ADDR                = 1,
    NAND_STATUS_INVALID_SIZE                = 2,
    NAND_STATUS_ECC_ERR                     = 3,
    NAND_STATUS_ELSE_ERR                    = 4,
}NAND_STATUS;

typedef enum {
    NAND_ECC_UNLOCK                         = 0,
    NAND_ECC_LOCK                           = !NAND_ECC_UNLOCK,
}NAND_ECC;



/*************************************************************************
                          inline functions
 ************************************************************************/
 
static inline void nand_delay(void)
{
    uint8_t i = 0;
    for(; i < 10; i++);
}

static inline void nand_select(void)
{
    NAND_CTRL->NFCONT &= ~(0x1 << 1);
    nand_delay();
}

static inline void nand_deselect(void)
{
    NAND_CTRL->NFCONT |= (0x1 << 1);
}

static inline void nand_write_cmd(uint8_t cmd)
{
    *(uint8_t *)&NAND_CTRL->NFCMMD = cmd;
}

static inline void nand_wait_idle(void)
{
    __IO uint8_t *ptr = (uint8_t *)&NAND_CTRL->NFSTAT;    
    while(!(*ptr & 0x1))
        nand_delay();
}

static inline void nand_write_addr(uint32_t addr)
{
    __IO uint8_t *ptr = (uint8_t *)&NAND_CTRL->NFADDR;

    *ptr = (uint8_t )0x0;   //column address: A0 - A7
    *ptr = (uint8_t )0x0;   //column address: A8 - A11
    addr >>= 12;
    *ptr = addr & 0xFF;     //row address: A12 - A19
    addr >>= 8;
    *ptr = addr & 0xFF;     //row address: A20 - A27
    addr >>= 8;
    *ptr = addr & 0x0F ;    //row address: A28
    nand_delay();
}

static inline uint8_t nand_read_data(void)
{
    return *(uint8_t *)&NAND_CTRL->NFDATA;
}

static inline void nand_reset_ecc(void)
{
    NAND_CTRL->NFCONT |= (0x1 << 4);
}

static inline void nand_lock_unlock_main_ecc(NAND_ECC stat)
{
    if(stat == NAND_ECC_UNLOCK)
        NAND_CTRL->NFCONT &= ~(0x1 << 5);
    else
        NAND_CTRL->NFCONT |=  (0x1 << 5);
}

static inline void nand_lock_unlock_spare_ecc(NAND_ECC stat)
{
    if(stat == NAND_ECC_UNLOCK)
        NAND_CTRL->NFCONT &= ~(0x1 << 6);
    else
        NAND_CTRL->NFCONT |=  (0x1 << 6);
}

static inline uint32_t nand_get_ecc(void)
{
    uint32_t ecc;
    ecc = nand_read_data();
    ecc <<= 8;
    ecc = nand_read_data();
    ecc <<= 8;
    ecc = nand_read_data();
    ecc <<= 8;
    ecc = nand_read_data();
    
    return ecc;
}



/*************************************************************************
                        function declaration
 ************************************************************************/

NAND_STATUS nand_read(uint8_t *target_ptr, uint32_t size, uint32_t src_addr);


#endif

