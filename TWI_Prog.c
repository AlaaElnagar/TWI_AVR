/*

 * TWI_Prog.c

 *
 *  Created on: 18/11/2020
 *      Author: Alaa Elnagar
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrorMessage.h"
#include "DIO_reference.h"
#include "TWI_Private.h"

#include "TWI_Config.h"





/************************************************************************************************
 [Function Name]   TWI_VidMasterInit

 [Description]		Function used to give specific SCL specific prescalling and address

 	 	 	 	 	 -Prescaling by

 	 	 	 	 	 	 		PrescalerOne
 	 	 	 	 	 	 		PrescalerFour
 	 	 	 	 	 	 		PrescalerSixteen
                            	PrescalerSixtyFour

                     -setting Master address

								 Address_1_Set
								 Address_2_Set
								  .UPTO
								 Address_127_Set

 [Args]				prescaller_enuState Copy_enuprescaler
  	 	 	 	 	TWI_enuAddress Copy_enupAddress

 [in]				 Copy_enuprescaler
 	 	 	 	 	 Copy_enupAddress

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/



void TWI_VidMasterInit( prescaller_enuState Copy_enuprescaler , TWI_enuAddress Copy_enupAddress ){

	/*variable to generate the power according to TWDR Equation*/
	u8 Local_U8_Power=4;
	/*Setting master address */
	TWAR = Copy_enupAddress<<1;


	/*setting SCL working frequancy in TWDR register*/
	switch ( Copy_enuprescaler){

	case PrescalerOne :

		TWBR=((F_CPU_AVR/F_SCL)-16)/2*4;
		PRESCALER_ONE;
		break ;

	case PrescalerFour :
		/*Generating the prescaller power */
		for (u8 i=0 ; i<PrescalerFour ; i++ ){
			Local_U8_Power*=Local_U8_Power;
		}
		TWBR=((F_CPU_AVR/F_SCL)-16)/(2*Local_U8_Power);
		PRESCALER_FOUR;
		break ;
	case PrescalerSixteen :
		for (u8 i=0 ; i<PrescalerSixteen ; i++ ){
			Local_U8_Power*=Local_U8_Power;
		}
		TWBR=((F_CPU_AVR/F_SCL)-16)/(2*Local_U8_Power);
		PRESCALER_SIXTEEN ;
		break ;
	case PrescalerSixtyFour :

		for (u8 i=0 ; i<PrescalerSixtyFour ; i++ ){
			Local_U8_Power*=Local_U8_Power;
		}

		TWBR=((F_CPU_AVR/F_SCL)-16)/(2*Local_U8_Power);
		PRESCALER_SIXTYFOUR;
		break ;
	}

	ENABLE_TWI;  //Enable I2c
	EN_ACK;

}


/************************************************************************************************
 [Function Name]    TWI_VidSlvInit

 [Description]		Function used to intialize the slave by

 	 	 	 	 	 -Giveing Specific address

 	 	 	 	 	 	 		 Address_1_Set
 	 	 	 	 	 	 		 Address_2_Set
 	 	 	 	 	 	 		  .UPTO
                            	 Address_127_Set

                     -Enable TWI in the slave
					-the function ACK is enabled





 [Args]				prescaller_enuState Copy_enuprescaler


 [in]				 Copy_enuprescaler


 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/



void TWI_VidSlaveInit(TWI_enuAddress Copy_enuAddress ){



	TWAR = Copy_enuAddress<<1;
	ENABLE_TWI;  //Enable I2c
	EN_ACK	;

}



/************************************************************************************************
 [Function Name]     TWI_VidMasterStart

 [Description]		Function used to Start the communication

 	 	 	 	 	 -option of status code checking




 [Args]				 None


 [in]				 None


 [out]			MS_enuState

 [in/out]			None


 [Returns]			Enu_messeage

 * ********************************************************************************************/



Enu_messeage TWI_VidMasterStart(){
	/*master start enum state retun ok or nok*/
	Enu_messeage MS_enuState ;

	MS_enuState=TWI_MStart_nok;
	 /*start by reciving no value from the bus ehile the scl is high*/
	 START_COMMUNICATION;
	 /*clearing the starting ok flag */
	 CLEAR_FLAG;
	 /*wait untill the flag reset */
	 DELAY_UNTIL_FLAG_RESET;
/*checking status code for successfull start*/
	 if (   (TWSR_STATE) == M_START ){
			MS_enuState=TWI_MStart_ok;}

return MS_enuState ;

}

/*start but with different status code*/

Enu_messeage TWI_VidRepeatStart(){

	/*master repeeated start enum state retun ok or nok*/
	Enu_messeage MS_enuState ;

	MS_enuState=TWI_M_Restart_Nok;
	/*start by recieving no value from the bus while the SCL is high*/
	START_COMMUNICATION;
	/*clearing the starting ok flag */
	CLEAR_FLAG;
	/*wait untill the flag reset */
	DELAY_UNTIL_FLAG_RESET;
	/*checking status code for successfull start*/
	if (   (TWSR_STATE) == M_RESTART ){
		MS_enuState=TWI_M_Restart_Ok;}

	return MS_enuState ;

}



void TWI_VidEnableInterrupt(){

	TWCR |= (1<<TWIE_BIT_TWCR);
}

void TWI_VidDisableInterrupt(){

	TWCR |= (0<<TWIE_BIT_TWCR);
}


/************************************************************************************************
 [Function Name]    TWI_VidSendSlaveAddress with write

 [Description]		Function used to send address to select slave by

 	 	 	 	 	 -sending Specific address
 	 	 	 	 	 -prepeare this address to write over it

 	 	 	 	 	 	 		 Address_1_Set
 	 	 	 	 	 	 		 Address_2_Set
 	 	 	 	 	 	 		  .UPTO
                            	 Address_127_Set

 	 	 	 	 	 -Wait for TWINT Flag set.
 	 	 	 	 	 -check status code



 [Args]				-TWI_enuAddress



 [in]				-Copy_enuAddress


 [out]				MS_enuState

 [in/out]			None


 [Returns]			Enu_messeage

 * **************************************************************************************/

/*master functions*/

Enu_messeage TWI_VidSendSlaveAddressWithWrite(TWI_enuAddress Copy_enuAddress){

	Enu_messeage MS_enuState ;

	MS_enuState=TWI_MS_SLA_w_Nok;

	TWDR = (Copy_enuAddress<<1);//Set Slave Addr
	/*Disable start bit */
	Dis_S_COMMUNICATION;
	CLEAR_FLAG;
	/*wait untill the flag reset */
	DELAY_UNTIL_FLAG_RESET;

	if (   (TWSR_STATE) == (M_SLA_W_ACK ||M_SLA_W_NACK)){
		MS_enuState=TWI_MS_SLA_w_Ok;}

	return MS_enuState ;


}


/************************************************************************************************
 [Function Name]    TWI_VidSendSlaveAddress with read

 [Description]		Function used to send address to select slave by

 	 	 	 	 	 -sending Specific address
 	 	 	 	 	 -prepeare this address to Read from

 	 	 	 	 	 	 		 Address_1_Set
 	 	 	 	 	 	 		 Address_2_Set
 	 	 	 	 	 	 		  .UPTO
                            	 Address_127_Set

 	 	 	 	 	 -Wait for TWINT Flag set.
 	 	 	 	 	 -check status code



 [Args]				-TWI_enuAddress



 [in]				-Copy_enuAddress


 [out]				MS_enuState

 [in/out]			None


 [Returns]			Enu_messeage

 * **************************************************************************************/


Enu_messeage TWI_VidSendSlaveAddressWithRead(TWI_enuAddress Copy_enuAddress){

	Enu_messeage MS_enuState ;

		MS_enuState=TWI_MS_SLA_R_Nok;

		TWDR = ((Copy_enuAddress<<1)|1);//Set Slave Address
		/*Disable start bit */
		Dis_S_COMMUNICATION;
		CLEAR_FLAG;
		/*wait untill the flag reset */
		DELAY_UNTIL_FLAG_RESET;

		if (   (TWSR_STATE) == (M_SLA_R_ACK||M_SLA_R_NACK)){
			MS_enuState=TWI_MS_SLA_R_Ok;}

		return MS_enuState ;



}


/************************************************************************************************
 [Function Name]   TWI_VidMasterSendData

 [Description]		Function used to send Data from master to slave


 	 	 	 	 	 -check status code



 [Args]				-u8



 [in]				-Copy_U8Data


 [out]				MS_enuState

 [in/out]			None


 [Returns]			Enu_messeage

 * **************************************************************************************/
Enu_messeage TWI_VidMasterSendData(u8 Copy_U8Data){

	Enu_messeage MS_enuState ;

		MS_enuState=TWI_MS_Data_Nok;

		TWDR = (Copy_U8Data);
		/*Disable start bit */
		CLEAR_FLAG;
		/*wait untill the flag reset */
		DELAY_UNTIL_FLAG_RESET;

		if (   (TWSR_STATE) == (MT_DATA_ACK ||MT_DATA_NACK)){
			MS_enuState=TWI_MS_Data_Ok;}

		return MS_enuState ;


}



/************************************************************************************************
 [Function Name]     TWI_S_CheckOwnAddr_RW

 [Description]		Function used to check if slave address is called



 	 	 	 	 	 -check status code read or write address



 [Args]				-None



 [in]				-None


 [out]				MS_enuState

 [in/out]


 [Returns]			Enu_messeage

 * **************************************************************************************/

Enu_messeage TWI_S_CheckOwnAddr_RW(void){

	SET_BIT(TWCR,6);//Enable Ack
	Enu_messeage MS_enuState ;

	MS_enuState=TWI_SC_Add_Nok ;

	CLEAR_FLAG;

	DELAY_UNTIL_FLAG_RESET;
	if (   (TWSR_STATE) == (S_SLA_W_ACK	 || S_SLA_R_ACK	)){
		MS_enuState=TWI_SR_Data_Ok;}

	return MS_enuState ;



}





/************************************************************************************************
 [Function Name]    TWI_VidMasterReciveData

 [Description]		Function used to send Data from master to slave


 	 	 	 	 	 -check status code



 [Args]				-u8



 [in]				-Copy_U8PReciver


 [out]				MS_enuState

 [in/out]			Copy_U8PReciver


 [Returns]			Enu_messeage

 * **************************************************************************************/
Enu_messeage TWI_VidMasterReciveData(u8 *Copy_U8PReciver){


	Enu_messeage MS_enuState ;

			MS_enuState=TWI_MR_Data_Nok;

			/*Disable start bit */
			CLEAR_FLAG;
			/*wait untill the flag reset */
			DELAY_UNTIL_FLAG_RESET;

			if (   (TWSR_STATE) == (MR_DATA_ACK ||MR_DATA_NACK)){
				MS_enuState=TWI_MR_Data_Ok;}

			*Copy_U8PReciver =TWDR;

			return MS_enuState ;


}


/*second code for slave */


/************************************************************************************************
 [Function Name]     TWI_VidSlaveSendData

 [Description]		Function used to send Data from   slave to master


 	 	 	 	 	 -check status code



 [Args]				-u8



 [in]				-Copy_U8PReciver


 [out]				MS_enuState

 [in/out]


 [Returns]			Enu_messeage

 * **************************************************************************************/

Enu_messeage TWI_VidSlaveSendData(u8 Copy_U8Data){

	Enu_messeage MS_enuState ;

		MS_enuState=TWI_SS_Data_Nok;

		TWDR = (Copy_U8Data);
		/*Disable start bit */
		CLEAR_FLAG;
		/*wait untill the flag reset */
		DELAY_UNTIL_FLAG_RESET;

		if (   (TWSR_STATE) == (ST_DATA_ACK ||ST_DATA_NACK)){
			MS_enuState=TWI_SS_Data_Ok;}

		return MS_enuState ;


}


/************************************************************************************************
 [Function Name]     TWI_VidSlaveSendData

 [Description]		Function used to Rcive Data from  master to specific slave


 	 	 	 	 	 -check status code



 [Args]				-u8



 [in]				-Copy_U8PReciver


 [out]				MS_enuState

 [in/out]			Copy_U8PReciver


 [Returns]			Enu_messeage

 * **************************************************************************************/



Enu_messeage TWI_VidSlaveRecive(u8 *Copy_U8PReciver){

	Enu_messeage MS_enuState ;

				MS_enuState=TWI_SR_Data_Nok;

				CLEAR_FLAG;
				/*wait untill the flag reset */
				DELAY_UNTIL_FLAG_RESET;

				if (   (TWSR_STATE) == (SR_DATA_ACK	 ||SR_DATA_NACK)){
					MS_enuState=TWI_SR_Data_Ok;}

				*Copy_U8PReciver =TWDR;

				return MS_enuState ;

}


/************************************************************************************************
 [Function Name]     I2C_VidStop

 [Description]		Function used to stop the communication





 [Args]				-None



 [in]				-None

 [out]				-None

 [in/out]			-None


 [Returns]			-None

 * **************************************************************************************/

void TWI_VidStop(void)
{
	STOP_COMMUNICATION;

	CLEAR_FLAG;

	DELAY_UNTIL_FLAG_RESET;
}
