#include "STDtypes.h"
#include "MEMMAP.h"
#include "UTILS.h"
#include "UART_int.h"


void uart_int(void)
{
	// data length ,stop bits "frame package" 1 stop,no parity,asynchronous
	// baud rate 9600
	UBRRL=51; // l for low number , h for high number
	CLR_BIT(UCSRA,U2X); // normal speed 	
	SET_BIT(UCSRB,RXEN); // resever enable
	SET_BIT(UCSRB,TXEN); // transmitter enable 
	
}


void uart_send(u8 data)
{
	while (!GET_BIT(UCSRC,UDRE)); //when this while become zero go to anther line bussy wait 
	UDR=data;  //UDR bit for buffer;
	
	
}

u8 uart_receive(void)
{
	
	while (!GET_BIT(UCSRC,RXC));
	return UDR;
	
}


u8 uart_receive_periodic(u8*pdata)
{
	if (!GET_BIT(UCSRC,RXC))
	{
		*pdata=UDR;
		return 0;
	}
    return  0;	
}
