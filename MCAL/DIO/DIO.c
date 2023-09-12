#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "DIO.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    if (Copy_u8Pin < 8 && Copy_u8Pin >= 0)
    {
        if (Copy_u8Direction == DIO_OUTPUT)
        {
            switch (Copy_u8Port)
            {
                case DIO_PORTA: SET_BIT(DDRA, Copy_u8Pin); break;
                case DIO_PORTB: SET_BIT(DDRB, Copy_u8Pin); break;
                case DIO_PORTC: SET_BIT(DDRC, Copy_u8Pin); break;
                case DIO_PORTD: SET_BIT(DDRD, Copy_u8Pin); break;
                default: break;
            }
        }
        else if (Copy_u8Direction == DIO_INPUT)
        {
            switch (Copy_u8Port)
            {
                case DIO_PORTA: CLR_BIT(DDRA, Copy_u8Pin); break;
                case DIO_PORTB: CLR_BIT(DDRB, Copy_u8Pin); break;
                case DIO_PORTC: CLR_BIT(DDRC, Copy_u8Pin); break;
                case DIO_PORTD: CLR_BIT(DDRD, Copy_u8Pin); break;
                default: break;
            }
        }
    }
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    if (Copy_u8Pin < 8 && Copy_u8Pin >= 0)
    {
        if (Copy_u8Value == DIO_HIGH)
        {
            switch (Copy_u8Port)
            {
                case DIO_PORTA: SET_BIT(PORTA, Copy_u8Pin); break;
                case DIO_PORTB: SET_BIT(PORTB, Copy_u8Pin); break;
                case DIO_PORTC: SET_BIT(PORTC, Copy_u8Pin); break;
                case DIO_PORTD: SET_BIT(PORTD, Copy_u8Pin); break;
                default: break;
            }
        }
        else if (Copy_u8Value == DIO_LOW)
        {
            switch (Copy_u8Port)
            {
                case DIO_PORTA: CLR_BIT(PORTA, Copy_u8Pin); break;
                case DIO_PORTB: CLR_BIT(PORTB, Copy_u8Pin); break;
                case DIO_PORTC: CLR_BIT(PORTC, Copy_u8Pin); break;
                case DIO_PORTD: CLR_BIT(PORTD, Copy_u8Pin); break;
                default: break;
            }
        }
    }
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    if (Copy_u8Pin < 8 && Copy_u8Pin >= 0)
    {
        
        switch (Copy_u8Port)
        {
            case DIO_PORTA: return (GET_BIT(PINA, Copy_u8Pin));
            case DIO_PORTB: return (GET_BIT(PINB, Copy_u8Pin));
            case DIO_PORTC: return (GET_BIT(PINC, Copy_u8Pin));
            case DIO_PORTD: return (GET_BIT(PIND, Copy_u8Pin));
            default: return (0xFF);
        }
    }
    return (0xFF);
}

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8DirectionValue)
{
    switch (Copy_u8Port)
    {
        case DIO_PORTA: DDRA = Copy_u8DirectionValue; break;
        case DIO_PORTB: DDRB = Copy_u8DirectionValue; break;
        case DIO_PORTC: DDRC = Copy_u8DirectionValue; break;
        case DIO_PORTD: DDRD = Copy_u8DirectionValue; break;
        default: break;
    }
}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    switch (Copy_u8Port)
    {
        case DIO_PORTA: PORTA = Copy_u8Value; break;
        case DIO_PORTB: PORTB = Copy_u8Value; break;
        case DIO_PORTC: PORTC = Copy_u8Value; break;
        case DIO_PORTD: PORTD = Copy_u8Value; break;
        default: break;
    }
}

void DIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    if (Copy_u8Pin < 8 && Copy_u8Pin >= 0)
    {
        switch (Copy_u8Port)
        {
            case DIO_PORTA: TGL_BIT(PORTA, Copy_u8Pin); break;
            case DIO_PORTB: TGL_BIT(PORTB, Copy_u8Pin); break;
            case DIO_PORTC: TGL_BIT(PORTC, Copy_u8Pin); break;
            case DIO_PORTD: TGL_BIT(PORTD, Copy_u8Pin); break;
            default: break;
        }
    }
}
