/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: alaqsa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_VidLatch(void);
void LCD_VidSendCommand(u8 Copy_U8Command);

void LCD_VidInit(void);
void LCD_VidSendData(s64 Copy_s64Data);
void LCD_VidSendString(u16 *Copy_U8String);
//void LCD_VidSendInt(s64 Copy_U8Int);
void LCD_VidSendFloat(u16 Copy_U8Float);

void LCD_VidGoto(u8 Copy_U8Row,u8 Copy_U8Column);

void LCD_VidNewPattern();

void LCD_CLEAR();
void LCD_VidSendInt(s64 Copy_s64Integer);

#endif /* LCD_INTERFACE_H_ */
