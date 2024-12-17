
#include "STDtypes.h"
#include "DIO_Inter.h"
#include "LCD_INTER.h"
#include "LCD_Cfg.h"
#include "UTILS.h"
#define F_CPU 8000000
#include <util/delay.h>



#if lcd_mode == _4_bit  

static void write_ins(u8 ins)
{
	DIO_writepin(RS,LOW);
	
	DIO_writepin(D7,GET_BIT(ins,7));
	DIO_writepin(D6,GET_BIT(ins,6));
	DIO_writepin(D5,GET_BIT(ins,5));
	DIO_writepin(D4,GET_BIT(ins,4));
	
	DIO_writepin(EN,HIGH);
	_delay_ms(1);
	DIO_writepin(EN,LOW);
	_delay_ms(1);
	
	
	DIO_writepin(D7,GET_BIT(ins,3));
	DIO_writepin(D6,GET_BIT(ins,2));
	DIO_writepin(D5,GET_BIT(ins,1));
	DIO_writepin(D4,GET_BIT(ins,0));
	
	DIO_writepin(EN,HIGH);
	_delay_ms(1);
	DIO_writepin(EN,LOW);
	_delay_ms(1);
}

static void write_data(u8 data)
{
	DIO_writepin(RS,HIGH);
	
	DIO_writepin(D7,GET_BIT(data,7));
	DIO_writepin(D6,GET_BIT(data,6));
	DIO_writepin(D5,GET_BIT(data,5));
	DIO_writepin(D4,GET_BIT(data,4));
	
	DIO_writepin(EN,HIGH);
	_delay_ms(1);
	DIO_writepin(EN,LOW);
	_delay_ms(1);
	
	
	DIO_writepin(D7,GET_BIT(data,3));
	DIO_writepin(D6,GET_BIT(data,2));
	DIO_writepin(D5,GET_BIT(data,1));
	DIO_writepin(D4,GET_BIT(data,0));
	
	DIO_writepin(EN,HIGH);
	_delay_ms(1);
	DIO_writepin(EN,LOW);
	_delay_ms(1);
}

void LCD_init(void)
{
	
	_delay_ms(50);
	write_ins(0x02);
	write_ins(0x28);
	write_ins(0x0c);
	write_ins(0x01);
	_delay_ms(1);
	write_ins(0x06);
}




#elif lcd_mode==_8_bit  


static void write_ins(u8 ins)
{
	DIO_writepin(RS,LOW);
	DIOWrite_port(LCD_PORT,ins);
	DIO_writepin(EN,HIGH);
	_delay_ms(1);
	DIO_writepin(EN,LOW);
	_delay_ms(1);
	
}
static void write_data(u8 data)
{
	DIO_writepin(RS,HIGH);
	DIOWrite_port(LCD_PORT,data);
	DIO_writepin(EN,HIGH);
	_delay_ms(1);
	DIO_writepin(EN,LOW);
	_delay_ms(1);
	
}

void LCD_init(void)
{
	
	_delay_ms(50);
	write_ins(0x38);
	write_ins(0x0c);  //0x0e  0x0f  cursor
	write_ins(0x01);  //clear lcd
	_delay_ms(1);
	write_ins(0x06);  // DDRAM increment
}



#endif

void LCD_Write_Char(u8 ch)
{
	write_data(ch);
}


void LCD_Write_String(u8 *str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		write_data(str[i]);
	}
}

void LCD_Clear(void)
{
	write_ins(0x01);
	_delay_ms(1);
}

void LCD_Set_Cursor(u8 line ,u8 cell)
{
	if(line==1)
	{
		write_ins(0x80+(cell-1));
	}
	if(line==2)
	{
		write_ins(0x80+0x40+(cell-1));
	}
}
void LCD_Write_Number(s32 num)
{
	u8 str[16],i;
	s8 j;
	if (num==0)
	{
		LCD_Write_Char('0');
	}
	if (num<0)
	{
		LCD_Write_Char('-');
		num=num*-1;
	}
	while(num)
	{
		str[i]=num%10+'0';
		num=num/10;
		i++;	
	}
	for (j=i-1;j>=0;j--)
	{
		LCD_Write_Char(str[j]);
	}
	
}

void LCD_Write_Binary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_Write_Char(GET_BIT(num,i)+'0');
	}
}

void LCD_Write_Hex(u8 num)
{
	u8 LN,HN;  //num 0110 1010
	LN=num&0x0F; //0000 1010
	HN=num>>4;  //0000 0110
	if(HN<10)
	{
		LCD_Write_Char(HN+'0');
	}
	else
	{
		LCD_Write_Char(HN+'A'-10);
	}
	if(LN<10)
	{
		LCD_Write_Char(LN+'0');
	}
	else
	{
		LCD_Write_Char(LN+'A'-10);
	}
}


