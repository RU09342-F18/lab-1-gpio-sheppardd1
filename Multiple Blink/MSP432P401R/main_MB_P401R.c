
//David Sheppard
//16 September 2018
//Lab 1: Multiple Blink Blink for MSP432P401R
//Purpose: Blinks LED light on an off at desired frequency. Blinking is symmetrical (time on = time off)
//Notes:
//  Adapted from code found in TI Resource Explorer
//  Original name: msp430g2xx3_lpm3.c
//  Changes made: disabled WDT, made blinking synchronous (LED time on = LED time off), added 2nd LED


#include <msp432.h>         //include header file for this launchpad family

int main(void)  //begin main function
{
    WDTCTL = WDTPW + WDTHOLD;       //disable WDT
    //BCSCTL1 = CALBC1_1MHZ;          //set clock to run at 1 MHz ("BCSCTL" = Basic Clock System Control)
    //DCOCTL = CALDCO_1MHZ;           //set other clock to run at 1 MHz ("DCOCTL" = Digitally Controlled Oscillator Control)
    P1DIR = 0xFF;                   // All P1.x outputs set to 1
    P1OUT = 0;                      // All P1.x reset to 0
    P2DIR = 0xFF;                   // All P2.x outputs set to 1
    P2OUT = 0;                      // All P2.x reset to 0
    //P1SEL &= ~0x01;                 //set first MUX select bit to 0 in order to set P1.0 as an output
    //P1SEL2 &= !0x01;                //set second MUX select bit to 0 in order to set P1.0 as an output

    while(1){                       //infinite loop
        P1OUT ^= 0x01;              // Invert value of P1 LED only
        __delay_cycles(300000);     // Set delay to 1/4 second
        P2OUT ^= 0x01;              //Invert 21 LED...
        P1OUT ^= 0x01;              //...and invert P1 LED
        __delay_cycles(300000);     //add another 1/4 second delay
    }

    return 0;
}

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
//******************************************************************************
//  MSP430G2xx3 Demo - Basic Clock, LPM3 Using WDT ISR, 32kHz ACLK
//
//  Description: This program operates MSP430 normally in LPM3, pulsing P1.0
//  at 4 second intervals. WDT ISR used to wake-up system. All I/O configured
//  as low outputs to eliminate floating inputs. Current consumption does
//  increase when LED is powered on P1.0. Demo for measuring LPM3 current.
//  ACLK = LFXT1/4 = 32768/4, MCLK = SMCLK = default DCO ~ 800kHz
//  //* External watch crystal installed on XIN XOUT is required for ACLK *//
//
//
//           MSP430G2xx3
//         ---------------
//     /|\|            XIN|-
//      | |               | 32kHz
//      --|RST        XOUT|-
//        |               |
//        |           P1.0|-->LED
//
//  D. Dang
//  Texas Instruments Inc.
//  December 2010
//   Built with CCS Version 4.2.0 and IAR Embedded Workbench Version: 5.10
//******************************************************************************


