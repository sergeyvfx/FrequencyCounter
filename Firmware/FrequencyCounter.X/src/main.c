#include <stdlib.h>
#include <pic16f628a.h>
#include <pic.h>

#include "max7219.h"

#pragma config BOREN = 0FF
#pragma config CP = 0FF
#pragma config WDTE = 0FF
#pragma config LVP = 0FF
#pragma config FOSC = INTOSCIO

#define _XTAL_FREQ 4000000

int main(int argc, char **argv) {
  OSCF = 1;  /* 4Mhz oscillator. */

  /* Setup the timer. */
  TMR1IE = 0; /* Disable the TMR1 overflow interrupt. */
  TMR1CS = 1; /* Clock source: external clock (T1CKI on the rising edge). */
  T1CKPS0 = 0; /* 1:1 divider on timer1. */
  T1CKPS1 = 0;
  T1OSCEN = 1;

  /* Configure ports as inputs (1) or outputs(0). */
  TRISA = 0x0;
  TRISB = 0x0;

  /* RB6 is used as timer input. */
  TRISBbits.TRISB6 = 1;

  /* Delay before talking to MAX, let it settle down. */
  __delay_us(100);

  maxDriverStartupInitialize();

  /* Set per-digit decode mode.
   * - If bit for the digit is 0, no decode is used.
   * - If bit for the digit is 1, code B is used
   */
  maxDriverSendData(MAX_ADDRESS_DECODE_MODE, 0xff);

  /* We're currently only 3 digits for the tests. */
  maxDriverSendData(MAX_ADDRESS_SCAN_LIMIT, MAX_LIMIT_DIGITS_012);

  /* Maximum intensity. */
  maxDriverSendData(MAX_ADDRESS_INTENSITY, 0x0f);

  /* Switch tp normal mode. */
  maxDriverSendData(MAX_ADDRESS_SHUTDOWN, MAX_MODE_NORMAL);

  while(1) {
    TMR1L = 0;
    TMR1H = 0;
    TMR1ON = 1;
    __delay_us(1000);
    TMR1ON = 0;

    maxDriverSendData(MAX_ADDRESS_DIGIT0, TMR1L % 10);
    maxDriverSendData(MAX_ADDRESS_DIGIT1, TMR1L / 10 % 10);
    maxDriverSendData(MAX_ADDRESS_DIGIT2, TMR1L / 100 % 10);

    __delay_ms(500);
  }

  return EXIT_SUCCESS;
}