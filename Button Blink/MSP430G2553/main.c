#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	if(P1OUT == )
	P1OUT ^= 0x01;

	return 0;
}
