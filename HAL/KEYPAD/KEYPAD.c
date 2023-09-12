/*
 * KEYPAD.c
 *
 *  Created on: 17 Aug 2023
 *      Author: menna
 */
#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "KEYPAD.h"

u8 KPD_Au8Keys[4][4] = KPD_KEYS;

u8 KPD_Au8RowPins[4] = {KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN, KPD_R4_PIN};

u8 KPD_Au8ColPins[4] = {KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN, KPD_C4_PIN};

void KPD_voidInit(void)
{
	u8 Local_u8Count;

	for (Local_u8Count = 0; Local_u8Count < 8; Local_u8Count++)
	{
		if (Local_u8Count < 4)
		{
			DIO_voidSetPinDirection(KPD_PORT, KPD_Au8RowPins[Local_u8Count], DIO_OUTPUT);
		}
		else
		{
			DIO_voidSetPinDirection(KPD_PORT, KPD_Au8ColPins[Local_u8Count - 4], DIO_INPUT);
		}
	}

	DIO_voidSetPortValue(KPD_PORT, 0xFF);
}

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8RowCount, Local_u8ColCount, Local_u8Pressed, Local_u8Flag = 0;
	u8 Local_u8ReturnedVal = KPD_CHECK_BUTTON_PRESSED_OR_NOT;

	for (Local_u8RowCount = 0; Local_u8RowCount < 4; Local_u8RowCount++)
	{
		DIO_voidSetPinValue(KPD_PORT, KPD_Au8RowPins[Local_u8RowCount], DIO_LOW);

		for (Local_u8ColCount = 0; Local_u8ColCount < 4; Local_u8ColCount++)
		{
			Local_u8Pressed = DIO_u8GetPinValue(KPD_PORT, KPD_Au8ColPins[Local_u8ColCount]);
			if (Local_u8Pressed == 0)
			{
				_delay_ms(25);

				Local_u8Pressed = DIO_u8GetPinValue(KPD_PORT, KPD_Au8ColPins[Local_u8ColCount]);
				if (Local_u8Pressed == 0)
				{
					Local_u8ReturnedVal = KPD_Au8Keys[Local_u8RowCount][Local_u8ColCount];
					while (Local_u8Pressed == 0)
					{
						Local_u8Pressed = DIO_u8GetPinValue(KPD_PORT, KPD_Au8ColPins[Local_u8ColCount]);
					}

					Local_u8Flag = 1;
					break;
				}
			}
		}

		DIO_voidSetPinValue(KPD_PORT, KPD_Au8RowPins[Local_u8RowCount], DIO_HIGH);
		if (Local_u8Flag)
			break;
	}

	return (Local_u8ReturnedVal);
}
