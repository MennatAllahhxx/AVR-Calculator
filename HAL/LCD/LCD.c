#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD.h"

void LCD_voidInit(void)
{
	DIO_voidSetPortDirection(LCD_DATA_PORT, 0XFF);

	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN, DIO_OUTPUT);

	_delay_ms(35);

	LCD_voidSendCommand(FUNCTION_SET);

	_delay_us(50);

	LCD_voidSendCommand(DISPLAY_ON_OFF);

	_delay_us(50);

	LCD_voidSendCommand(CLEAR);
	_delay_ms(2);
}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, DIO_LOW);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, DIO_LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);

	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, DIO_HIGH);

	_delay_us(1);

	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, DIO_LOW);
}

void LCD_voidSendChar(u8 Copy_u8Char)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RS, DIO_HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, RW, DIO_LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Char);

	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, DIO_HIGH);

	_delay_us(1);

	DIO_voidSetPinValue(LCD_CONTROL_PORT, EN, DIO_LOW);
}
//to send a string
void LCD_voidSendString(u8 *Copy_u8String)
{
	u8 i = 0;
	while (Copy_u8String[i])
		LCD_voidSendChar(Copy_u8String[i++]);
}

void LCD_voidSetLocation(u8 Copy_u8LineNum, u8 Copy_u8CharNum)
{
	switch(Copy_u8LineNum)
	{
		case (LCD_LINE1): LCD_voidSendCommand(0x80 + Copy_u8CharNum); break;
		case (LCD_LINE2): LCD_voidSendCommand(0xC0 + Copy_u8CharNum); break;
	}
}
//42261, you should display each number
void LCD_voidSendNumber(u32 Copy_u32Number)
{
	u8 str[10];
	u8 i, rem, len = 0;

	u32 n = Copy_u32Number;
	if (Copy_u32Number == 0)
	{
		LCD_voidSendChar('0');
	}
	while (n != 0){
		len++;
		n /= 10;
	}

	for ( i = 0; i < len; i++ )
	{
		rem = Copy_u32Number % 10;
		Copy_u32Number = Copy_u32Number / 10;
		str[len - ( i + 1)] = rem + '0';
	}
	str[len] = '\0';

	LCD_voidSendString (str);
}

void LCD_voidDrawSpecialChar( u8 Copy_u8CharIndex, u8 *Copy_u8SpecialChar)
{
	LCD_voidSendCommand(0b01000000+(Copy_u8CharIndex * 8));
	_delay_us(40);
	u8 LCD_U8Counter ;
	for (LCD_U8Counter=0 ; LCD_U8Counter<8 ; LCD_U8Counter++)
	{
		LCD_voidSendChar(Copy_u8SpecialChar[LCD_U8Counter]);
	}
}

void LCD_voidSendSpecialChar(u8 Copy_u8CharIndex)
{
	LCD_voidSendChar(Copy_u8CharIndex);
}
