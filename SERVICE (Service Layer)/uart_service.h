
#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

void uart_sendstring(u8* str);  //send string
void uart_receivestring(u8* str);  //receive string
void uart_sendnumber (u32 num);
void uart_sendnumber2 (u32 num);
u32 uart_receivenumber (void);
u32 uart_receivenumber2 (void);
u8 endian_test(void);
u32 endian_Convert(u32 num);
u16 endian_Convert(u16 num);
void uart_sendstring_checksum(u8*str);
u8 UART_ReceiveStringChecksum(u8 *str);

#endif
