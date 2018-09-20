/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************
 *
 *                       MSP430 CODE EXAMPLE DISCLAIMER
 *
 * MSP430 code examples are self-contained low-level programs that typically
 * demonstrate a single peripheral function or device feature in a highly
 * concise manner. For this the code may rely on the device's power-on default
 * register values and settings such as the clock configuration and care must
 * be taken when combining code from several examples to avoid potential side
 * effects. Also see www.ti.com/grace for a GUI- and www.ti.com/msp430ware
 * for an API functional library-approach to peripheral configuration.
 *
 * --/COPYRIGHT--*/
//***************************************************************************************
// MSP430 PushButton that toggles LED at P1.0 On and OFF
//
// Description; PushButton in P1.3 through interrupt turns on and off the LED in P1.0
// By changing the P1.3 interrupt edge, the interrupt is called every time the button
// is pushed and pulled; toggling the LED everytime.
// ACLK = n/a, MCLK = SMCLK = default DCO
//
// MSP430x2xx
// -----------------
// /|\| XIN|-
// | | |
// --|RST XOUT|-
// | |
// | P1.0|-->LED
//
// Aldo Briano
// Texas Instruments, Inc
// June 2010
// Built with Code Composer Studio v4
//***************************************************************************************


//Taken from: http://processors.wiki.ti.com/index.php/MSP430_LaunchPad_PushButton

//David Sheppard
//16 September 2018
//Lab 1: Button Blink for MSP430G2553
//Allows user to control 2 LEDs using the pin 3 button
//LEDs are on when button is held down, off when button is not held

#include <msp430x20x2.h>

#define LED0 BIT0   //defining LED0 as BIT0
#define LED1 BIT6   //defining LED1 as BIT6
#define BUTTON BIT3 //defining BUTTON as BIT3


int main(void)  //begin main function
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    P1DIR |= (LED0 + LED1); // Set P1.0 to output direction

    P1OUT &= ~(LED0 + LED1); // set P1.0 to 0 (LED OFF)
    P1IE |= BUTTON; // P1.3 interrupt enabled

    P1IFG &= ~BUTTON; // P1.3 IFG cleared

    __enable_interrupt(); // enable all interrupts
    for(;;)                 //do nothing
    {}
}


// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
P1OUT ^= (LED0 + LED1); // P1.0 = toggle
P1IFG &= ~BUTTON; // P1.3 IFG cleared
P1IES ^= BUTTON; // toggle the interrupt edge,
// the interrupt vector will be called
// when P1.3 goes from HitoLow as well as
// LowtoHigh
}
