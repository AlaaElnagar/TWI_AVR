/*
 * main.c
 *
 *  Created on: 29/11/2020
 *      Author: AlaaElnagar
 */
#include "ErrorMessage.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reference.h"
#include "TWI_Interface.h"
#include<util/delay.h>
#include "LCD_interface.h"
//#define TWSR *((volatile u8*)0x21)


/*
 * the address 0000 000 is reserved for a general call.
 * 1111 xxx
 * after  sending address slave should
 *  acknowledge by pulling SDA low in the ninth SCL
 *(ACK) cycle
 *(ACK)
 *(ACK)
 *When a general call is issued, all slaves should respond by pulling the SDA line low in the ACK
 * When the receiver has
received the last byte, or for some reason cannot receive any more bytes, it should inform the
transmitter by sending a NACK after the final byte.
cycle.
 * */
#define MASTER  0

#define SLAVE   1

#define MAINSELECT MASTER




#if MAINSELECT == MASTER


int main(){

	LCD_VidInit();

	LCD_VidSendData('a');


	TWI_VidMasterInit(PrescalerSixtyFour , Address_1_Set );


	TWI_VidMasterStart();

	TWI_VidSendSlaveAddressWithWrite(Address_2_Set);

    TWI_VidMasterSendData(10);

    TWI_VidStop();

	//I2C_VidStop();

	_delay_ms(2000);

	TWI_VidRepeatStart();

	TWI_VidSendSlaveAddressWithWrite(Address_2_Set);

	TWI_VidMasterSendData(20);

	TWI_VidStop();


	//DIO_VidSetPinValue(1,0,1);


return 0 ;

}






#elif MAINSELECT == SLAVE



int main (){

	LCD_VidInit();

	TWI_VidSlaveInit(Address_2_Set);

	u8 x =0 ;

	while(1){

		TWI_S_CheckOwnAddr_RW();

		TWI_VidSlaveRecive(&x);

		LCD_VidSendInt(x);
	}
}

#endif
