/*************************************************************************
	> File Name: s3c2440a.h
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时30分58秒
 ************************************************************************/

#ifndef _S3C2440A_H
#define _S3C2440A_H

typedef     short                           int16_t;
typedef     int                             int32_t;
typedef     long long                       int64_t;
typedef     unsigned char                   uint8_t;
typedef     unsigned short                  uint16_t;
typedef     unsigned int                    uint32_t;
typedef     unsigned long long              uint64_t;

#define __IO                                volatile

#define GPIO_BASE                           ((uint32_t)0x56000000)
#define GPIOF_BASE                          (GPIO_BASE + 0x50)
#define MEM_CTRL_BASE                       ((uint32_t)0x48000000)
#define NAND_CTRL_BASE                      ((uint32_t)0x4E000000)

#define GPIOF                               ((GPIO_REG_PT)GPIOF_BASE)
#define MEM_CTRL                            ((MEM_CTRL_REG_PT)MEM_CTRL_BASE)
#define MEM_CTRL_BANK6                      6 //sdram is connetted to bank6
#define NAND_CTRL                           ((NAND_CTRL_REG_PT)NAND_CTRL_BASE)

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
}MEM_CTRL_REG_T, *MEM_CTRL_REG_PT;

typedef struct {
    __IO uint32_t NFCONF;
    __IO uint32_t NFCONT;
    __IO uint32_t NFCMMD;
    __IO uint32_t NFADDR;
    __IO uint32_t NFDATA;
    __IO uint32_t NFMECCD0;
    __IO uint32_t NFMECCD1;
    __IO uint32_t NFSECCD;
    __IO uint32_t NFSTAT;
    __IO uint32_t NFESTAT0;
    __IO uint32_t NFESTAT1;
    __IO uint32_t NFMECC0;
    __IO uint32_t NFMECC1;
    __IO uint32_t NFSECC;
    __IO uint32_t NFSBLK;
    __IO uint32_t NFEBLK;
}NAND_CTRL_REG_T, *NAND_CTRL_REG_PT;

#endif

