/* 
 * File:   layer_initialize.c
 * Author: Admin
 *
 * Created on March 2, 2024, 1:46 AM
 */

#include "layer_initialize.h"

segment_t _7seg = {
    .segment_pins[0].direction = OUTPUT,
    .segment_pins[0].port = PORTC_INDEX,
    .segment_pins[0].pin = PIN0,
    .segment_pins[1].direction = OUTPUT,
    .segment_pins[1].port = PORTC_INDEX,
    .segment_pins[1].pin = PIN1,
    .segment_pins[2].direction = OUTPUT,
    .segment_pins[2].port = PORTC_INDEX,
    .segment_pins[2].pin = PIN2,
    .segment_pins[3].direction = OUTPUT,
    .segment_pins[3].port = PORTC_INDEX,
    .segment_pins[3].pin = PIN3,
    
    .segment_type = SEGMENT_COMMON_ANODE
};
lcd_4bits_t lcd1 =    
{
    .lcd_en.direction = OUTPUT,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = PIN1,
    .lcd_en.logic = LOW,
    .lcd_rs.direction = OUTPUT,
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = PIN0,
    .lcd_rs.logic = LOW,
    .lcd_pins[0].direction = OUTPUT,
    .lcd_pins[0].port = PORTC_INDEX,
    .lcd_pins[0].pin = PIN2,
    .lcd_pins[0].logic = LOW,
    .lcd_pins[1].direction = OUTPUT,
    .lcd_pins[1].port = PORTC_INDEX,
    .lcd_pins[1].pin = PIN3,
    .lcd_pins[1].logic = LOW,
    .lcd_pins[2].direction = OUTPUT,
    .lcd_pins[2].port = PORTC_INDEX,
    .lcd_pins[2].pin = PIN4,
    .lcd_pins[2].logic = LOW,
    .lcd_pins[3].direction = OUTPUT,
    .lcd_pins[3].port = PORTC_INDEX,
    .lcd_pins[3].pin = PIN5,
    .lcd_pins[3].logic = LOW
};

lcd_8bits_t lcd2 =    
{
    .lcd_en.direction = OUTPUT,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = PIN7,
    .lcd_en.logic = LOW,
    .lcd_rs.direction = OUTPUT,
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = PIN6,
    .lcd_rs.logic = LOW,
    .lcd_pins[0].direction = OUTPUT,
    .lcd_pins[0].port = PORTD_INDEX,
    .lcd_pins[0].pin = PIN0,
    .lcd_pins[0].logic = LOW,
    .lcd_pins[1].direction = OUTPUT,
    .lcd_pins[1].port = PORTD_INDEX,
    .lcd_pins[1].pin = PIN1,
    .lcd_pins[1].logic = LOW,
    .lcd_pins[2].direction = OUTPUT,
    .lcd_pins[2].port = PORTD_INDEX,
    .lcd_pins[2].pin = PIN2,
    .lcd_pins[2].logic = LOW,
    .lcd_pins[3].direction = OUTPUT,
    .lcd_pins[3].port = PORTD_INDEX,
    .lcd_pins[3].pin = PIN3,
    .lcd_pins[3].logic = LOW,
    .lcd_pins[4].direction = OUTPUT,
    .lcd_pins[4].port = PORTD_INDEX,
    .lcd_pins[4].pin = PIN4,
    .lcd_pins[4].logic = LOW,
    .lcd_pins[5].direction = OUTPUT,
    .lcd_pins[5].port = PORTD_INDEX,
    .lcd_pins[5].pin = PIN5,
    .lcd_pins[5].logic = LOW,
    .lcd_pins[6].direction = OUTPUT,
    .lcd_pins[6].port = PORTD_INDEX,
    .lcd_pins[6].pin = PIN6,
    .lcd_pins[6].logic = LOW,
    .lcd_pins[7].direction = OUTPUT,
    .lcd_pins[7].port = PORTD_INDEX,
    .lcd_pins[7].pin = PIN7,
    .lcd_pins[7].logic = LOW        
};

Std_ReturnType ret= E_NOT_OK;
void application_initialize(void){
    ret = lcd_4bit_initialize(&lcd1);
    ret = lcd_8bit_initialize(&lcd2);
    ret = seven_segement_intialize(&_7seg);
    ret = gpio_port_direction_initialize(PORTC_INDEX , ~0x0F);
    ret = gpio_port_direction_initialize(PORTD_INDEX , ~0x7E);
}


/* 
 --------------------motor inizialize------------------------
 dc_motor_t motor_1 = {
    .dc_motor_pin[0].port = PORTC_INDEX , 
    .dc_motor_pin[0].pin  = PIN1 , 
    .dc_motor_pin[0].direction = OUTPUT , 
    .dc_motor_pin[0].logic = MOTOR_OFF ,
    .dc_motor_pin[1].port = PORTC_INDEX , 
    .dc_motor_pin[1].pin  = PIN2 , 
    .dc_motor_pin[1].direction = OUTPUT , 
    .dc_motor_pin[1].logic = MOTOR_OFF
};
 */