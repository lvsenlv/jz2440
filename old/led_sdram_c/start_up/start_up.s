/*************************************************************************
	> File Name: start_up.s
	> Author: 
	> Mail: 
	> Created Time: 2017年01月09日 星期一 23时54分58秒
 ************************************************************************/

.text
.global _start
_start:
    ldr     sp, =4096
    bl      disable_watchdog
    bl      memory_config
    bl      cp_sram_to_sdram
    ldr     sp, =0x34000000     @point to top of sdram
    ldr     pc, =main
halt_loop :
    b       halt_loop

