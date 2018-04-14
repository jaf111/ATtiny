

#define F_CPU 3333333UL
#define BAUD_9600 ((4UL*F_CPU)/9600)

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "adc.h"
#include "uart.h"

int main(void){
	
	//Initialize
	uart_init(BAUD_9600);
	adc_init();
		
	sei(); 
	
	while (1){
		
		int verdi= adc_read(0x06);
		
		//Check light in room with sensor
		printf("Lysverdi: %d \n", verdi);
		_delay_ms(250);
	}
}
