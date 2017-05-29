CC := arm-linux-gcc
LD := arm-linux-ld
OBJCOPY := arm-linux-objcopy

led.bin:led.s led.c
	$(CC) -c -o led.o $<
	$(CC) -c -o led_c.o led.c
	$(LD) -Ttext 0x20000000 led.o led_c.o -o led.elf
	$(OBJCOPY) -O binary led.elf $@

clean:
	rm -f *.o *.elf *.bin

