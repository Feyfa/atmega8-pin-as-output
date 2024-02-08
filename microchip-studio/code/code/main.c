#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
	// Make only PB0 as output
	// DDRB |= 1 << 0;
	// DDRB  = DDRB | 1 << 0;
	// DDRB  = 00000000 | 00000001;
	// DDRB  = 00000001;
	DDRB |= 1 << 0;
	
	// Make only PC0 and PC1 as output
	// DDRC |= 1 << 0 | 1 << 1;
	// DDRC  = DDRC | 1 << 0 | 1 << 1;
	// DDRC  = 00000000 | 00000001 | 00000010;
	// DDRC  = 00000011;
	DDRC |= 1 << 0 | 1 << 1;
	
	while (1)
	{
		// Write Logic High only at PB0
		// PORTB |= 1 << 0;
		// PORTB  = PORTB | 1 << 0;
		// PORTB  = 00000000 | 00000001;
		// PORTB  = 00000001;
		PORTB |= 1 << 0;
		
		// Write logic high only on PC0 and PC1
		// PORTC |= 1 << 0 | 1 << 1;
		// PORTC  = PORTC | 1 << 0 | 1 << 1;
		// PORTB  = 00000000 | 00000001;
		// PORTC  = 00000000 | 00000001 | 00000010;
		// PORTC  = 00000011;
		PORTC |= 1 << 0 | 1 << 1;
		
		// Wait for 500 ms
		_delay_ms(500);
		
		// Write Low Logic Only at PB0
		// PORTB &= ~(1 << 0);
		// PORTB  = PORTB & ~(00000001);
		// PORTB  = 00000001 & 111111110;
		// PORTB  = 00000000;
		PORTB &= ~(1 << 0);
		
		// Write Low Logic Only on PC0 and PC1
		// PORTC &= ~(1 << 0 | 1 << 1);
		// PORTC  = PORTC & ~(00000001 | 00000010);
		// PORTC  = 00000011 & ~(00000011);
		// PORTC  = 00000011 & 11111100;
		// PORTC  = 00000000;
		PORTC &= ~(1 << 0 | 1 << 1);
		
		// Wait for 500 ms
		_delay_ms(500);
	}
}

