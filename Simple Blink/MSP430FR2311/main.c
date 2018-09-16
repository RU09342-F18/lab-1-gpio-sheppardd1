#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL0 = 0x0;
	P2SEL1 = 0x0;

    WDTCTL = WDTPW + WDTHOLD;       //disable WDT
    //BCSCTL1 = CALBC1_1MHZ;          //set clock to run at 1 MHz ("BCSCTL" = Basic Clock System Control)
    //DCOCTL = CALDCO_1MHZ;           //set other clock to run at 1 MHz ("DCOCTL" = Digitally Controlled Oscillator Control)
    P1DIR = 0xFF;                   // All P1.x outputs set to 1
    P1OUT = 0;                      // All P1.x reset to 0
    P2DIR = 0xFF;                   // All P2.x outputs set to 1
    P2OUT = 0;                      // All P2.x reset to 0
    while(1){
        P1OUT ^= 0x01;              // Invert value of P1OUT (the LED)
        __delay_cycles(50000);     // Set delay to 1/2 second (LED is on for 1/2 second and then off for 1/2 second)
    }
	return 0;
}
