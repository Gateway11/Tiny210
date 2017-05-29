.text
.global _start

_start:
    bl main

_loop:
    b _loop
