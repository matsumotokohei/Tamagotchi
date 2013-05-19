//#include "LPC1100.h"
#include <LPC11xx.h>

void start(void)
{
	int i;

//	GPIO1DIR |= _BV(5);
	LPC_GPIO1->DIR |= (1 << 5);
	for (;;) {
		for (i = 0; i < 1024 * 1024; i++) {
//			GPIO1DATA = GPIO1DATA;
			LPC_GPIO1->DATA = LPC_GPIO1->DATA;
		}
//		GPIO1DATA ^= _BV(5);
		LPC_GPIO1->DATA ^= (1 << 5);
	}

}

