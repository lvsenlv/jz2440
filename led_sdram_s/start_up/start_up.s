/*************************************************************************
	> File Name: start_up.s
	> Author: 
	> Mail: 
	> Created Time: 2017年01月09日 星期一 23时54分58秒
 ************************************************************************/

.text
.global _start
_start:
    bl      disable_watchdog
    bl      memory_config
    bl      cp_sram_to_sdram
    ldr     pc, =on_sdram
on_sdram :
    ldr     sp, =0x34000000     @point to top of sdram
    bl      main
halt_loop :
    b       halt_loop


disable_watchdog :
    ldr     r0, =0x53000000
    mov     r1, #0x0
    str     r1, [r0]
    mov     pc, lr


memory_config :
    ldr     r0, =0x48000000
    adrl    r1, mem_conf_info
    add     r2, r0, #52 @13 members of mem_conf_info, 4byte per one
1 :
    ldr     r3, [r1], #4
    str     r3, [r0], #4
    cmp     r0, r2
    bne     1b
    mov     pc, lr


cp_sram_to_sdram :
    mov     r0, #0x0            @sram addr
    ldr     r1, =0x30000000       @sdram addr
    add     r2, r0, #4*1024     @copy 4KiB data
1 : 
    ldr     r3, [r0], #4
    str     r3, [r1], #4
    cmp     r0, r2
    bne     1b
    mov     pc, lr


.align 4
mem_conf_info :
    .long 0x02111001    @BWSCON
    .long 0x00000700    @BANKCON0
    .long 0x0           @BANKCON1
    .long 0x0           @BANKCON2
    .long 0x00000700    @BANKCON3
    .long 0x00000700    @BANKCON4
    .long 0x00000700    @BANKCON5
    .long 0x00018005    @BANKCON6
    .long 0x00018005    @BANKCON7
    .long 0x008c07a3    @REFRESH
    .long 0x000000b1    @BANKSIZE
    .long 0x00000030    @MRSRB6
    .long 0x0           @MRSRB7

