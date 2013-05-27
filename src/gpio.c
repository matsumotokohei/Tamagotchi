#include <LPC11xx.h>

void GPIO_init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 6);

	LPC_IOCON->PIO1_5 = 0xd0; /* pull up */

	LPC_IOCON->PIO0_7 = 0xd0; /* pull up */
	LPC_IOCON->PIO0_4 = 0xd0; /* pull up */
	LPC_IOCON->PIO0_3 = 0xd0; /* pull up */

	/**/
	LPC_GPIO1->DIR |= (1 << 5); /* output */

	LPC_GPIO0->DIR &= ~(1 << 7); /* input */
	LPC_GPIO0->DIR &= ~(1 << 4); /* input */
	LPC_GPIO0->DIR &= ~(1 << 3); /* input */

	/* interrupt */
	NVIC_EnableIRQ(EINT0_IRQn);

	LPC_GPIO0->IS &= ~(1 << 7);
	LPC_GPIO0->IS &= ~(1 << 4);
	LPC_GPIO0->IS &= ~(1 << 3);

	LPC_GPIO0->IBE &= ~(1 << 7);
	LPC_GPIO0->IBE &= ~(1 << 4);
	LPC_GPIO0->IBE &= ~(1 << 3);

	LPC_GPIO0->IEV &= ~(1 << 7);
	LPC_GPIO0->IEV &= ~(1 << 4);
	LPC_GPIO0->IEV &= ~(1 << 3);

	LPC_GPIO0->IE |= (1 << 7);
	LPC_GPIO0->IE |= (1 << 4);
	LPC_GPIO0->IE |= (1 << 3);
}

