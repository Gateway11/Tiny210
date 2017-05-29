.text
.global _start
_start:

    bl main

    ldr r0,=0xe0200280
    ldr r1,=0x00001010
    str r1,[r0]

    ldr r0,=0xe0200244
    mov r1,#0x0
    str r1,[r0]

loop:
    b loop
