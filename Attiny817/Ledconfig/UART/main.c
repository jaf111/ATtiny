#define F_CPU 3333333UL
#define BAUD_9600 ((4UL*F_CPU)/9600)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void uart_init(unsigned long baud){
	
	//Set TX 
	PORTB.DIR |= (1 << 2);
 	PORTB.OUT |= (1 << 2); 
	
	//Baudrate
	USART0.BAUD = (BAUD_9600); 
	
	//Enable RX and TX
	USART0.CTRLB |= (USART_RXEN_bm) | (USART_TXEN_bm); 
	
	
	//Enable interrupt 
	USART0.CTRLA |= (USART_RXCIE_bm);
	
}

void uart_transmit(unsigned char data){
	
	while(!(USART0.STATUS & (USART_DREIF_bm)));
		
	USART0.TXDATAL = data;
}

int main(void)
{
	uart_init(BAUD_9600);
	sei(); 
	
    while (1) 
    {
		//the ISR will handle receiving. 
    }
}

//Interrupt service 
ISR(USART0_RXC_vect){
	
	char data = USART0.RXDATAL;  
	uart_transmit(data);

}