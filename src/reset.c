#include <LPC11xx.h>
#include "main.h"

void Reset_Handler(void)
{
	long *s, *d;
	extern long * _sidata, * _sdata, *  _edata;
	extern long * _sbss, * _ebss;

	for (s = _sidata, d = _sdata; d < _edata; *d++ = *s++);
	for (d = _sbss; d < _ebss; *d++ = 0);

	__SystemInit();
	__main();
	
	while(1);
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
}

void SVCall_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
	LPC_GPIO1->DATA ^= (1 << 5);
}

void WAKEUP_IRQHandler(void)
{
}

void ARRAY_COM_Rx_N_IRQHandler(void)
{
}

void ARRAY_COM_Rx_S_IRQHandler(void)
{
}

void I2C_IRQHandler(void)
{
}

void TIMER16_0_IRQHandler(void)
{
}

void TIMER16_1_IRQHandler(void)
{
}

void TIMER32_0_IRQHandler(void)
{
}

void TIMER32_1_IRQHandler(void)
{
}

void SSP_IRQHandler(void)
{
}

void UART_IRQHandler(void)
{
}

void ARRAY_COM_Rx_W_IRQHandler(void)
{
}

void ARRAY_COM_Rx_E_IRQHandler(void)
{
}

void ADC_IRQHandler(void)
{
}

void WDT_IRQHandler(void)
{
}

void BOD_IRQHandler(void)
{
}

void FMC_IRQHandler(void)
{
}

void PIOINT3_IRQHandler(void)
{
}

void PIOINT2_IRQHandler(void)
{
}

void PIOINT1_IRQHandler(void)
{
}

void PIOINT0_IRQHandler(void)
{
	LPC_GPIO1->DATA ^= (1 << 5);

	if ( LPC_GPIO0->MIS & (1 << 7) ) {
		LPC_GPIO0->IC |= (1 << 7);
	}
	else if ( LPC_GPIO0->MIS & (1 << 4) ) {
		LPC_GPIO0->IC |= (1 << 4);
	}
	else if ( LPC_GPIO0->MIS & (1 << 3) ) {
		LPC_GPIO0->IC |= (1 << 3);
	}
}

