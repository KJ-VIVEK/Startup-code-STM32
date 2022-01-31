/***************************************************************
* @file      Startup_stm32.c
* @author    K J Vivek
* @brief     Set heap size, stack size and stack location according
             to application requirements.
* @reference https://youtu.be/qWqlkCLmZoE
**************************************************************/

/*Entry Point*/
ENTRY(Reset_Handler)

/*Address of User stack */
_Stack_Start =ORIGIN(SRAM) + LENGTH(SRAM);

/**********************************************************************************************
Memory Definition
Memory alisaing is done, that is the reason why code executes from 0x0800_0000 and not 0x0000_0000
**********************************************************************************************/
MEMORY
{
  FLASH(rx):ORIGIN =0x08000000,LENGTH =1024K
  SRAM(rwx):ORIGIN =0x20000000,LENGTH =128K
}

/*Sections*/
/*************************************************************

 ______FLASH________
|                   | : unused memory
 -------------------
|                   | : unused memory
 ------_edata-------
|                   | : .data
 ------_sdata-------
|                   | : .rodata
 -------------------
|                   | : .text
 -------------------
|___________________| : vector table=0x08000000


****************************************************************

 _______SRAM________
|                   | : Stack
 ---_Stack_Start----
|                   | : unused SRAM
 -------------------
|                   | : heap
 ------_ebss--------
|                   | : .bss : copied from flash
 ------_sbss--------
|___________________| : .data=0x20000000 : copied from flash

*************************************************************/
SECTIONS
{
  .text :
  {
    *(.isr_vector)
    *(.text)
	*(.text.*)
	*(.init)
	*(.fini)
	*(.rodata)
	*(.rodata.*)
	. = ALIGN(4);
	_etext = .;
  }> FLASH
  
  /* Used by the startup to initialize data */
 _la_data = LOADADDR(.data); 
  
  .data :
  {
    _sdata = .; /* Here location counter resets to start VMA for this Section */
	*(.data)
	*(.data.*)
	. = ALIGN(4);
	_edata = .;
  }> SRAM AT> FLASH
  
  .bss :
  {
    _sbss = .;
	__bss_start__ = _sbss;
	*(.bss)
	*(.bss.*)
	*(COMMON)
	. = ALIGN(4);
	_ebss = .;
	__bss_end__ = _ebss;
	   . = ALIGN(4); 
	end = .;
	__end__ = .;
  }> SRAM
    
}
