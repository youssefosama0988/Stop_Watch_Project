

#include "lcd.h"

static Std_ReturnType lcd_send_4bits(const lcd_4bits_t * lcd , uint8 data_command);
static Std_ReturnType lcd_4bits_send_enable_signal(const lcd_4bits_t * lcd );
static Std_ReturnType lcd_4bits_set_cursor(const lcd_4bits_t * lcd , uint8 row, uint8 column);

static Std_ReturnType lcd_8bits_send_enable_signal(const lcd_8bits_t * lcd );
static Std_ReturnType lcd_8bits_set_cursor(const lcd_8bits_t * lcd , uint8 row, uint8 column);



Std_ReturnType lcd_4bit_initialize(const lcd_4bits_t * lcd){
    Std_ReturnType ret = E_OK;
    uint8 l_counter= 0;
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize_write(&(lcd->lcd_en));
        ret = gpio_pin_direction_initialize_write(&(lcd->lcd_rs));  
        
        for (l_counter = 0; l_counter < 4;l_counter++){
            ret = gpio_pin_direction_initialize_write(&(lcd->lcd_pins[l_counter]));
        }
        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        ret = lcd_4bit_send_command(lcd , LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd , LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd , LCD_ENTRY_MODE);
        ret = lcd_4bit_send_command(lcd , LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_4bit_send_command(lcd , LCD_4BIT_MODE_2LINE);
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_command(const lcd_4bits_t * lcd , uint8 command){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs) , LOW);
        
        ret = lcd_send_4bits( lcd ,command >> 4);
        ret = lcd_4bits_send_enable_signal(lcd);
        ret = lcd_send_4bits( lcd ,command);
        ret = lcd_4bits_send_enable_signal(lcd); 
    }
    return ret;
}


Std_ReturnType lcd_4bit_send_char_data(const lcd_4bits_t * lcd , uint8 data){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs) , HIGH);
        
        ret = lcd_send_4bits( lcd ,data >> 4);
        ret = lcd_4bits_send_enable_signal(lcd);
        ret = lcd_send_4bits( lcd ,data);
        ret = lcd_4bits_send_enable_signal(lcd); 
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_char_data_pos(const lcd_4bits_t * lcd , uint8 row , uint8 column, uint8 data){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret  = lcd_4bits_set_cursor(lcd, row, column);
        ret &= lcd_4bit_send_char_data(lcd, data);
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_string(const lcd_4bits_t * lcd , uint8 * data){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        while(*data){
            ret = lcd_4bit_send_char_data(lcd , *data++);
        }
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_string_pos(const lcd_4bits_t * lcd , uint8 row , uint8 column, uint8 * data){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret  = lcd_4bits_set_cursor(lcd , row, column);
        ret &= lcd_4bit_send_string(lcd, data);
    }
    return ret;
}

Std_ReturnType lcd_4bit_send_custom_char(const lcd_4bits_t * lcd , uint8 row , uint8 column,
                                         const uint8 chr[], uint8 mem_pos){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        
    }
    return ret;
}


Std_ReturnType lcd_8bit_initialize(const lcd_8bits_t * lcd){
    Std_ReturnType ret = E_OK;
    uint8 l_counter= 0;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize_write(&(lcd->lcd_en));
        ret = gpio_pin_direction_initialize_write(&(lcd->lcd_rs));  
        for (l_counter = 0; l_counter < 8;l_counter++){
            ret = gpio_pin_direction_initialize_write(&(lcd->lcd_pins[l_counter]));
        }
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2LINE);
        ret = lcd_8bit_send_command(lcd , LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd , LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd , LCD_ENTRY_MODE);
        ret = lcd_8bit_send_command(lcd , LCD_CURSOR_OFF_DISPLAY_ON);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_command(const lcd_8bits_t * lcd , uint8 command){
    Std_ReturnType ret = E_OK;
    uint8 l_pin_counter = 0;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs) , LOW);
        
        for(l_pin_counter = 0 ; l_pin_counter <8 ; l_pin_counter ++){  
          ret = gpio_pin_write_logic(&(lcd->lcd_pins[l_pin_counter]),(command >> l_pin_counter)&(uint8)0x01);
        }
        ret = lcd_8bits_send_enable_signal(lcd);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_char_data(const lcd_8bits_t * lcd , uint8 data){
    Std_ReturnType ret = E_OK;
    uint8 l_pin_counter = 0;
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs) , HIGH);
        
        for(l_pin_counter = 0 ; l_pin_counter <8 ; l_pin_counter ++){  
          ret = gpio_pin_write_logic(&(lcd->lcd_pins[l_pin_counter]),(data >> l_pin_counter)&(uint8)0x01);
        }
        ret = lcd_8bits_send_enable_signal(lcd);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_char_data_pos(const lcd_8bits_t * lcd , uint8 row , uint8 column, uint8 data){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret  = lcd_8bits_set_cursor(lcd , row , column);
        ret &= lcd_8bit_send_char_data(lcd , data);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_string(const lcd_8bits_t * lcd , uint8 * data){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        while(*data){
           ret = lcd_8bit_send_char_data(lcd , *data++);
        }
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bits_t * lcd , uint8 row , uint8 column, uint8 * data){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        ret =  lcd_8bits_set_cursor(lcd, row, column);
        ret &= lcd_8bit_send_string(lcd, data);
    }
    return ret;
}

Std_ReturnType lcd_8bit_send_custom_char(const lcd_8bits_t * lcd , uint8 row , uint8 column,
                                         const uint8 chr[], uint8 mem_pos){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        
    }
    return ret;
}


void convert_byte_to_string(uint8 value , uint8 *str){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  str ){
         ret = E_NOT_OK;
    }
    else{
        
    }
}

void convert_short_to_string(uint16 value , uint8 *str){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  str ){
         ret = E_NOT_OK;
    }
    else{
        
    }
}

void convert_int_to_string(uint32 value , uint8 *str){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  str ){
         ret = E_NOT_OK;
    }
    else{
        
    }
} 

static Std_ReturnType lcd_send_4bits(const lcd_4bits_t * lcd , uint8 data_command){
    Std_ReturnType ret = E_OK;
    
    ret  = gpio_pin_write_logic(&(lcd->lcd_pins[0]) , (data_command >> 0) & (uint8)0x01); 
    ret &= gpio_pin_write_logic(&(lcd->lcd_pins[1]) , (data_command >> 1) & (uint8)0x01); 
    ret &= gpio_pin_write_logic(&(lcd->lcd_pins[2]) , (data_command >> 2) & (uint8)0x01); 
    ret &= gpio_pin_write_logic(&(lcd->lcd_pins[3]) , (data_command >> 3) & (uint8)0x01); 
    
    return ret;
}

static Std_ReturnType lcd_4bits_send_enable_signal(const lcd_4bits_t * lcd ){
    Std_ReturnType ret = E_OK;
    
    ret  = gpio_pin_write_logic(&(lcd->lcd_en) ,HIGH);
    __delay_us(5);
    ret  = gpio_pin_write_logic(&(lcd->lcd_en) ,LOW);
    return ret;
}

static Std_ReturnType lcd_8bits_send_enable_signal(const lcd_8bits_t * lcd ){
    Std_ReturnType ret = E_OK;
    
    ret  = gpio_pin_write_logic(&(lcd->lcd_en) ,HIGH);
    __delay_us(5);
    ret  = gpio_pin_write_logic(&(lcd->lcd_en) ,LOW);
    return ret;
}

static Std_ReturnType lcd_8bits_set_cursor(const lcd_8bits_t * lcd , uint8 row, uint8 column){
   Std_ReturnType ret = E_OK;
   column--;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        switch (row){
            case ROW1 : ret = lcd_8bit_send_command(lcd , 0x80 + column ); break;
            case ROW2 : ret = lcd_8bit_send_command(lcd , 0xc0 + column ); break;
            case ROW3 : ret = lcd_8bit_send_command(lcd , 0x94 + column ); break;
            case ROW4 : ret = lcd_8bit_send_command(lcd , 0xd4 + column ); break;
            
            default :;
        }
    }
   return ret;
}

static Std_ReturnType lcd_4bits_set_cursor(const lcd_4bits_t * lcd , uint8 row, uint8 column){
   Std_ReturnType ret = E_OK;
   column--;
    
    if(NULL ==  lcd ){
         ret = E_NOT_OK;
    }
    else{
        switch (row){
            case ROW1 : ret = lcd_4bit_send_command(lcd , 0x80 + column ); break;
            case ROW2 : ret = lcd_4bit_send_command(lcd , 0xc0 + column ); break;
            case ROW3 : ret = lcd_4bit_send_command(lcd , 0x94 + column ); break;
            case ROW4 : ret = lcd_4bit_send_command(lcd , 0xd4 + column ); break;
            
            default :;
        }
    }
   return ret;
}
