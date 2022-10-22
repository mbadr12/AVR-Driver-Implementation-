/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	SPI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_8__SPI_SPI_REGISTER_H_
#define COTS_1_MCAL_8__SPI_SPI_REGISTER_H_

#define SPDR		*((volatile u8*) 0x2f)
#define SPSR		*((volatile u8*) 0x2e)
#define SPSR_SPIF	7
#define SPSR_WCOL	6
#define SPSR_SPI2X	0

#define SPCR		*((volatile u8*) 0x2d)
#define SPCR_SPIE	7
#define SPCR_SPE	6
#define SPCR_DORD	5
#define SPCR_MSTR	4
#define SPCR_CPOL	3
#define SPCR_CPHA	2
#define SPCR_SPR1	1
#define SPCR_SPR0	0

#endif /* COTS_1_MCAL_8__SPI_SPI_REGISTER_H_ */
