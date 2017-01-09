/*************************************************************************
	> File Name: start_up.s
	> Author: 
	> Mail: 
	> Created Time: 2017年01月09日 星期一 23时54分58秒
 ************************************************************************/

.text
.global _start
_start:
        ldr     r0, =0x53000000     @在r0寄存器中写入看门狗寄存器的地址
        mov     r1, #0x0            
        str     r1, [r0]            @将r1寄存器中的值写入r0寄存器，写入0即可关闭看门狗

        ldr     sp, =1024*4         @设置栈指针，sram只有

        bl      main                @跳转到main函数
unconditional_branch:
        b       unconditional_branch                @死循环
