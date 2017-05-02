.text
.global _start

_start :
    @close watch dog
    ldr     r0, =0x53000000
    mov     r1, #0x0
    str     r1, [r0]

    @configure GPIOF pin4 pin5 and pin6 as output mode
    ldr     r0, =0x56000050
    ldr     r1, [r0]
    orr     r1, r1, #0x1500
    str     r1, [r0]

    @set pin4 pin5 pin6 corresponding bit
    add     r0, r0, #0x4
    ldr     r1, [r0]
    orr     r1, r1, #0x70
    str     r1, [r0]

    @reset corresponding bit
    ldr     r1, [r0]
    bic     r1, r1, #0x10
    str     r1, [r0]

halt_loop :
    b   halt_loop

