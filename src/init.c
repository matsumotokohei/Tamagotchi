#include "LPC1100.h"

extern long * _sidata;
extern long * _sdata;
extern long * _edata;
extern long * _sbss;
extern long * _ebss;

#define raise_bit(sfr, bit) \
	do {	\
		sfr |= _BV(bit);	\
		sfr &= ~_BV(bit);	\
		sfr |= _BV(bit);	\
		while (!(sfr & _BV(bit)));	\
	} while(0)

void init(void)
{
	long *s, *d;
	/* step 4: init SRAM */
	for (s = _sidata, d = _sdata; d < _edata; *d++ = *s++);
	for (d = _sbss; d < _ebss; *d++ = 0);

	/* step 4': set flush access rate (���g���������ݒ肷��ꍇ�ɂ̓t���b�V���������̃A�N�Z�X�T�C�N������������) */
	FLASHCFG = (FLASHCFG & 0xFFFFFFFC) | 2;	/* Set wait state for flash memory (1WS) */
	
	/* step 5: init CLK */
	/*  a. Power on sys PLL (�����sysclk�pRC���U������clk�����̂�PLL�̂ݗL��) */
	PDRUNCFG &= ~(_BV(7));
	/*  b. PLL�̓���CLK�̑I�� */
	SYSPLLCLKSEL = 0;
	/*   PLLCLKUEN(0)�̗����オ���SYSPLLCLKSEL�̒l�����f����� */
	raise_bit(SYSPLLCLKUEN, 0);
	/*  c. PLL�ݒ� */
	SYSPLLCTRL = (4 - 1) | (1 << 5);
	while ((SYSPLLSTAT & 1) == 0) ;			/* Wait for PLL locked */
	/*  d. MAINCLK�̑I�� */
	MAINCLKSEL = 3; // PLL�o��
	/*   MAINCLKUEN(0)�̗����オ���MAINCLKSEL�̒l�����f����� */
	raise_bit(MAINCLKUEN, 0);
	/*  e. Peripheral Clk�Ȃǂ̐ݒ� */
	SYSAHBCLKDIV = 1;
	SYSAHBCLKCTRL = 0x0001005f;}

