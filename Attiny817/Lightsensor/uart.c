

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "uart.h"

void uart_init(unsigned long baud){
	
	PORTB.OUTSET |= (1 << PIN2_bp);
	PORTB.DIRSET |= (1 << PIN2_bp); 		
	USART0.BAUD = baud; 	
	USART0.CTRLB |= (1 << USART_RXEN_bp) | (1 << USART_TXEN_bp);	//Enable RX and TX
	
	
	USART0.CTRLA |= (1 << USART_RXCIE_bp); //Enable interupts on RX
	
	fdevopen(uart_transmit, NULL); 
}

int uart_transmit(char data, FILE* stream){
	while (!(USART0.STATUS & (1 << USART_DREIF_bp)));
	USART0.TXDATAL = data; 
	return 0;
}

ISR(USART0_RXC_vect){
	
	uint8_t data = USART0.RXDATAL; 
}