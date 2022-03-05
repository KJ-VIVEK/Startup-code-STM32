# Startup-code-STM32
Startup code for STM32 Disc MCU, written using inline ASM and C.
Reference: https://youtu.be/qWqlkCLmZoE

OBJECTIVE: To understand how startup code and linker file work together to memory map code at respective places i,e., in FLASH and SRAM.

THEORY:

1. Processing of code:
C-program(main.c) -> pre-processor(main.i) -> compiler -> Assembly_code(main.s) -> Assembler -> Object_code(main.o) -> Linker -> Executable(main.exe)

2. Different sections of object file:

 ______FLASH________                                          _______SRAM________
|                   | : unused memory                        |                   | : Stack
 -------------------                                          ---_Stack_Start----
|                   | : unused memory                        |                   | : unused SRAM
 ------_edata-------                                          -------------------
|                   | : .data                                |                   | : heap
 ------_sdata-------                                          ------_ebss--------
|                   | : .rodata                              |                   | : .bss : copied from flash
 -------------------                                          ------_sbss--------
|                   | : .text                                |___________________| : .data=0x20000000 : copied from flash      
 -------------------
|___________________| : vector table=0x08000000

    a> .data: contains initialised data
    b> .rodata: contains read-only data
    c> .text: contains instruction code
    d> .bss: contains uninitialised data
    e> user-defined: user can put his sections
    f> special sections: added by compiler
    g> vector table: contains the reset value of SP amd exception handlers, in order.

    *.data is copied into SRAM
    *C-startup code, transfers .data section from ROM to RAM.

3. Linker file:

    a> Contains different parts, which allow compiler to understand what code, where to put during execution
    b> Linker and Locator, together assign unique absolute address to different sections of output file by  
       referring to address information mentioned in linker script
    c> It contains code and data memory address and size info
    d> Has its own format
    e> It is applied during linking phase

4. Locator is used to merge different sections and assign address.

5. Reset handler:

    a> Processor starts at pre-defind address, lets say 0x0000_0000.
    b> Processor fetches value in 0x0000_0000 to SP.
    c> Processor reads next addr after 0x0000_0000 and starts executing first instr.
    d> Here, we initialise, like, clock configuration, stack space, before calling main configuration.

6. To run the code using cmd in W11:

  1. Have Make installed. Run Makefile in cmd
  2. Install openOCD which allows debugging and programming of MCU
  3. The following cmd were used to flash code using openOCD:  
      a. arm-none-eabi-gdb.exe      
      b. target remote localhost:3333      
      c. monitor reset init      
      d. monitor flash write_image erase final.elf      
      e. monitor reset
