MEMORY
{
	PAGE 0:
		PRUIMEM:	o = 0x00000000	l = 0x00001000 	/* 4KB PUR0 Instruction RAM */
	PAGE 1:
		PRUDMEM:	o = 0x00000000	l = 0x00000200	/* 512B PRU Data RAM 0 */
}

SECTIONS
{
	.text:_c_int00*		>	0x0
	.text				>	PRUIMEM, PAGE 0
	.bss				>	PRUDMEM, PAGE 1
	.data				>	PRUDMEM, PAGE 1
	.rodata				>	PRUDMEM, PAGE 1
	.farbss				>	PRUDMEM, PAGE 1
	.fardata			>	PRUDMEM align=4, PAGE 1
	.rofardata			>	PRUDMEM align=4, PAGE 1
	.sysmem				>	PRUDMEM, PAGE 1
	.stack				>	PRUDMEM align=4, PAGE 1
	.init_array			>	PRUDMEM, PAGE 1
	.cinit				>	PRUDMEM, PAGE 1
	.args				>	PRUDMEM, PAGE 1
}
