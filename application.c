#include <avr/io.h>
#include <util/delay.h>

#include "LIB/STD_Types.h"

#include "HAL/LCD/LCD.h"
#include "HAL/KEYPAD/KEYPAD.h"

int main(void)
{
	u8 Local_u8Key = 0, Local_u8Operator, Local_u8Flag = 0, Local_u8Flag2 = 0;
	f32 Local_f32FirstNumber = 0, Local_f32SecondNumber = 0, Local_f32Remainder;

	LCD_voidInit();
	KPD_voidInit();

	while (1)
	{
		Local_u8Key = KPD_u8GetPressedKey();

		while (Local_u8Key == KPD_CHECK_BUTTON_PRESSED_OR_NOT)
		{
			Local_u8Key = KPD_u8GetPressedKey();
		}

		if (Local_u8Flag2 == 0)
		{
			LCD_voidSendCommand(CLEAR);
			_delay_ms(2);
		}

		if (Local_u8Key != KPD_CHECK_BUTTON_PRESSED_OR_NOT)
		{
			LCD_voidSendChar(Local_u8Key);

			Local_u8Flag2 = 1;

			if (Local_u8Key == '=')
			{
				switch (Local_u8Operator)
				{
					case '+':
						Local_f32FirstNumber += Local_f32SecondNumber;
						break;
					case '-':
						Local_f32FirstNumber -= Local_f32SecondNumber;
						break;
					case '*':
						Local_f32FirstNumber *= Local_f32SecondNumber;
						break;
					case '/':
						Local_f32FirstNumber /= Local_f32SecondNumber;
						break;
				}

				LCD_voidSetLocation(LCD_LINE2, 0);
				if (Local_f32FirstNumber < 0)
				{
					LCD_voidSendChar('-');
					Local_f32FirstNumber *= (-1);
				}
				LCD_voidSendNumber((u32)Local_f32FirstNumber);

				Local_f32Remainder = (u32)(Local_f32FirstNumber * 100 )%100;
				if (Local_f32Remainder > 0)
				{
					LCD_voidSendChar('.');
					LCD_voidSendNumber(Local_f32Remainder);
				}

				Local_f32FirstNumber = 0;
				Local_f32SecondNumber = 0;
				Local_u8Operator = 0;
				Local_u8Flag = 0;
				Local_u8Flag2 = 0;
			}

			else if ((Local_u8Key < 58) && (Local_u8Key > 47))
			{
				if (!Local_u8Flag)
				{
					Local_f32FirstNumber *= 10;
					Local_f32FirstNumber += (Local_u8Key - '0');
				}
				else
				{
					Local_f32SecondNumber *= 10;
					Local_f32SecondNumber += (Local_u8Key - '0');
				}

			}

			else
			{
				if (Local_u8Key == 'C')
				{
					Local_f32FirstNumber = 0;
					Local_f32SecondNumber = 0;
					Local_u8Operator = 0;
					Local_u8Flag = 0;
					Local_u8Flag2 = 0;

					LCD_voidSendCommand(CLEAR);
					_delay_ms(2);
				}
				else
				{
					switch (Local_u8Operator)
					{
						case '+':
							Local_f32FirstNumber += Local_f32SecondNumber;
							break;
						case '-':
							Local_f32FirstNumber -= Local_f32SecondNumber;
							break;
						case '*':
							Local_f32FirstNumber *= Local_f32SecondNumber;
							break;
						case '/':
							Local_f32FirstNumber /= Local_f32SecondNumber;
							break;
					}

					Local_u8Operator = Local_u8Key;
					Local_u8Flag = 1;
					Local_f32SecondNumber = 0;
				}
			}
		}
	}
	return 0;
}
