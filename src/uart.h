#ifndef _UART_H
#define _UART_H

#define puts(x) UART_puts(x)

#if defined(__cplusplus)
extern "C" {
#endif

void UART_init(void);
void UART_putc(char c);
void UART_puts(char * s);
int UART_getc(void);

#if defined(__cplusplus)
extern "C" {
#endif

#endif /* _UART_H */
