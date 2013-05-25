	.arch armv6-m

	.global	_StackTop
	.global	Reset_Handler
	.global NMI_Handler
	.global HardFault_Handler

	.section .vector
	.align 2
	.long _StackTop
	.long Reset_Handler
	.long NMI_Handler		/* -14: NMI */
	.long HardFault_Handler	/* -13: Hard Fault */
	.long 0					/* -12: Reserved */
	.long 0					/* -11: Reserved */
	.long 0					/* -10: Reserved */
	.long 0					/*  -9: Reserved */
	.long 0					/*  -8: Reserved */
	.long 0					/*  -7: Reserved */
	.long 0					/*  -6: Reserved */
	.long SVCall_Handler	/*  -5: SVCall */
	.long 0					/*  -4: Reserved */
	.long 0					/*  -3: Reserved */
	.long PendSV_Handler	/*  -2: PendSV */
	.long SysTick_Handler	/*  -1: SysTick */
	/**/
	.long WAKEUP_IRQHandler	/*   0: PIO0_0 Wakeup */
	.long WAKEUP_IRQHandler	/*   1: PIO0_1 Wakeup */
	.long WAKEUP_IRQHandler	/*   2: PIO0_2 Wakeup */
	.long WAKEUP_IRQHandler	/*   3: PIO0_3 Wakeup */
	.long WAKEUP_IRQHandler	/*   4: PIO0_4 Wakeup */
	.long WAKEUP_IRQHandler	/*   5: PIO0_5 Wakeup */
	.long WAKEUP_IRQHandler	/*   6: PIO0_6 Wakeup */
	.long WAKEUP_IRQHandler	/*   7: PIO0_7 Wakeup */
	.long WAKEUP_IRQHandler	/*   8: PIO0_8 Wakeup */
	.long WAKEUP_IRQHandler	/*   9: PIO0_9 Wakeup */
	.long WAKEUP_IRQHandler	/*  10: PIO0_10 Wakeup */
	.long WAKEUP_IRQHandler	/*  11: PIO0_11 Wakeup */
	.long WAKEUP_IRQHandler	/*  12: PIO1_0 Wakeup */
	.long ARRAY_COM_Rx_N_IRQHandler
							/*  13: Array COM Rx from North */
	.long ARRAY_COM_Rx_S_IRQHandler
							/*  14: Array COM Rx from South */
	.long I2C_IRQHandler	/*  15: I2CO */
	.long TIMER16_0_IRQHandler
							/*  16: 16-bit Timer 0 */
	.long TIMER16_1_IRQHandler
							/*  17: 16-bit Timer 1 */
	.long TIMER32_0_IRQHandler
							/*  18: 32-bit Timer 0 */
	.long TIMER32_1_IRQHandler
							/*  19: 32-bit Timer 1 */
	.long SSP_IRQHandler	/*  20: */
	.long UART_IRQHandler	/*  21: */
	.long ARRAY_COM_Rx_W_IRQHandler
							/*  22: */
	.long ARRAY_COM_Rx_E_IRQHandler
							/*  23: */
	.long ADC_IRQHandler	/*  24: */
	.long WDT_IRQHandler	/*  25: */
	.long BOD_IRQHandler	/*  26: */
	.long FMC_IRQHandler	/*  27: Flash Memory Controller */
	.long PIOINT3_IRQHandler/*  28: */
	.long PIOINT2_IRQHandler/*  29: */
	.long PIOINT1_IRQHandler/*  30: */
	.long PIOINT0_IRQHandler/*  31: */

	.end

