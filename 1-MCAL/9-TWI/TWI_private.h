/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TWI 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_9_TWI_TWI_PRIVATE_H_
#define COTS_1_MCAL_9_TWI_TWI_PRIVATE_H_

#define START_ACK				0X08	/*Start has been sent*/
#define REP_START_ACK			0X10	/*Repeated start*/
#define SLAVE_ADD_AND_WR_ACK	0X18	/*Master transmit (Slave Address + Write Request ACK)*/
#define SLAVE_ADD_AND_RD_ACK	0X40    /*Master transmit (Slave Address + Read Request ACK)*/
#define MSTR_WR_BYTE_ACK		0X28    /*Master transmit ACK*/
#define MSTR_RD_BYTE_WITH_ACK	0X50	/*Master Receive data with ACK*/
#define MSTR_RD_BYTE_WITH_NACK	0X58    /*Master Receive data with not ACK*/
#define SLAVE_ADD_RCVD_RD_REQ	0XA8	/*Means that Slave Address is received with Read Request*/
#define SLAVE_ADD_RCVD_WR_REQ	0X60    /*Means that Slave Address is received with Write Request*/
#define SLAVE_DATA_RECEIVED		0X80    /*Means that a byte is received*/
#define SLAVE_BYTE_TRANSMITTED	0XB8    /*Means that the written byte is transmitted*/

#define TWSR_Mask				0b11111000

#endif /* COTS_1_MCAL_9_TWI_TWI_PRIVATE_H_ */
