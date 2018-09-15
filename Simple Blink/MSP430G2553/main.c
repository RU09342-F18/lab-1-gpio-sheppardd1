#include <msp430.h> 


/**
 * main.c
 */

int main(void){
    P1SEL &= !BIT0;
    P1SEL2 &= !BIT0;
    P1DIR |= BIT0;
    while(1){
        P1OUT ^= BIT0;
        int i = 0;
        int j = 0;
        while(i < 10000000){
            i++;
            while(j < 10000000){
              j++;
            };
        };
    }
}
