.text
.global _start

_start :
    @close watch dog
    ldr     r0, =0x53000000
    mov     r1, #0x0
    str     r1, [r0]

    ldr     sp, =1024*4
    bl      sys_init
    ldr     sp, =0x34000000
    ldr     pc, =main

halt_loop :
    b   halt_loop

