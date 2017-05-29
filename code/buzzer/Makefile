CC := arm-linux-gcc
LD := arm-linux-ld
OBJCOPY := arm-linux-objcopy
CFLAGS :=

a.bin:start.o main.o
	$(LD) -Ttext 0x20000000 $^ -o a.elf
	$(OBJCOPY) -O binary a.elf $@

%.o:%.s
	$(CC) -c -o $@ $<

%.o:%.c
	$(CC) -c -o $@ $<

clean:
	rm -f *.o *.elf *.bin

