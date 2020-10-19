/*	Author: spate130
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0x00;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0x00; PORTC = 0x00;
    /* Insert your solution below */
   
    unsigned char tmpB = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char cntavail;
    while (1) {
	 tmpA = PINA & 0x01;
	 if (tmpA == 0x01) {	
		tmpB = (tmpB & 0xFC) | 0x01;
	 } else {
		tmpB = (tmpB & 0xFC) | 0x02;
	 }
	PORTB = tmpB;

	tmpA = PINA & 0x0F;
	if(tmpA == 0x01){
		cntavail = 1;
	}
	else if(tmpA == 0x00){
		cntavail = 0;
	}
	else if(tmpA == 0x02){
		cntavail = 2;
	}
	else if (tmpA == 0x03){
		cntavail = 3;
	}
	else if (tmpA == 0x04){
		cntavail = 4;
	}

	PORTC = 4 - cntavail;
    }
    return 0;
}
