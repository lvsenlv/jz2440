/*************************************************************************
	> File Name: init.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月26日 星期日 11时35分56秒
 ************************************************************************/

//void disable_watchdog(void);
//void memory_config(void);
//void cp_sram_to_sdram(void);

void disable_watchdog(void)
{
    *((volatile unsigned long *)0x53000000) = 0;
}

void memory_config(void)
{
    volatile unsigned long *ptr = (volatile unsigned long *)0x48000000;
    *ptr++ = 0x02111001;        //BWSCON
    *ptr++ = 0x00000700;        //BANK0     -nor flash
    *ptr++ = 0x00000000;        //BANK1     -null 
    *ptr++ = 0x00000000;        //BANK2     -null 
    *ptr++ = 0x00000700;        //BANK3     -J3 external expansion socket
    *ptr++ = 0x00000700;        //BANK4     -DM9000 network card
    *ptr++ = 0x00000700;        //BANK5     -J2 external expansion socket
    *ptr++ = 0x00018005;        //BANK6     -SDRAM
    *ptr++ = 0x00000000;        //BANK7     -null 
    *ptr++ = 0x008c07a3;        //REFRESH
    *ptr++ = 0x000000b1;        //BANKSIZE
    *ptr++ = 0x00000030;        //MRSRB6
    *ptr = 0x00000000;          //MRSRB7
}

void cp_sram_to_sdram(void)
{
    unsigned long *sram = (unsigned long *)1024;
    unsigned long *sdram = (unsigned long *)0x30000000;
    unsigned long size = 3072;
    unsigned long i = 0;

    for(;i < size; i++)
    {
        sdram[i] = sram[i];
    }
}
