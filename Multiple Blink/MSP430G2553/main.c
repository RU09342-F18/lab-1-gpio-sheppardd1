#include <msp430.h> 



#include <msp430.h>         //include header file for this launchpad family

int main(void)  //begin main function
{
    WDTCTL = WDTPW + WDTHOLD;       //disable WDT
    BCSCTL1 = CALBC1_1MHZ;          //set clock to run at 1 MHz ("BCSCTL" = Basic Clock System Control)
    DCOCTL = CALDCO_1MHZ;           //set other clock to run at 1 MHz ("DCOCTL" = Digitally Controlled Oscillator Control)
    P1DIR = 0xFF;                   // All P1.x outputs set to 1
    P1OUT = 0;                      // All P1.x reset to 0
    P2DIR = 0xFF;                   // All P2.x outputs set to 1
    P2OUT = 0;                      // All P2.x reset to 0
    while(1){
        P1OUT ^= 0x40;              // Invert value of P1OUT Pin 6 (red LED)
        __delay_cycles(250000);     // Set delay to 1/2 second (LED is on for 1/2 second and then off for 1/2 second)
        P1OUT ^= 0x41;              //Invert P1OUT Pins 6 and 0
        __delay_cycles(250000);
    }

    return 0;
}
