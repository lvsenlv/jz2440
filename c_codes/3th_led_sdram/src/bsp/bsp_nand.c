/*************************************************************************
	> File Name: bsp_nand.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月02日 星期二 13时46分24秒
 ************************************************************************/

#include "bsp_nand.h"

NAND_STATUS nand_write(uint8_t *src_ptr, uint32_t target_addr, uint32_t size)
{
    if(target_addr & NAND_PAGE_MASK)
        return NAND_STATUS_INVALID_ADDR;
    
    if(size & NAND_PAGE_MASK)
        return NAND_STATUS_INVALID_SIZE;


    return NAND_STATUS_OK;
}

NAND_STATUS nand_read(uint8_t *target_ptr, uint32_t size, uint32_t src_addr)
{
    if(src_addr & NAND_PAGE_MASK)
        return NAND_STATUS_INVALID_ADDR;

    if(size & NAND_PAGE_MASK)
        return NAND_STATUS_INVALID_SIZE;

    nand_reset_ecc();
    nand_select();
    
    uint32_t i = 0, j = 0;
    uint32_t main_ecc, spare_ecc;
    
    for(i = src_addr; i < NAND_PAGE_SIZE+size; i+= NAND_PAGE_SIZE)
    {
        nand_lock_unlock_main_ecc(NAND_ECC_UNLOCK);

        nand_write_cmd(NAND_CMD_READ_1st);
        nand_write_addr(src_addr);
        nand_write_cmd(NAND_CMD_READ_2nd);
        nand_wait_idle();
        
        for(j = 0; j < NAND_PAGE_SIZE; j++)
        {
            *target_ptr++ = nand_read_data();
        }

        nand_lock_unlock_main_ecc(NAND_ECC_LOCK);
        nand_lock_unlock_spare_ecc(NAND_ECC_UNLOCK);

        main_ecc = nand_get_ecc();
        spare_ecc = nand_get_ecc();
        
        NAND_CTRL->NFMECCD0 = (main_ecc & 0xFF) | ((main_ecc & 0xFF00) << 8);
        NAND_CTRL->NFMECCD1 = ((main_ecc & 0xFF0000) >> 16) | 
                              ((main_ecc & 0xFF000000) >> 8);

        nand_lock_unlock_spare_ecc(NAND_ECC_LOCK);

        NAND_CTRL->NFSECCD = (spare_ecc & 0xFF) | ((spare_ecc & 0xFF00) << 8);

        if((NAND_CTRL->NFESTAT0 & 0xF) != 0)
        {
            nand_deselect();
            return NAND_STATUS_ECC_ERR;
        }
    }

    nand_deselect();
    return NAND_STATUS_OK;
}
/*
U8 rNF_ReadPage( U32 page_number )

{
 
       //把读取到的spare区的ECC校验码放入NFSECCD的相应位置内

rNFSECCD=((secc&0xff00)<<8)|(secc&0xff);

    NF_nFCE_H();   //关闭nandflash片选

      

    //判断所读取到的数据是否正确

if ((rNFESTAT0&0xf) == 0x0)

return 0x66;                  //正确

else

return 0x44;                  //错误

}
*/
