#include "LPC1100.h"

void main(void)
{
	int i;

	GPIO1DIR |= _BV(5);
	for (;;) {
		for (i = 0; i < 1024 * 1024; i++) {
			GPIO1DATA = GPIO1DATA;
		}
		GPIO1DATA ^= _BV(5);
	}

}

