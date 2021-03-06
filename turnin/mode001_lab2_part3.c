/*		Name & E-mail: Michael O'dea, mode001@ucr.edu 
 *		 	 	Lab Section: 025 
 *		  	 	Assignment: Lab #2  Exercise #3
 *		   	   	Exercise Description: Extend the previous program to still write the available spaces    *                               number, but only to PC3..PC0, and to set PC7 to 1 if the lot is full.
 *
 *		     	     	I acknowledge all content contained herein, excluding template or example
 *		     	      	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char cntavail = 0x00;
	unsigned char spaceOne = 0x00;
	unsigned char spaceTwo = 0x00;
	unsigned char spaceThree = 0x00;
	unsigned char spaceFour = 0x00;
	
	while(1){
		spaceOne = PINA & 0x01;
		spaceTwo = PINA & 0x02;
		spaceThree = PINA & 0x04;
		spaceFour = PINA & 0x08;
	
		spaceTwo = spaceTwo >> 1;
		spaceThree = spaceThree >> 2;
		spaceFour = spaceFour >> 3;
	
		cntavail = spaceOne + spaceTwo + spaceThree + spaceFour;

		if(cntavail >= 0x04){
			PORTC = 0x80;
		}
		else{
			cntavail = 0x04 - cntavail;
			PORTC = cntavail;
		}
	}

return 0;

}





