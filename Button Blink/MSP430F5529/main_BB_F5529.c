//Written with much help from Nick K. (LA)

//David Sheppard
//16 September 2018
//Modified 20 September 2018 - code cleaned up, delay adjusted, comments added

//Lab 1: Button Blink for MSP430F5529
//Allows user to control LEDs using the pin 3 button
//Hitting the button (P1.1) toggles the red LED (P1.0)
//If button is held for over 300000 clock cycles, LED blinks on and off repeatedly


#include <msp430F5529.h>

#define BUTTON BIT1

int main(void){

     WDTCTL = WDTPW + WDTHOLD;       //disable WDT (lets us have infinite loops)
     P1DIR = 0xFF;                   // All P1.x directions set to 1 (in order to be outputs
     P1OUT = 0;                      // All P1.x reset to 0
     P1REN = BUTTON;                  //setup resistor (resistor enable)
     P1DIR |= ~BUTTON;              //set P1.1 to be an input (unlike all other P1.x pins)
     P1OUT |= BUTTON;               //set output to Button


     while(1){                              //infinite loop; always check the following if statement every time While loop completes
         if((P1IN & BUTTON) == 0x00){       //c
             P1OUT ^= BIT0;                 //toggle LED
             __delay_cycles(300000);        //create delay
             //without this delay, button shake would cause unpredictable behavior. This gives the user time to let go of button.
             //As a side effect of button shake, if user holds down button for longer than 300000 clock cycles, led will blink on and off repeatedly
         }
     }
return 0;
}
