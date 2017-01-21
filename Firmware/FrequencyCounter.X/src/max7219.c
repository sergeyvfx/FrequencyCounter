#include <htc.h>
#include <pic.h>

#include "max7219.h"
#include "max7219_config.h"

void maxDriverStartupInitialize(void) {
  LOAD = 1;  /* Load line is high by default. */
  CLK = 0;   /* Ensure no clock pulse is here. */
  DOUT = 0;  /* Zero data output */
}

void maxDriverSendData(uint8_t address, uint8_t data) {
#define SEND_BIT(bit) { DOUT = (bit); CLK = 1; CLK = 0; DOUT = 0; } (void)0

  LOAD = 0;

  /* 4 MSB are "don't care" */
  SEND_BIT(0);
  SEND_BIT(0);
  SEND_BIT(0);
  SEND_BIT(0);

  SEND_BIT((address & 0x08) >> 3);
  SEND_BIT((address & 0x04) >> 2);
  SEND_BIT((address & 0x02) >> 1);
  SEND_BIT((address & 0x01) >> 0);

  SEND_BIT((data & 0x80) >> 7);
  SEND_BIT((data & 0x40) >> 6);
  SEND_BIT((data & 0x20) >> 5);
  SEND_BIT((data & 0x10) >> 4);
  SEND_BIT((data & 0x08) >> 3);
  SEND_BIT((data & 0x04) >> 2);
  SEND_BIT((data & 0x02) >> 1);
  SEND_BIT((data & 0x01) >> 0);

  DOUT = 0;
  LOAD = 1;

#undef SEND_BIT
}
