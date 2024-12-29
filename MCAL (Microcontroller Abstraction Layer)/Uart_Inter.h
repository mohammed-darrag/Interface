
#ifndef UART_INT_H_
#define UART_INT_H_


void uart_int(void);

void uart_send(u8 data);

u8 uart_receive(void);

u8 uart_receive_periodic(u8*pdata);



#endif