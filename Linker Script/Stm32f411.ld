/*
 * @file    stm32f411.ld
 * @author  Abdelmoniem Ahmed
 * @brief   GNU LD linker script for STM32F411 (Cortex-M4)
 *
 * Defines memory regions and section placement for a bare-metal
 * STM32 application.
 */


_estack = ORIGIN(RAM) + LENGTH(RAM); /* Initial stack pointer */

_Min_Heap_Size = 0x200;      /* Minimum heap size */
_Min_Stack_Size = 0x400;     /* Minimum stack size */



/* Memory Definition */

MEMORY{
	FLASH (rx) : ORIGIN = 0x08000000 , LENGTH = 512K    /* From 0x08000000 to 0x0807FFFF */
	RAM (rwx)  : ORIGIN = 0x20000000 , LENGTH = 128K    /* From 0x20000000 to 0x2001FFFF */
}

/*  
	r ->  Read  
	w ->  Write 
	x ->  Execute
*/


/* Sections */

SECTIONS{
	/* to instruct the compiler to store the ISR vector table at the start of the flash despite it is -> a data not code <- */
	.isr_vector : {
			. = ALIGN(4);
				*(.isr_vector)
			. = ALIGN(4);
	} >FLASH

	.text : {
			_scode = .; /* Start address of .text section in FLASH */
			. = ALIGN(4);
				*(.text)
				*(.text*)
			. = ALIGN(4);
			_ecode = .; /* End address of .text section in FLASH */
	} >FLASH
/* Custom section for application-specific code/data */
	.My_custom_Section : {
			. = ALIGN(4);
				*(.My_custom_Section)
				*(.My_custom_Section*)
			. = ALIGN(4);
	}
	
	.rodata : {
			_srodata = .; /* Start address of .rodata section in FLASH */
			. = ALIGN(4);
				*(.rodata)
				*(.rodata*)	
			. = ALIGN(4);
			_erodata = .; /* End address of .rodata section in FLASH */
	} >FLASH
    /* Used by startup code for load the .data section at Ram from Flash */
	_sidata = LOADADDR(.data); /* Load address of .data section in FLASH */

	.data : {
			_sdata = .; /* Start address of .data section in RAM */
			. = ALIGN(4);
				*(.data)
				*(.data*)	
			. = ALIGN(4);
			_edata = .; /* End address of .data section in RAM */
	} >RAM AT >FLASH

	.bss : {
			_sbss = .; /* Start address of .bss section in RAM */
			. = ALIGN(4);
				*(.bss)
				*(.bss*)
			. = ALIGN(4);
			_ebss = .; /* End address of .bss section in RAM */
	} >RAM

			end = .; /* End of RAM used by the program */
			_end = .;
			__end__ = .;
	.User_heap_stack : {
			. = ALIGN(4);
				*(.User_heap_stack)
				*(.User_heap_stack*)
			. = ALIGN(4);
	} >RAM

}