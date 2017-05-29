CC := arm-linux-gcc
LD := arm-linux-ld
OBJCOPY := arm-linux-objcopy
CFLAGS :=

led.bin:led.o main.o
	$(LD) -Ttext 0x20000000 $^ -o led.elf
	$(OBJCOPY) -O binary led.elf $@

%.o:%.s
	$(CC) -c -o $@ $<

%.o:%.c
	$(CC) -c -o $@ $<

clean:
	rm -f *.o *.elf *.bin

