/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	SPI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_8__SPI_SPI_CONFIG_H_
#define COTS_1_MCAL_8__SPI_SPI_CONFIG_H_

/*choose Data Order:
 * 1- LSB_FIRST
 * 2- MSB_FIRST*/
#define DATA_ORDER LSB_FIRST

/*Choose Master/Slave Select:
 * 1-MASTER
 * 2-SLAVE*/
#define MASTER_SLAVE_SELECT MASTER

/*Choose Clock Polarity:
 * 1-RAISING_LEADING
 * 2-FALLING_LEADING*/
#define CLK_POLARITY RAISING_LEADING

/*Choose Clock Phase
 * 1-LEADING_SAMPLE
 * 2-LEADING_SETUP*/
#define CLK_PHASE LEADING_SAMPLE

/*Choose SPI Speed
 * 1-NORMAL_SPEED
 * 2-DOUBLE_SPEED*/
#define SPI_SPEED NORMAL_SPEED

/*Choose PreScaler
 * for Normal Speed:
 * 1- DIVIDE_BY4
 * 2- DIVIDE_BY16
 * 3- DIVIDE_BY64
 * 4- DIVIDE_BY128
 * for Double Speed
 * 1- DIVIDE_BY2
 * 2- DIVIDE_BY8
 * 3- DIVIDE_BY32
 * 4- DIVIDE_BY464*/
#define PRE_SCALER	DIVIDE_BY16

#endif /* COTS_1_MCAL_8__SPI_SPI_CONFIG_H_ */
