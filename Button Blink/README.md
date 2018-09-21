# Button Blink
- Created by David Sheppard
- 16 September 2018
- Last Modified: 20 September 2018 - cleaned up code, adjusted delay, commented.
- Written with much help from Nick K.
## Purpose
Allows the user to control an LED(s) with a button on the development board.
## Implemen7ations
- The MSP430F5529 code uses a while loop to constantly check for button presses. In this implementation, the LED toggles whenever the button is pressed. It also blinks on and off if the button is held (due to button bounce).
- The MSP430G2552 code uses an interrupt to handle the button press. For this design. the LED remains lit whenever the button is held; it stays off whenever the button is not being held. Because the code utilizes interrupts, button bounce is not an issue for this implementation.
