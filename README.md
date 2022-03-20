# Startup-code-STM32
Startup code for STM32 Disc MCU, written using inline ASM and C.

Reference: https://youtu.be/qWqlkCLmZoE

OBJECTIVE: To understand how startup code and linker file work together to memory map code at respective places i,e., in FLASH and SRAM.

THEORY:

1. Processing of code:
C-program(main.c) -> pre-processor(main.i) -> compiler -> Assembly_code(main.s) -> Assembler -> Object_code(main.o) -> Linker -> Executable(main.exe)

2. Different sections of object file:
    - .data: contains initialised data
    - .rodata: contains read-only data
    - .text: contains instruction code
    - .bss: contains uninitialised data
    - user-defined: user can put his sections
    - special sections: added by compiler
    - vector table: contains the reset value of SP amd exception handlers, in order.

   *.data is copied into SRAM
   **C-startup code, transfers .data section from ROM to RAM.

3. Linker file:
    - Contains different parts, which allow compiler to understand what code, where to put during execution
    - Linker and Locator, together assign unique absolute address to different sections of output file by referring to address information mentioned in linker script
    - It contains code and data memory address and size info
    - Has its own format
    - It is applied during linking phase

4. Locator is used to merge different sections and assign address.

5. Reset handler:
    - Processor starts at pre-defind address, lets say 0x0000_0000.
    - Processor fetches value in 0x0000_0000 to SP.
    - Processor reads next addr after 0x0000_0000 and starts executing first instr.
    - Here, we initialise, like, clock configuration, stack space, before calling main configuration.

6. To run the code using cmd in W11:
    - Have Make installed. Run Makefile in cmd
    - Install openOCD which allows debugging and programming of MCU
    - The following cmd were used to flash code using openOCD:  
        i. arm-none-eabi-gdb.exe      
        ii. target remote localhost:3333      
        iii. monitor reset init      
        iv. monitor flash write_image erase final.elf      
        v. monitor reset
