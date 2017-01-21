#ifndef MAX7219_H_
#define	MAX7219_H_

#include <stdint.h>

/* Register address map. */
#define MAX_ADDRESS_DIGIT0       0x01
#define MAX_ADDRESS_DIGIT1       0x02
#define MAX_ADDRESS_DIGIT2       0x03
#define MAX_ADDRESS_DIGIT3       0x04
#define MAX_ADDRESS_DIGIT4       0x05
#define MAX_ADDRESS_DIGIT5       0x06
#define MAX_ADDRESS_DIGIT6       0x07
#define MAX_ADDRESS_DIGIT7       0x08
#define MAX_ADDRESS_DECODE_MODE  0x09
#define MAX_ADDRESS_INTENSITY    0x0a
#define MAX_ADDRESS_SCAN_LIMIT   0x0b
#define MAX_ADDRESS_SHUTDOWN     0x0c
#define MAX_ADDRESS_DISPLAY_TEST 0x0f

/* Shutdown register format. */
#define MAX_MODE_SHUTDOWN  0x00
#define MAX_MODE_NORMAL    0x01

/* Code B font. */
#define MAX_CHAR_0        0x00
#define MAX_CHAR_1        0x01
#define MAX_CHAR_2        0x02
#define MAX_CHAR_3        0x03
#define MAX_CHAR_4        0x04
#define MAX_CHAR_5        0x05
#define MAX_CHAR_6        0x06
#define MAX_CHAR_7        0x07
#define MAX_CHAR_8        0x08
#define MAX_CHAR_9        0x09
#define MAX_CHAR_DASH     0x0a
#define MAX_CHAR_E        0x0b
#define MAX_CHAR_H        0x0c
#define MAX_CHAR_L        0x0d
#define MAX_CHAR_P        0x0e
#define MAX_CHAR_BLANK    0x0f

#define MAX_CHAR_DOT_FLAG 0x80  /* Used as a bitflag together with other chars. */

/* No-decode mode data-bits->segments mapping. */
#define MAX_SEGMENT_DOT 0x80
#define MAX_SEGMENT_A   0x40
#define MAX_SEGMENT_B   0x20
#define MAX_SEGMENT_C   0x10
#define MAX_SEGMENT_D   0x08
#define MAX_SEGMENT_E   0x04
#define MAX_SEGMENT_F   0x02
#define MAX_SEGMENT_G   0x01

/* Scan limit register format. */
#define MAX_LIMIT_DIGITS_0        0x00
#define MAX_LIMIT_DIGITS_01       0x01
#define MAX_LIMIT_DIGITS_012      0x02
#define MAX_LIMIT_DIGITS_0123     0x03
#define MAX_LIMIT_DIGITS_01234    0x04
#define MAX_LIMIT_DIGITS_012345   0x05
#define MAX_LIMIT_DIGITS_0123456  0x06
#define MAX_LIMIT_DIGITS_01234567 0x07

/* Intensity register format (MAX7219 only). */
#define MAX_INTENSITY_1_32   0x00
#define MAX_INTENSITY_3_32   0x01
#define MAX_INTENSITY_5_32   0x02
#define MAX_INTENSITY_7_32   0x03
#define MAX_INTENSITY_9_32   0x04
#define MAX_INTENSITY_11_32  0x05
#define MAX_INTENSITY_13_32  0x06
#define MAX_INTENSITY_15_32  0x07
#define MAX_INTENSITY_17_32  0x08
#define MAX_INTENSITY_19_32  0x09
#define MAX_INTENSITY_21_32  0x0a
#define MAX_INTENSITY_23_32  0x0b
#define MAX_INTENSITY_25_32  0x0c
#define MAX_INTENSITY_27_32  0x0d
#define MAX_INTENSITY_29_32  0x0e
#define MAX_INTENSITY_31_32  0x0f

/* Intensity register format (MAX7221 only). */
#define MAX_INTENSITY_1_16     0x00
#define MAX_INTENSITY_2_16     0x01
#define MAX_INTENSITY_3_16     0x02
#define MAX_INTENSITY_4_16     0x03
#define MAX_INTENSITY_5_16     0x04
#define MAX_INTENSITY_6_16     0x05
#define MAX_INTENSITY_7_16     0x06
#define MAX_INTENSITY_8_16     0x07
#define MAX_INTENSITY_9_16     0x08
#define MAX_INTENSITY_10_16    0x09
#define MAX_INTENSITY_11_16    0x0a
#define MAX_INTENSITY_12_16    0x0b
#define MAX_INTENSITY_13_16    0x0c
#define MAX_INTENSITY_14_16    0x0d
#define MAX_INTENSITY_15_16    0x0e
#define MAX_INTENSITY_15_16max 0x0f

#define MAX_INTENSITY_MIN      0x00
#define MAX_INTENSITY_MAX      0x0f

/* Initialize driver and internal variables after the controller startup. */
void maxDriverStartupInitialize(void);

/* Send the given data to the giver register of the display driver. */
void maxDriverSendData(uint8_t address, uint8_t data);

#endif	/* MAX7219_H_ */
