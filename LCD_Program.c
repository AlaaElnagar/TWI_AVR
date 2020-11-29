/*
 * LCD_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: alaqsa
 */

#include "STD_TYPES.h"
#include "DIO_reference.h"
#include "DIO_Configure.h"

#include "LCD_Configaration.h"
#include "LCD_interface.h"
#include <util/delay.h>



/************************************************************************************************
 [Function Name]    LCD_VidLatch

 [Description]		Function used to Enable LCD internal circuit to
 	 	 	 	 	 -receive data by setting RS pin to High rising  edge
 	 	 	 	 	 -write   data by setting RS pin to Low  falling edge

 [Args]				void

 [in]				void

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/


void LCD_VidLatch(void){

/*Set EN pin to change from high to low to as falling edge to allow lcd recive data */

DIO_VidSetPinDirection(LCD_E_PORT,LCD_E_PIN,OUTPUT);

/*Set EN PIN to ONE as instruction READ operation */

DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,ONE);
_delay_ms(1);
/*Set EN PIN to ZERRO as instruction WRITE operation */
DIO_VidSetPinValue(LCD_E_PORT, LCD_E_PIN,ZERO);
_delay_ms(1);


}


/************************************************************************************************
 [Function Name]    LCD_VidSendCommand

 [Description]		Function used to send command to lcd internal circuit
 	 	 	 	 	 -
 	 	 	 	 	 -

 [Args]				Copy_U8Command

 [in]				Copy_U8Command : a char which hold lcd command

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/

void LCD_VidSendCommand(u8 Copy_U8Command){
	/*Set RS pin as output */
DIO_VidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
/*Set RW pin as output */
DIO_VidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);

/*Set RS to zerro as instruction write operation */
DIO_VidSetPinValue(LCD_RS_PORT , LCD_RS_PIN,ZERO);
/*Set RW to zerro as instruction write operation */
DIO_VidSetPinValue(LCD_RW_PORT , LCD_RW_PIN,ZERO);


/*Setup of lcd pins directions as output*/

DIO_VidSetPinDirection(LCD_D0_PIN_PORT,LCD_D0_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D1_PIN_PORT,LCD_D1_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D2_PIN_PORT,LCD_D2_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D3_PIN_PORT,LCD_D3_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D4_PIN_PORT,LCD_D4_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D5_PIN_PORT,LCD_D5_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D6_PIN_PORT,LCD_D6_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D7_PIN_PORT,LCD_D7_PIN,OUTPUT);

/*Sending the command to the Pins*/

DIO_VidSetPinValue( LCD_D0_PIN_PORT   ,  LCD_D0_PIN ,    ( Copy_U8Command>>ZERO ) &ONE     );
DIO_VidSetPinValue( LCD_D1_PIN_PORT   ,  LCD_D1_PIN ,    ( Copy_U8Command>>ONE  ) &ONE	   );
DIO_VidSetPinValue( LCD_D2_PIN_PORT   ,  LCD_D2_PIN ,    ( Copy_U8Command>>TWO  ) &ONE	   );
DIO_VidSetPinValue( LCD_D3_PIN_PORT   ,  LCD_D3_PIN ,    ( Copy_U8Command>>THREE) &ONE	   );
DIO_VidSetPinValue( LCD_D4_PIN_PORT   ,  LCD_D4_PIN ,    ( Copy_U8Command>>FOUR ) &ONE	   );
DIO_VidSetPinValue( LCD_D5_PIN_PORT   ,  LCD_D5_PIN ,    ( Copy_U8Command>>FIVE ) &ONE	   );
DIO_VidSetPinValue( LCD_D6_PIN_PORT   ,  LCD_D6_PIN ,    ( Copy_U8Command>>SIX  ) &ONE	   );
DIO_VidSetPinValue( LCD_D7_PIN_PORT   ,  LCD_D7_PIN ,    ( Copy_U8Command>>SEVEN) &ONE	   );
/*Enable lcd to recive command*/
LCD_VidLatch();
}

/************************************************************************************************
 [Function Name]    LCD_VidSendData

 [Description]		Function used to send Data to lcd internal circuit
 	 	 	 	 	 -send the command to all of lcd pins
 	 	 	 	 	 -feature of  to insertion lcd pins at any ports

 [Args]				Copy_U8Data

 [in]				Copy_U8Data : a char which hold lcd Data

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/

void LCD_VidSendData(s64 Copy_s64Data){
	/*Set RS pin as output */
DIO_VidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
/*Set RW pin as output */

DIO_VidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);

/*Set RS to ONE as DATA write operation */
DIO_VidSetPinValue(LCD_RS_PORT , LCD_RS_PIN,ONE);
/*Set RW to ZERRO as DATA write operation */
DIO_VidSetPinValue(LCD_RW_PORT , LCD_RW_PIN,ZERO);

/*Setup of lcd pins directions as output*/

DIO_VidSetPinDirection(LCD_D0_PIN_PORT,LCD_D0_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D1_PIN_PORT,LCD_D1_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D2_PIN_PORT,LCD_D2_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D3_PIN_PORT,LCD_D3_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D4_PIN_PORT,LCD_D4_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D5_PIN_PORT,LCD_D5_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D6_PIN_PORT,LCD_D6_PIN,OUTPUT);
DIO_VidSetPinDirection(LCD_D7_PIN_PORT,LCD_D7_PIN,OUTPUT);

/*Sending the command to the Pins*/


DIO_VidSetPinValue(  LCD_D0_PIN_PORT  ,   LCD_D0_PIN ,    ( Copy_s64Data>>ZERO )   &ONE     );
DIO_VidSetPinValue(  LCD_D1_PIN_PORT  ,   LCD_D1_PIN ,    ( Copy_s64Data>>ONE  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D2_PIN_PORT  ,   LCD_D2_PIN ,    ( Copy_s64Data>>TWO  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D3_PIN_PORT  ,   LCD_D3_PIN ,    ( Copy_s64Data>>THREE)   &ONE	   );
DIO_VidSetPinValue(  LCD_D4_PIN_PORT  ,   LCD_D4_PIN ,    ( Copy_s64Data>>FOUR )   &ONE	   );
DIO_VidSetPinValue(  LCD_D5_PIN_PORT  ,   LCD_D5_PIN ,    ( Copy_s64Data>>FIVE )   &ONE	   );
DIO_VidSetPinValue(  LCD_D6_PIN_PORT  ,   LCD_D6_PIN ,    ( Copy_s64Data>>SIX  )   &ONE	   );
DIO_VidSetPinValue(  LCD_D7_PIN_PORT  ,   LCD_D7_PIN ,    ( Copy_s64Data>>SEVEN)   &ONE	   );
/*Enable LCD to receive Data*/
LCD_VidLatch();


}


/************************************************************************************************
 [Function Name]    LCD_VidInit

 [Description]		Function used to intialize internal circuit and make LCD ready
 	 	 	 	 	 -feature of 8BIT mode
 	 	 	 	 	 -feature of 4BIT mode

 [Args]				None

 [in]				None

 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/


void LCD_VidInit(void){

_delay_ms(50);

/*set the function set  0  0  1  DL  N  F  X  X
 * 		DL-->> Data line 						1 for 8bit Mode   		0 for 4 bit Mode
 * 		N -->>Number of display lines			1 for 2 line			0 for 1 line
 * 		F -->>Font 								1 for 5*11 dots         0 for 5*8 dots
 */

LCD_VidSendCommand(0b00111000);

_delay_ms(1);

/*set Display on off control   0  0  0  0  1  D  C  B
 * 		D-->> Set on off entire display 		1 for Display on   		0 for Display off
 * 		C-->>Set cursor on off  display			1 for cursor  on		0 for cursor off
 * 		B-->>blinking of cursor position 		1 for Blinking          0 for None
 */

LCD_VidSendCommand(0b00001100);
_delay_ms(1);

/*Clear display*/
LCD_VidSendCommand(0b00000001);

_delay_ms(2);

/*Entry Mode Set   0  0  0  0  0  1  I/D  SH
 * 	I/D-->> allow movement through DDRAM addresses when character code is written or read
 * 						1 for address increase
 * 								The cursor blink mov to right I/D 1
 * 						0 for address decrease
 * 								The cursor blink mov to left  I/D 0
 *
 * 	SH-->>shift display
 *
 * 						1 for <<Screen>>  shift to the right
 * 						0 for <<Screen>> shift to the left
 *
 */

LCD_VidSendCommand(0b00000110);


}





/************************************************************************************************
 [Function Name]    LCD_VidGoto

 [Description]		Function used to mov to any where in the LCD



 [Args]				Copy_U8Row    Copy_U8Column

 [in]				-Copy_U8Row  zerro for selction of first row
 	 	 	 	 				 one  for selection of second row
 	 	 	 	 	-Copy_U8Column 0 start at first column
 	 	 	 	 				   16 mov to last LCD column


 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/

void LCD_VidGoto(u8 Copy_U8Row,u8 Copy_U8Column){
	/*(Set DDRAM address)      1  AC6 AC5 AC4 AC3 AC2 AC1 AC0
	 *
	 *AC is the address counter which looks at DDRAM
	 *
	 *
	 * */
	u8 Local_Copy_u8ACC=Copy_U8Column;

	if (Copy_U8Row==0){

	LCD_VidSendCommand(0b10000000+Local_Copy_u8ACC);
	}
	else if (Copy_U8Row==1){
	LCD_VidSendCommand(0b10000000+64+Local_Copy_u8ACC);

	}


}


/************************************************************************************************
 [Function Name]    LCD_VidSendString

 [Description]		Function used to print string  in the LCD



 [Args]				Copy_U8String

 [in]				-Copy_U8String is a pointer to char which points to array to access it



 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/


void LCD_VidSendString(u16 *Copy_U8String){

while (*Copy_U8String){

	LCD_VidSendData(*Copy_U8String);
	Copy_U8String++;
}


/************************************************************************************************
 [Function Name]    LCD_VidSendString

 [Description]		Function used to print string  in the LCD



 [Args]				Copy_U8String

 [in]				-Copy_U8String is a pointer to char which points to array to access it



 [out]				None

 [in/out]			None


 [Returns]			None

 * ********************************************************************************************/



}


void LCD_VidNewPattern(){

	u8 Custom_Char[] = {
	  0b01110,0b01110,0b00100,0b01110,0b10101,0b00100,0b01010,0b01010, // Code for CGRAM memory space 1
	  0b00000,0b00000,0b01010,0b00100,0b00100,0b10001,0b01110,0b00000, // Code for CGRAM memory space 2
	  0b00100,0b01110,0b11111,0b11111,0b01110,0b01110,0b01010,0b01010, // Code for CGRAM memory space 3
	  0b01110,0b10001,0b10001,0b11111,0b11011,0b11011,0b11111,0b00000, // Code for CGRAM memory space 4
	  0b01110,0b10000,0b10000,0b11111,0b11011,0b11011,0b11111,0b00000, // Code for CGRAM memory space 5
	  0b00000,0b10001,0b01010,0b10001,0b00100,0b01110,0b10001,0b00000, // Code for CGRAM memory space 6
	  0b00000,0b00000,0b01010,0b10101,0b10001,0b01110,0b00100,0b00000, // Code for CGRAM memory space 7
	  0b11111,0b11111,0b10101,0b11011,0b11011,0b11111,0b10001,0b11111  // Code for CGRAM memory space 8
	};



	/* Set CGRAM address to move Acc address pointer from DDRAM TO CGRAM  */


	/*(Set CGRAMaddress)      0  1 AC5 AC4 AC3 AC2 AC1 AC0
	 *
	 *AC is the address counter which  NOW WILL looks at CGRAM
	 *
	 *
	 * */

	u8 Local_CopyU8ACC=0;   /*point to first address in CGRAM*/
	LCD_VidSendCommand(0b01000000+Local_CopyU8ACC);

	/*Write your data to CGRAM start with first row        */

for (u8 i=0 ; i<63 ; i++){
	LCD_VidSendData(Custom_Char[i]);

}



	/*Set Entry mode set to allow CGRAM Address to be increased automatically    */

	/*Entry Mode Set   0  0  0  0  0  1  I/D  SH
	 * 	I/D-->> allow movement through DDRAM addresses when character code is written or read
	 * 						1 for address increase
	 * 								The cursor blink mov to right I/D 1
	 * 						0 for address decrease
	 * 								The cursor blink mov to left  I/D 0
	 *
	 * 	SH-->>shift display
	 *
	 * 						1 for <<Screen>>  shift to the right
	 * 						0 for <<Screen>> shift to the left
	 *
	 */

	LCD_VidSendCommand(0b00000110);

	/*Set DDRAM ACC to select place to write = GOTO FNCTION   */
	LCD_VidGoto(0,7);


	/*write the pattern address u want to show --->>pattern address start from zerro to 7*/
	for (u8 i=0 ; i<8 ; i++){
	LCD_VidSendData(i);
	}

}







void LCD_CLEAR(){

	LCD_VidSendCommand(0b00000001);


}



void LCD_VidSendInt(s64 Copy_s64Integer){

	//1234
	//65535
	if (!Copy_s64Integer){ LCD_VidSendData('0') ;}

	else{

		s64 Local_Copy_s64Divisor=10000;
		s64 Local_Copy_s64DivResult;
if (Copy_s64Integer<0){LCD_VidSendData('-');Copy_s64Integer*=-1;}

while(Copy_s64Integer){


			while (Copy_s64Integer<Local_Copy_s64Divisor){

				Local_Copy_s64Divisor/=10;
			}

			Local_Copy_s64DivResult=Copy_s64Integer/Local_Copy_s64Divisor;
			LCD_VidSendData('0'+Local_Copy_s64DivResult);
			Copy_s64Integer%=Local_Copy_s64Divisor;
		}
	}
}







































































