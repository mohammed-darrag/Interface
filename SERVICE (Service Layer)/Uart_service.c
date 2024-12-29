
#include "STDtypes.h"
#include "UART_int.h"



void uart_sendstring(u8*str)
{
	u8 i;
	for(i=0;str[i],i++)
	{
		uart_send(str[i]);
		
	}

}

void uart_receivestring(u8* strm)  //synchronious funcation receive a string 
{
	u8 i = 0; // Initialize index
	strm[i] = uart_receive(); // Receive the first character
	
	for (; strm[i] != '#';) // Loop until '#' is received
	{
		i++; // Increment index
		strm[i] = uart_receive(); // Receive the next character
	}
	strm[i] = 0; // Null-terminate the string
}



void uart_sendnumber (u32 num)
{
	uart_send((u8)(num));         
	uart_send((u8)(num >> 8));  
	uart_send((u8)(num >> 16));  
	uart_send((u8)(num >> 24));  
}


void uart_sendnumber2 (u32 num)
{
	u8*p=&num;
	uart_send(p[0]);
	uart_send(p[1]);
	uart_send(p[2]);
	uart_send(p[3]);
	return num;
	

}

u32 uart_receivenumber (void)
{
	u32 num=0;
	u8 b0=uart_receive();
	u8 b1=uart_receive();
	u8 b2=uart_receive();
	u8 b3=uart_receive();
	num=(u32)b0|(u32)b1<<8|(u32)b2<<16|(u32)b3<<24 ;

   return num;
   
}

u32 uart_receivenumber2 (void)
{
	u32 num=0;
	u8*p=num;
	p[0]=uart_receive();
	p[1]=uart_receive();
	p[2]=uart_receive();
	p[3]=uart_receive();
	
	return num;
	
}

	u8 endian_test(void)
	{
		u32 num=1;
		u8*p=&num;
		if(*P==1)
		{
			printf("This number stored on memory as Little endian \n");
		
		}
		else
		{
			printf("This number stored on memory as Big endian \n");
		}
	}
	
	u32 endian_Convert(u32 num)
	{
		u8*p =&num;
		u32 result;
		result = ((u32)p[0] << 24) | 
		((u32)p[1] << 16) | 
		((u32)p[2] << 8)  | 
		((u32)p[3]);        

	  return result; 

	}
	
	u16 endian_Convert(u16 num)
	{
		
		return num<<8|num>>8

	}
	
	
void uart_sendstring_checksum(u8*str)
{
	
	u8 i;
	u16 sum=0;
	for(i=0;i<str[i];i++)
	{	
	}
	uart_send(i);
	for(i=0;str[i];i++)
	{
		uart_send(str[i]);
		sum+=str[i];
		uart_send((u8)sum);
		uart_send((u8)sum>>8);
		
	}
}


u8 UART_ReceiveStringChecksum(u8 *str)
{
	u8 L, i;
	u16 sumReceive = 0;
	u16 sumCalc = 0;
	u8 b0, b1;

	L = UART_Receive();

	for (i = 0; i < L; i++)
	{
		str[i] = UART_Receive();
		sumCalc += str[i];
	}
	str[L] = '\0';

	b0 = UART_Receive();
	b1 = UART_Receive();

	sumReceive = (b1 << 8) | b0;

	if (sumReceive == sumCalc)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
