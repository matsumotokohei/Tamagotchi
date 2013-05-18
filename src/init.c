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

	/* step 4': set flush access rate (周波数を高く設定する場合にはフラッシュメモリのアクセスサイクル数が増える) */
	FLASHCFG = (FLASHCFG & 0xFFFFFFFC) | 2;	/* Set wait state for flash memory (1WS) */
	
	/* step 5: init CLK */
	/*  a. Power on sys PLL (今回はsysclk用RC発振を元にclkを作るのでPLLのみ有効) */
	PDRUNCFG &= ~(_BV(7));
	/*  b. PLLの入力CLKの選択 */
	SYSPLLCLKSEL = 0;
	/*   PLLCLKUEN(0)の立ち上がりでSYSPLLCLKSELの値が反映される */
	raise_bit(SYSPLLCLKUEN, 0);
	/*  c. PLL設定 */
	SYSPLLCTRL = (4 - 1) | (1 << 5);
	while ((SYSPLLSTAT & 1) == 0) ;			/* Wait for PLL locked */
	/*  d. MAINCLKの選択 */
	MAINCLKSEL = 3; // PLL出力
	/*   MAINCLKUEN(0)の立ち上がりでMAINCLKSELの値が反映される */
	raise_bit(MAINCLKUEN, 0);
	/*  e. Peripheral Clkなどの設定 */
	SYSAHBCLKDIV = 1;
	SYSAHBCLKCTRL = 0x0001005f;}

