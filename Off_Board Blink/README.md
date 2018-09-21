# Off-Board Blink
- Created by David Sheppard
- 17 September 2018
- Modified 21 September: Extra Binary Counter program added
- Modified from code found in the TI Resource Explorer
# 1. Regular Program
## Purpose
The microprocessor is programmed and then removed from the board and placed onto a breadboard. The micropocessor causes 2 LEDs to blink at different rates.
## Board Layout (as seen in demo below)
- P1.0: Red LED
- P1.5: Green LED
- 3.3 V is supplied by the development board
- Reset circuitry consists of a switch, a 1 nF capacitor, and a 47 kOhm resistor
## Demo
The demo below shows the circuit running and the reset switch being pressed twice. The file can be found in video format at https://drive.google.com/file/d/1gjwNIF5b_0l1aHeVIs4melQUvIx8G14g/view?usp=sharing
![Label](GIF.GIF?raw=true "Title")
## Notes
The code is dependent upon the <msp430.h> library at a minimum.
# 2. Extra Program
## Purpose
The microprocessor controls 6 LEDs which blink to count in biary from 000000 to 111111 (0 to 63 in decimal)
## Board Layout
- LED0 = P1.5
- LED1 = P1.4
- LED2 = P1.3
- LED3 = P1.2
- LED4 = P1.1
- LED5 = P1.0
- Reset circuitry consists of a switch, a 1 nF capacitor, and a 47 kOhm resistor
## Demo
The demo below shows the circuit running through all possible 6-bit numbers. A video of the demo can be found at the following link: 
![Label](GIF2.GIF?raw=true "Title2"
