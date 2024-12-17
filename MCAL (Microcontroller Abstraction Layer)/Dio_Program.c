
#include "STDtypes.h"
#include "MEMMAP.h"
#include "UTILS.h"
#include "DIO_Inter.h"
#include "DIO_Private.h"




void DIO_init(void)
{
	DIO_PIN_T i;  //enum 
	for (i = PINA0; i < TOTAL_PINS; i++)
	{
		DIO_initpin(i, DIO_PIN_STATUSARR[i]);
	}
}

static void DIO_initpin(DIO_PIN_T pin, DIO_PINSTATUS_T status)
{
	DIO_PORT_T port = pin / 8; // Determine the port
	u8 pin_num = pin % 8;      // Determine the pin number within the port

	switch (status)
	{
		case OUTPUT:
		switch (port)
		{
			case PA:
			SET_BIT(DDRA, pin_num);
			CLR_BIT(PORTA, pin_num);
			break;
			case PB:
			SET_BIT(DDRB, pin_num);
			CLR_BIT(PORTB, pin_num);
			break;
			case PC:
			SET_BIT(DDRC, pin_num);
			CLR_BIT(PORTC, pin_num);
			break;
			case PD:
			SET_BIT(DDRD, pin_num);
			CLR_BIT(PORTD, pin_num);
			break;
		}
		break;

		case INTFREE:
		switch (port)
		{
			case PA:
			CLR_BIT(DDRA, pin_num);
			CLR_BIT(PORTA, pin_num);
			break;
			case PB:
			CLR_BIT(DDRB, pin_num);
			CLR_BIT(PORTB, pin_num);
			break;
			case PC:
			CLR_BIT(DDRC, pin_num);
			CLR_BIT(PORTC, pin_num);
			break;
			case PD:
			CLR_BIT(DDRD, pin_num);
			CLR_BIT(PORTD, pin_num);
			break;
		}
		break;

		case INPULL:
		switch (port)
		{
			case PA:
			CLR_BIT(DDRA, pin_num);
			SET_BIT(PORTA, pin_num);
			break;
			case PB:
			CLR_BIT(DDRB, pin_num);
			SET_BIT(PORTB, pin_num);
			break;
			case PC:
			CLR_BIT(DDRC, pin_num);
			SET_BIT(PORTC, pin_num);
			break;
			case PD:
			CLR_BIT(DDRD, pin_num);
			SET_BIT(PORTD, pin_num);
			break;
		}
		break;
	}
}

void DIO_writepin(DIO_PIN_T pin, DIO_PINVOLTAGE_T volt)
{
	DIO_PORT_T port = pin / 8; // Determine the port
	u8 pin_num = pin % 8;      // Determine the pin number within the port

	if (volt == HIGH)
	{
		switch (port)
		{
			case PA:
			SET_BIT(PORTA, pin_num);
			break;
			case PB:
			SET_BIT(PORTB, pin_num);
			break;
			case PC:
			SET_BIT(PORTC, pin_num);
			break;
			case PD:
			SET_BIT(PORTD, pin_num);
			break;
		}
	}
	else if (volt == LOW)
	{
		switch (port)
		{
			case PA:
			CLR_BIT(PORTA, pin_num);
			break;
			case PB:
			CLR_BIT(PORTB, pin_num);
			break;
			case PC:
			CLR_BIT(PORTC, pin_num);
			break;
			case PD:
			CLR_BIT(PORTD, pin_num);
			break;
		}
	}
}

DIO_PINVOLTAGE_T DIO_readpin(DIO_PIN_T pin)
{
	DIO_PORT_T port = pin / 8; // Determine the port
	u8 pin_num = pin % 8;      // Determine the pin number within the port
	DIO_PINVOLTAGE_T volt = LOW;

	switch (port)
	{
		case PA:
		volt = (DIO_PINVOLTAGE_T)GET_BIT(PINA, pin_num);
		break;
		case PB:
		volt = (DIO_PINVOLTAGE_T)GET_BIT(PINB, pin_num);
		break;
		case PC:
		volt = (DIO_PINVOLTAGE_T)GET_BIT(PINC, pin_num);
		break;
		case PD:
		volt = (DIO_PINVOLTAGE_T)GET_BIT(PIND, pin_num);
		break;
	}
	return volt;
}

void DIOWrite_port(DIO_PORT_T port,u8 data)
{
	switch(port)
	{
		case PA:
		PORTA=data;
		break;
		
		case PB:
		PORTB=data;
		break; 
		
		case PC:
		PORTC=data;
		break;
					
		case PD:
		PORTD=data;
		break;
		
	}
}

void DIO_Toggelpin(DIO_PIN_T pin)
{
		DIO_PORT_T port = pin / 8; // Determine the port
		u8 pin_num = pin % 8;      // Determine the pin number within the port
		DIO_PINVOLTAGE_T volt = LOW;

		switch (port)
		{
			case PA:
			TOG_BIT(PORTA,pin_num);
			break;
			case PB:
			TOG_BIT(PORTB,pin_num);
			break;
			case PC:
			TOG_BIT(PORTC,pin_num);
			break;
			case PD:
			TOG_BIT(PORTD,pin_num);
			break;
		}
	
	
}