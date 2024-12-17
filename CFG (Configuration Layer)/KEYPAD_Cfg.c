#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define no_key 'T'
#define first_input PIND1
#define first_output PINB2
#define row 4
#define col 4

#ifdef KEYPAD_PROG
u8 keypadarray[row][col] = {
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'c', '0', '=', '+'}};
	#endif

	#endif /* KEYPAD_CFG_H_ */
