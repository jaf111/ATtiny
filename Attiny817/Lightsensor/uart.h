

#ifndef UART_H_
#define UART_H_

#include <stdio.h> 

void uart_init(unsigned long baud); 

int uart_transmit(char data, FILE* stream); 

#endif /* UART_H_ */