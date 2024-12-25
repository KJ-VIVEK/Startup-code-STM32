# the name of the project
PROJNAME=LedBlink

# for the path of the project
PROJPATH=/media/kj-vivek/Projects/StartUp-Code/Startup-code-STM32/StartUp-Code

# arm cortex m4 makefile for compiling and linking the files
CC=arm-none-eabi-gcc

# for the microcontroller
MACH=cortex-m4

# for the flags
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0

# for the linker flags
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T Ls_stm32.ld -Wl,-Map=final.map

# for the objcopy
OBJCOPY=arm-none-eabi-objcopy

# for compiling all the files
all:$(PROJNAME).o Startup_stm32.o syscalls.o $(PROJNAME).elf

# compiling the $(PROJNAME)flash.c file
$(PROJNAME).o:$(PROJNAME).c
	$(CC) $(CFLAGS) -o $@ $^

# compiling the startup files
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

# compiling the syscalls files
syscalls.o:syscalls.c
	$(CC) $(CFLAGS) -o $@ $^

# linking all the files	
$(PROJNAME).elf: $(PROJNAME).o Startup_stm32.o syscalls.o
	$(CC) $(LDFLAGS) -o $@ $^

# for converting the .elf file to .hex and .bin
$(PROJNAME).bin: 
	$(OBJCOPY) -O ihex $(PROJNAME).elf $(PROJNAME).hex
	$(OBJCOPY) -O binary $(PROJNAME).elf $(PROJNAME).bin

# for flashing and debugging in linux
flash:
	st-flash write $(PROJPATH)/$(PROJNAME).bin 0x8000000

# for cleaning up the files
clean:
	rm -rf *.o *.elf *.bin *.map *.hex