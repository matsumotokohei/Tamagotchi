#include <LPC11xx.h>
#include "gpio.h"
#include "uart.h"
#include "dsp.h"

void __SystemInit(void)
{
	LPC_SYSCON->SYSAHBCLKDIV = 1; 
	LPC_SYSCON->SYSAHBCLKCTRL = 0x1005F;
}

void __main(void)
{
	UART_init();
	GPIO_init();

	if ( SysTick_Config(12000000) ) {
		while(1);
	}

	__enable_irq();

	puts("LPC1114 UART Tset\r\n");

	while(1) {
		;
	}
}

