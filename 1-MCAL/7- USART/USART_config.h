/*
 * USART_config.h
 *
 *  Created on: Jul 10, 2022
 *      Author: mbadr
 */

#ifndef COTS_1_MCAL_7__USART_USART_CONFIG_H_
#define COTS_1_MCAL_7__USART_USART_CONFIG_H_

/*Choose USART Mode:
 * 1- ASYNCH: Asynchronous Operation
 * 2- SYNCH: synchronous Operation*/
#define USART_MODE ASYNCH

/*if you Choose Asynchronous:
 * 1- NORMAL_SPEED
 * 2- DOUBLE_SPEED*/
#define TRANS_SPEED NORMAL_SPEED

/*choose Parity Mode:
 * 1- DISABLED
 * 2- EVEN_PARITY
 * 3- ODD_PARITY*/
#define PARITY_MODE DISABLED

/*Choose NO. of stop bits:
 * 1- ONE_BIT
 * 2- TWO_BIT*/
#define STOP_BIT ONE_BIT

/*Choose NO. of Data bits:
 * 1- FIVE_BIT
 * 2- SIX_BIT
 * 3- SEVEN_BIT
 * 4- EIGHT_BIT
 * 5- NINE_BIT*/
#define DATA_BIT EIGHT_BIT

/*Choose Baud rate
 * 1- RATE_2400
 * 2- RATE_4800
 * 3- RATE_9600
 * 4_ RATE_14400
 * 5- RATE_19200
 * 6- RATE_28800
 * 7- RATE_38400
 * 8- RATE_57600
 * 9- RATE_76800
 * 10- RATE_115200
 * 11- RATE_230400
 * 12- RATE_250000*/
#define BAUD_RATE RATE_9600

#endif /* COTS_1_MCAL_7__USART_USART_CONFIG_H_ */
