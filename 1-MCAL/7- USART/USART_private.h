/*
 * USART_private.h
 *
 *  Created on: Jul 10, 2022
 *      Author: mbadr
 */

#ifndef COTS_1_MCAL_7__USART_USART_PRIVATE_H_
#define COTS_1_MCAL_7__USART_USART_PRIVATE_H_
/*USART Modes*/
#define ASYNCH 			1
#define SYNCH 			2

/*Parity Mode*/
#define PARITY_MASK		0b11001111
#define DISABLED		0b00000000
#define EVEN_PARITY		0b00100000
#define ODD_PARITY		0b00110000

/*NO. of stop bits*/
#define ONE_BIT			1
#define TWO_BIT			2

/*NO. of Data Bits*/
#define DATA_MASK		0b11111001
#define FIVE_BIT		0b00000000
#define SIX_BIT  		0b00000010
#define SEVEN_BIT		0b00000100
#define EIGHT_BIT		0b00000110
#define NINE_BIT		7
/*Speed*/
#define NORMAL_SPEED 1
#define DOUBLE_SPEED 2

/*Baud rate*/
#define RATE_2400		2400
#define RATE_4800       4800
#define RATE_9600       9600
#define RATE_14400      14400
#define RATE_19200      19200
#define RATE_28800      28800
#define RATE_38400      38400
#define RATE_57600      57600
#define RATE_76800      76800
#define RATE_115200     115200
#define RATE_230400     230400
#define RATE_250000     250000

#define USART_TIMEOUT	50000
#define IDLE			1
#define BUSY			2

#define SEND_CHAR		1
#define	SEND_STRING		2
#define RECEIVE_CHAR	1
#define	RECEIVE_STRING	2

#endif /* COTS_1_MCAL_7__USART_USART_PRIVATE_H_ */
