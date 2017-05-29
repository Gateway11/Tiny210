CC := arm-linux-gcc
LD := arm-linux-ld
OBJCOPY := arm-linux-objcopy

led.bin:led.s
	$(CC) -c -o led.o $^
	$(LD) -Ttext 0x20000000 led.o -o led.elf
	$(OBJCOPY) -O binary led.elf led.bin

clean:
	rm -f *.o *.elf *.bin

