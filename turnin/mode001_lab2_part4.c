/*		Name & E-mail: Michael O'Dea
 *	 	Lab Section: 025 
 *	 	Assignment: Lab #2  Exercise #4
 *	   	Exercise Description: An amusement park kid ride cart has three seats, with 8-bit weight sensors 
 *	   	connected to ports A, B, and C (measuring from 0-255 kilograms). Set PD0 to 1 if the cart's total 
 *	   	passenger weight exceeds the maximum of 140 kg. Also, the cart must be balanced: Set port PD1 to 1 
 *	   	if the difference between A and C exceeds 80 kg.  The remaining 6 bits on D should display an 
 *	   	approximation of the total combined weight, accurate within 3 kg.  (Interesting note: Disneyland 
 *	   	recently redid their "It's a Small World" ride because the average passenger weight has increased 
 *	   	over the years, causing more boats to get stuck on the bottom).
 *	    	
 *	     	I acknowledge all content contained herein, excluding template or example
 *	      	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned char A = 0x00;
	unsigned char B = 0x00;
	unsigned char C = 0x00;
	unsigned char D = 0x00;
	unsigned char E = 0x00;
	unsigned char F = 0x00;
	
	while(1){
		
		A = PINA & 0xFF;
		B = PINB & 0xFF;
		C = PINC & 0xFF;

		if(A > C){E = A - C;}
		else{E = C - A;}

		D = A + B + C;	
		F = D & 0xFC;
		
		if(D > 140){F = F | 0x01;}
		if(E > 80){F = F | 0x02;}
		
		PORTD = F;


	}

return 0;

}







