#include <LPC11xx.h>
#include "gpio.h"
#include "uart.h"
#include "dsp.h"
#include "music.h"

void __SystemInit(void)
{
	LPC_SYSCON->SYSAHBCLKDIV = 1; 
	LPC_SYSCON->SYSAHBCLKCTRL = 0x1005F;
}

void __main(void)
{
	uint8_t k;
	uint32_t i;

	UART_init();
	TMR16_Init();
	GPIO_init();

	if ( SysTick_Config(12000000) ) {
		while(1);
	}

	__enable_irq();

	puts("LPC1114 UART Test\r\n");

	while(1) {
		for ( k = 0; k < 8*3; k++ ) {
			LPC_TMR16B1->MR0 = Freq[k];
			LPC_TMR16B1->TCR = 1;

			for (i = 0xfffff; i !=0; i--);
			LPC_TMR16B1->TCR = 0;
			LPC_TMR16B1->TCR |= (1 << 1);
		}
	}
}

