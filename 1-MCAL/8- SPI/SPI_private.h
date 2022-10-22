/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	SPI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_8__SPI_SPI_PRIVATE_H_
#define COTS_1_MCAL_8__SPI_SPI_PRIVATE_H_

/*Data Order*/
#define LSB_FIRST		1
#define MSB_FIRST		2

/*Master/Slave Select*/
#define MASTER			1
#define SLAVE 			2

/*Clock Polarity*/
#define RAISING_LEADING	1
#define FALLING_LEADING	2

/*Clock Phase*/
#define LEADING_SAMPLE	1
#define LEADING_SETUP	2

/*SPI Speed*/
#define NORMAL_SPEED	1
#define DOUBLE_SPEED	2

/*Pre_Scaler*/
#define PRE_SCALER_MASK	0b11111100
#define DIVIDE_BY4		0
#define DIVIDE_BY16 	1
#define DIVIDE_BY64 	2
#define DIVIDE_BY128	3
#define DIVIDE_BY2  	0
#define DIVIDE_BY8  	1
#define DIVIDE_BY32 	2
#define DIVIDE_BY464	3

#define SPI_TIMEOUT		50000

#define IDEL			1
#define BUSY			2
#endif /* COTS_1_MCAL_8__SPI_SPI_PRIVATE_H_ */
