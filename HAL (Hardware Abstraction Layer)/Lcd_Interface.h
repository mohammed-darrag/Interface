 


#ifndef LCD_INTER_H_
#define LCD_INTER_H_

void LCD_init(void);
void LCD_Write_Char(u8 ch);
void LCD_Write_String(u8 *str);
void LCD_Clear(void);
void LCD_Set_Cursor(u8 line ,u8 cell);
void LCD_Write_Number(s32 num);
void LCD_Write_Binary(u8 num);
void LCD_Write_Hex(u8 num);









#endif /* LCD_INTER_H_ */