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



//David Sheppard
//17 September 2018
//Lab 1: Off-Board Blink for MSP430G2553
//Purpose: Blinks LED light on an off at desired frequency. Blinking is symmetrical (time on = time off)
//Notes:
//  Adapted from code found in TI Resource Explorer
//  Original name: msp430g2xx3_lpm3.c
//  Changes made: disabled WDT, made blinking synchronous (LED time on = LED time off)



#include <msp430.h>         //include header file for this launchpad family

#define LED0 BIT5
#define LED1 BIT4
#define LED2 BIT3
#define LED3 BIT2
#define LED4 BIT1
#define LED5 BIT0

int main(void)  //begin main function
{
    WDTCTL = WDTPW + WDTHOLD;       //disable WDT
    BCSCTL1 = CALBC1_1MHZ;          //set clock to run at 1 MHz ("BCSCTL" = Basic Clock System Control)
    DCOCTL = CALDCO_1MHZ;           //set other clock to run at 1 MHz ("DCOCTL" = Digitally Controlled Oscillator Control)
    P1DIR = 0xFF;                   // All P1.x outputs set to 1
    P1OUT = 0;                      // All P1.x reset to 0

    const long delay = 200000;  //delay time

    int i = 1;  //the number displayed
    float divisor = i;  //used for checking divisibility
    P1OUT &= ~0x3F; //clear outs (set to 0)
    while(1){                       //infinite loop
        P1OUT ^= LED0;  //invert 1st LED
        //checking divisibility by comparing float division with integer division
        if((i / 2 == divisor / 2) && i != 0)    //if i is divisible by 2, invert 2nd led
        {
            P1OUT ^= LED1;
            if((i / 4 == divisor / 4) && i != 0)//if i is divisible by 4, invert 3rd led
            {
                P1OUT ^= LED2;
                if((i / 8 == divisor / 8) && i != 0)//if i is divisible by 8, invert 4th led
                {
                    P1OUT ^= LED3;
                    if((i / 16 == divisor / 16) && i != 0)//if i is divisible by 16, invert 5th led
                    {
                        P1OUT ^= LED4;
                        if((i / 32 == divisor / 32) && i != 0)//if i is divisible by 32, invert 6th led
                        {
                            P1OUT ^= LED5;
                            __delay_cycles(delay); //insert delay
                        }
                        else __delay_cycles(delay);//insert delay
                    }else __delay_cycles(delay);//insert delay
                }else __delay_cycles(delay);//insert delay
            }else __delay_cycles(delay);//insert delay
        }else __delay_cycles(delay);//insert delay
        i++;    //increment nubmer that is being displayed
        divisor = i;    //set divisor to same as i
        if(i == 64){    //if i is higher than max number that can be displayed(63), reset
            P1OUT ^= 0x3F;  //clear all values in output
            __delay_cycles(delay);  //delay
            i = 1;  //reset i
            divisor = i;    //reset divisor
        }
    }

    return 0;
}
