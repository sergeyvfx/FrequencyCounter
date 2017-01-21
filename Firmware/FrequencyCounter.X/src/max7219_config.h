#ifndef MAX7219_CONFIG_H_
#define	MAX7219_CONFIG_H_

/* NOTE: ports shall be configured for the outout by the main function.
 *       Driver's code doesnt' touch TRIS bits at all.
 */

/* Port used to send data to driver's Din line. */
#define DOUT PORTAbits.RA2

/* Port used for driver's CLK line. */
#define CLK  PORTAbits.RA3

/* Port used for driver's LOAD line. */
#define LOAD PORTAbits.RA1
//#define LOAD PORTAbits.RA4

#endif	/* MAX7219_CONFIG_H_ */
