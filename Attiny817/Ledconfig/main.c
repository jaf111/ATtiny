/*
 * ledconfig.c
 *
 * Created: 11.02.2017 23:56:53
 * Author : JanF
 */ 

// F_CPU
#define F_CPU 3333333UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

// LEDs - OLED1 Xplained Pro
#define LED1 7
#define LED2 8
#define LED3 6

// Buttons - OLED1 Xplained Pro
#define BUTTON1 9
#define BUTTON2 3
#define BUTTON3 4

#define PULLUPEN 3 

int main(void){
	
    PORTB.DIR |= (1 << LED1);
	PORTB.DIR &= ~(1 << BUTTON1);
	PORTB.DIR |= (1 << LED2);
	PORTB.DIR &= ~(1 << BUTTON2);
	PORTB.DIR |= (1 << LED3);
	PORTB.DIR &= ~(1 << BUTTON3);
	PORTB.PIN1CTRL |= (1 << PULLUPEN);
	PORTB.PIN2CTRL |= (1 << PULLUPEN);
	PORTB.PIN3CTRL |= (1 << PULLUPEN);
	int a=0;
	int b=0;
	int c=0;
    while (1){
		/*
		* turn on LED if button pressed
		*/
		if(!(PORTB.IN & (1 << BUTTON1)) && a==1 ){
			PORTB.OUT ^= (1 << LED1);
			a=0;
		}
		else if ((PORTB.IN & (1 << BUTTON1)) && a==0){
			a=1;
		}
		if(!(PORTB.IN & (1 << BUTTON2)) && b==1 ){
			PORTB.OUT ^= (1 << LED2);
			b=0;
		}
		else if ((PORTB.IN & (1 << BUTTON2)) && b==0){
			b=1;
		}
		if(!(PORTB.IN & (1 << BUTTON3)) && c==1 ){
			PORTB.OUT ^= (1 << LED3);
			c=0;
		}
		else if ((PORTB.IN & (1 << BUTTON3)) && c==0){
			c=1;
		}
    }
}

