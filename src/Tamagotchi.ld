MEMORY {
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 32k
	RAM (rwx)  : ORIGIN = 0x10000000, LENGTH =  4k
}

ENTRY(Reset_Handler)

SECTIONS {
	. = ORIGIN(FLASH);
	_stext = .;
	.text : {
		KEEP(*(.vector))
		*(.text .text.*)
		*(.rodata .rodata.*)
	} >FLASH =0
	. = ALIGN(4);
	_etext = .;
	
	_sidata = .;
	.data : {
		_sdata = .;
		*(.data .data.*)
		. = ALIGN(4);
		_edata = .;
	} >RAM AT>FLASH =0
	
	.bss (NOLOAD) : {
		_sbss = .;
		*(.bss .bss.* .COMMON .COMMON.*)
		. = ALIGN(4);
		_ebss = .;
	} >RAM

	_StackTop = ORIGIN(RAM) + LENGTH(RAM);
}
