/*
 * TWI_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: alaqsa
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_


/**/



#define TWBR_VALUE

/*TWI Data Register – TWDR*/
#define TWDR *((volatile u8*)0x23)
/* (Slave) Address Register – TWAR*/
#define TWAR *((volatile u8*)0x22)

#define TWSR *((volatile u8*)0x21)

/*/*• Bits [7:0] – TWI Bit Rate Register  in which we  define speed         */
#define TWBR *((volatile u8*)0x20)

/*TWI Control Register –TWCR*/
#define TWCR *((volatile u8*)0x56)





  	  	  	  	  	  	  	  	  /*TWI Control Register –TWCR     */

/*• Bit 7 – TWINT: TWI Interrupt Flag      */
#define     TWINT_BIT_TWCR  													7
/*• Bit 6 – TWEA: TWI Enable Acknowledge Bit*/
#define     TWEA_BIT_TWCR   													6
/*• Bit 5 – TWSTA: TWI START Condition Bit*/
#define     TWSTA_BIT_TWCR    													5
/*• Bit 4 – TWSTO: TWI STOP Condition Bit*/
#define     TWSTO_BIT_TWCR    													4
/*• Bit 3 – TWWC: TWI Write Collision Flag*/
#define     TWWC_BIT_TWCR    													3
/*• Bit 2 – TWEN: TWI Enable Bit*/
#define     TWEN_BIT_TWCR    													2
/*• Bit 1 – Reserved Bit*/
 /*• Bit 0 – TWIE: TWI Interrupt Enable*/
#define     TWIE_BIT_TWCR    													0



							/*TWI Status Register –TWSR*/

/*• Bits [7:3] – TWS: TWI Status*/
#define     TWS7_BIT_TWSR 												7
#define     TWS6_BIT_TWSR 												6
#define     TWS5_BIT_TWSR 									  			5
#define     TWS4_BIT_TWSR 												4
#define    	TWS3_BIT_TWSR 							    				3

/*• Bit 2 – Reserved Bit*/
/*• Bits [1:0] – TWPS: TWI Prescaler Bits*/
#define     TWPS1_BIT_TWSR												1
#define     TWPS0_BIT_TWSR 												0



/* (Slave) Address Register – TWAR*/

/*• Bits 7..1 – TWA: TWI (Slave) Address Register*/

/*• Bit 0 – TWGCE: TWI General Call Recognition Enable Bit*/
#define     TWGCE_BIT_TWAR 												 0




/*Prescaller value */


#define PRESCALER_ONE   CLEAR_BIT(TWSR ,TWPS0_BIT_TWSR);\
                        CLEAR_BIT(TWSR , TWPS1_BIT_TWSR)

#define PRESCALER_FOUR     SET_BIT(TWSR ,TWPS0_BIT_TWSR);\
                           CLEAR_BIT(TWSR , TWPS1_BIT_TWSR)


#define PRESCALER_SIXTEEN  CLEAR_BIT(TWSR ,TWPS0_BIT_TWSR);\
                           SET_BIT(TWSR , TWPS1_BIT_TWSR)


#define PRESCALER_SIXTYFOUR   SET_BIT(TWSR ,TWPS0_BIT_TWSR);\
                              SET_BIT(TWSR , TWPS1_BIT_TWSR)


/*intialization of registers bits*/

#define ENABLE_TWI   				SET_BIT(TWCR,TWEN_BIT_TWCR) //ENABLE
#define START_COMMUNICATION 		SET_BIT(TWCR,TWSTA_BIT_TWCR)//Set Start
#define STOP_COMMUNICATION			CLEAR_BIT(TWCR,TWSTO_BIT_TWCR)
#define Dis_S_COMMUNICATION 		CLEAR_BIT(TWCR,TWSTA_BIT_TWCR)//Set Start

#define CLEAR_FLAG			     	SET_BIT(TWCR,TWINT_BIT_TWCR)//Clear Flag
#define DELAY_UNTIL_FLAG_RESET 	    while((GET_BIT(TWCR,7))==0)
#define TWSR_STATE					 TWSR>>3
#define EN_ACK						SET_BIT(TWCR,TWEA_BIT_TWCR) //ENABLE ACK
#define Dis_ACK						CLEAR_BIT(TWCR,TWEA_BIT_TWCR) //Diasable ACK

/*Status Codes for Master Transmitter Mode*/

/*A START condition has been transmitted*/
#define M_START    										 							           0X08
/*A repeated START condition has been transmitted*/
#define M_RESTART  		    							 									   0X10
/*SLA+W has been transmitted; ACK has been received*/
#define M_SLA_W_ACK     								                                       0X18
/*SLA+W has been transmitted; NOT ACK has been received*/
#define M_SLA_W_NACK    								                                       0X20
/*Data byte has been transmitted; ACK has been received*/
#define MT_DATA_ACK    									   									   0X28
/*Data byte has been transmitted;NOT ACK has been received*/
#define MT_DATA_NACK   		  																   0X30
/*Arbitration lost in SLA+W or data bytes*/
#define M_ARBITR_LOST 	       						    									   0X38


/*Status Codes for Master Receiver Mode*/

 /*SLA+R has been transmitted; ACK has been received*/
#define M_SLA_R_ACK     			    														0X40
/*SLA+R has been transmitted;NOT ACK has been received*/
#define M_SLA_R_NACK    			    														0X48
/*Data byte has been received;ACK has been returned*/
#define MR_DATA_ACK              	    														0X50
/*Data byte has been received;NOT ACK has been returned*/
#define MR_DATA_NACK             	 														    0X58




/*Status Codes for Slave Receiver Mode*/


/*Own SLA+W has been received;ACK has been returned */
#define S_SLA_W_ACK     			 															 0X60
/*Arbitration lost in SLA+R/W as master; own SLA+W has been received; ACK has been returned */
#define S_AR_LOST_SLA_W         	    	 													 0X68
/*General call address has been received; ACK has been returned*/
#define SR_ADDR_G_CALL		  																	 0X70
/*Arbitration lost in SLA+R/W as master; General call address has been received; ACK has been returned*/
#define S_AR_LOST_G_CALL					 													 0X78
/*Previously addressed with own SLA+W; data has been received;ACK has been returned*/
#define SR_DATA_ACK																				 0X80
/*Data byte has been received;NOT ACK has been returned*/
#define SR_DATA_NACK																			 0X88
/*Previously addressed with general call; data has been received; ACK has been returned*/
#define SR_DATA_ACK_G_CALL		  																 0X90
/*Previously addressed with general call; data has been received; NOT ACK has been returned*/
#define SR_DATA_NACK_G_CALL		   	 															 0X98
/*A STOP condition or repeated START condition has been received while still addressed as slave*/
#define SR_STOP			 					 	 												 0XA0


/*Status Codes for Slave Transmitter Mode*/

/*Own SLA+R has been received; ACK has been returned*/
#define S_SLA_R_ACK			 		 														     0XA8
/*Arbitration lost in SLA+R/W as master; own SLA+R has been received; ACK has been returned*/
#define S_AR_LOST_SLA_R	 		 																 0XB0
/*Data byte in TWDR has been transmitted; ACK has been received*/
#define ST_DATA_ACK		 																		 0XB8
/*Data byte in TWDR has been transmitted; NOT ACK has been received*/
#define ST_DATA_NACK		 																	 0XC0
/*Last data byte in TWDR has been transmitted (TWEA = “0”); ACK has been received*/
#define  ST_LAST_DATA_ACK																		 0XC8

/*Miscellaneous States*/

/*indicates that no relevant information is available because the TWINT Flag is not set.
This occurs between other states, and when the TWI is not involved in a serial transfer.*/

#define TWI_UNDEFINED					  														 0XF8
/*Bus error due to an illegal START or STOP condition*/
#define BUS_ERROR    					  														 0X00








#endif /* TWI_PRIVATE_H_ */
