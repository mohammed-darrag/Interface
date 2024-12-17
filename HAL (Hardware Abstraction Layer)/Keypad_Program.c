#define KEYPAD_PROG
#include "STDtypes.h"
#include "DIO_Inter.h"
#include "KEYPAD_CFG.h"  // Ensure this filename is correct
#include "KEYPAD_INTER.h"
#define F_CPU 8000000
#include <util/delay.h>

void keypad_init(void)
{
	u8 r;
	for (r = 0; r < row; r++)
	{
		DIO_writepin(first_output + r, HIGH);
	}
}

u8 keypad_getkey(void)
{
	u8 r, c, key = no_key;
	for (r = 0; r < row; r++)
	{
		DIO_writepin(first_output + r, LOW);
		for (c = 0; c < col; c++)
		{
			if (!DIO_readpin(first_input + c))
			{
				key = keypadarray[r][c];
				_delay_ms(10);
				while (!DIO_readpin(first_input + c));
				_delay_ms(10);
			}
		}
		DIO_writepin(first_output + r, HIGH);
	}
	return key;
}
