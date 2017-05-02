/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 15时24分28秒
 ************************************************************************/

#include "bsp_led.h"
#include "bsp_nand.h"

void delay(uint32_t count);

int main(void)
{
    led_init();
    uint8_t buf[2048];
    NAND_STATUS nand_ret = NAND_STATUS_OK;
    
    nand_ret = nand_read(buf, sizeof(buf), 4096);
    if(nand_ret != NAND_STATUS_OK)
    {
        LED1_OFF;
        LED2_ON;
    }
    else
    {
        LED1_OFF;
        LED4_ON;
    }
    delay(0x1FFFF);

    while(1)
    {
        LED1_ON;
        delay(0x5FFF);
        LED1_OFF;
        LED2_ON;
        delay(0x5FFF);
        LED2_OFF;
        LED4_ON;
        delay(0x5FFF);
        LED4_OFF;
    }
    
    return 0;
}

void delay(uint32_t count)
{
    for(;count > 0; count--);
}

