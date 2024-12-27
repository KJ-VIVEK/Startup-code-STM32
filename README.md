# Startup-code-STM32
# Dec-25-2024

Startup code for STM32 Disc MCU, written using inline ASM and C.

To run the code using cmd in Linux:  
    a. Have gcc-arm-none-eabi-10.3-2021.10-x86_64-linux 
    b. Install [StLink](https://github.com/stlink-org/stlink)     
    c. Run following cmds: make all, make LedBlink.bin, make flash 

Reference: https://youtu.be/qWqlkCLmZoE

OBJECTIVE: To understand how startup code and linker file work together to memory map code at respective places i,e., in FLASH and SRAM.

THEORY: [Understanding C-Code-Working-materials]