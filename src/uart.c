#include <LPC11xx.h>
#include "uart.h"

#define BAUDRATE (9600)

void UART_init(void)
{
	uint32_t DL;

	LPC_IOCON->PIO1_6 |= 0x01;
	LPC_IOCON->PIO1_7 |= 0x01;

	/* Enable UART clock */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 12);
	LPC_SYSCON->UARTCLKDIV = 0x01;

	DL = (12000000) / (16 * BAUDRATE);

	LPC_UART->LCR |= (1 << 7);
	LPC_UART->DLM = DL / 256;
	LPC_UART->DLL = DL % 256;
	LPC_UART->LCR &= ~(1 << 7); /* DLAB = 0 */
	LPC_UART->LCR = 3;
	LPC_UART->FCR = 0x07; /* Enable and reset TX and RX FIFO */
}

void UART_putc(char c)
{
	while(!(LPC_UART->LSR & (1 << 5)));
	LPC_UART->THR = c;
}

void UART_puts(char * str)
{
	while (*str != '\0') {
		UART_putc(*str);
		str++;
	}
}

int UART_getc(void)
{
	while (!(LPC_UART->LSR & 0x01));
	return LPC_UART->RBR;
}
