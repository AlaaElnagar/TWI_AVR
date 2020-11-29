/*
 * TWI_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: alaqsa
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_



void TWI_VidMasterInit( prescaller_enuState Copy_enuprescaler , TWI_enuAddress Copy_enupAddress );


	void TWI_VidSlaveInit(TWI_enuAddress Copy_enuAddress );


		Enu_messeage TWI_VidMasterStart();


		/*start but with different status code*/

		Enu_messeage TWI_VidRepeatStart();


			void TWI_VidEnableInterrupt();


		   void TWI_VidDisableInterrupt();


		   Enu_messeage TWI_VidSendSlaveAddressWithWrite(TWI_enuAddress Copy_enuAddress);



		Enu_messeage TWI_VidSendSlaveAddressWithRead(TWI_enuAddress Copy_enuAddress);


			Enu_messeage TWI_VidMasterSendData(u8 Copy_U8Data);


				Enu_messeage TWI_S_CheckOwnAddr_RW(void);



			Enu_messeage TWI_VidMasterReciveData(u8 *Copy_U8PReciver);



/*second code for slave */


					Enu_messeage TWI_VidSlaveSendData(u8 Copy_U8Data);




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



						Enu_messeage TWI_VidSlaveRecive(u8 *Copy_U8PReciver);




/************************************************************************************************
					 [Function Name]     I2C_VidStop

					 [Description]		Function used to stop the communication





					 [Args]				-None



					 [in]				-None

					 [out]				-None

					 [in/out]			-None


					 [Returns]			-None

 * **************************************************************************************/

							void TWI_VidStop(void);

#endif /* TWI_INTERFACE_H_ */
