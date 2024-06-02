/* 
 * File:   lcd.h
 * Author: Admin
 *
 * Created on February 29, 2024, 2:02 AM
 */

#ifndef LCD_H
#define	LCD_H

#include "../../MCAL_Layer/GPIO/hal_gpio.h"

#define LCD_CLEAR                     0x01
#define LCD_RETURN_HOME               0x02                    
#define LCD_ENTRY_MODE                0x06                    
#define LCD_CURSOR_OFF_DISPLAY_ON     0x0C
#define LCD_CURSOR_OFF_DISPLAY_OFF    0x08
#define LCD_CURSOR_ON_BLINK_ON        0x0F
#define LCD_CURSOR_ON_BLINK_OFF       0x0E
#define LCD_SHIFT_RIGHT               0x1C
#define LCD_SHIFT_LEFT                0x18
#define LCD_8BIT_MODE_2LINE           0x38
#define LCD_4BIT_MODE_2LINE           0x28
#define LCD_CGRAM_START               0x40
#define LCD_DRAM_START                0x80

#define ROW1       1
#define ROW2       2
#define ROW3       3
#define ROW4       4


typedef struct{
    pin_confg_t lcd_rs;
    pin_confg_t lcd_en;
    pin_confg_t lcd_pins[4];
}lcd_4bits_t; 

typedef struct{
    pin_confg_t lcd_rs;
    pin_confg_t lcd_en;
    pin_confg_t lcd_pins[8];
}lcd_8bits_t; 


Std_ReturnType lcd_4bit_initialize(const lcd_4bits_t * lcd);
Std_ReturnType lcd_4bit_send_command(const lcd_4bits_t * lcd , uint8 command);
Std_ReturnType lcd_4bit_send_char_data(const lcd_4bits_t * lcd , uint8 data);
Std_ReturnType lcd_4bit_send_char_data_pos(const lcd_4bits_t * lcd , uint8 row , uint8 column, uint8 data);
Std_ReturnType lcd_4bit_send_string(const lcd_4bits_t * lcd , uint8 * data);
Std_ReturnType lcd_4bit_send_string_pos(const lcd_4bits_t * lcd , uint8 row , uint8 column, uint8 * data);
Std_ReturnType lcd_4bit_send_custom_char(const lcd_4bits_t * lcd , uint8 row , uint8 column,
                                         const uint8 chr[], uint8 mem_pos);

Std_ReturnType lcd_8bit_initialize(const lcd_8bits_t * lcd);
Std_ReturnType lcd_8bit_send_command(const lcd_8bits_t * lcd , uint8 command);
Std_ReturnType lcd_8bit_send_char_data(const lcd_8bits_t * lcd , uint8 data);
Std_ReturnType lcd_8bit_send_char_data_pos(const lcd_8bits_t * lcd , uint8 row , uint8 column, uint8 data);
Std_ReturnType lcd_8bit_send_string(const lcd_8bits_t * lcd , uint8 * data);
Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bits_t * lcd , uint8 row , uint8 column, uint8 * data);
Std_ReturnType lcd_8bit_send_custom_char(const lcd_8bits_t * lcd , uint8 row , uint8 column,
                                         const uint8 chr[], uint8 mem_pos);

void convert_byte_to_string(uint8 value , uint8 *str);
void convert_short_to_string(uint16 value , uint8 *str);
void convert_int_to_string(uint32 value , uint8 *str);

#endif	/* LCD_H */

