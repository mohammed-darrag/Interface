#ifndef DIO_INTER_H_
#define DIO_INTER_H_


typedef enum
{
	OUTPUT,
	INTFREE,
	INPULL
} DIO_PINSTATUS_T;


typedef enum
{
	PINA0 = 0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS 
} DIO_PIN_T;


typedef enum
{
	PA,
	PB,
	PC,
	PD
} DIO_PORT_T;


typedef enum
{
	LOW = 0,
	HIGH
} DIO_PINVOLTAGE_T;


void DIO_init(void);
void DIOWrite_port(DIO_PORT_T port,u8 data);
void DIO_writepin(DIO_PIN_T pin, DIO_PINVOLTAGE_T volt);
DIO_PINVOLTAGE_T DIO_readpin(DIO_PIN_T pin);
void DIO_Toggelpin(DIO_PIN_T pin);


#endif /* DIO_INTER_H_ */
