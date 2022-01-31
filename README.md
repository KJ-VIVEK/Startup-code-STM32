# Startup-code-STM32
Startup code for STM32 Disc MCU, written using inline ASM &amp; C. 

Reference: https://youtu.be/qWqlkCLmZoE

Objective: To understand how startup code and linker file work together to memory map code at respective places i,e., in FLASH and SRAM.

To run the code using cmd in W11:
  1. Have Make installed. Run Makefile in cmd
  2. Install openOCD which allows debugging and programming of MCU
  3. The following cmd were used to flash code using openOCD:
  
      a. arm-none-eabi-gdb.exe
      
      b. target remote localhost:3333
      
      c. monitor reset init
      
      d. monitor flash write_image erase final.elf
      
      e. monitor reset
