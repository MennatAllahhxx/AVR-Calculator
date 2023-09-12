#ifndef KEYPAD_H
#define KEYPAD_H

#define KPD_PORT DIO_PORTC

#define KPD_CHECK_BUTTON_PRESSED_OR_NOT 0XFF

#define KPD_R1_PIN DIO_PIN0
#define KPD_R2_PIN DIO_PIN1
#define KPD_R3_PIN DIO_PIN2
#define KPD_R4_PIN DIO_PIN3

#define KPD_C1_PIN DIO_PIN4
#define KPD_C2_PIN DIO_PIN5
#define KPD_C3_PIN DIO_PIN6
#define KPD_C4_PIN DIO_PIN7

#define KPD_KEYS {{'7', '8', '9', '/'},\
				  {'4', '5', '6', '*'},\
				  {'1', '2', '3', '-'},\
				  {'C', '0', '=', '+'}}



void KPD_voidInit(void);
u8 KPD_u8GetPressedKey(void);

#endif
