/* 
 * File:   application.c
 * Author: Admin
 *
 * Created on February 4, 2024, 12:45 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "application.h"
uint8 seg_common_anode_values[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
uint8 seconds = 55, minutes =59, hours = 23;
Std_ReturnType ret= E_NOT_OK;

int main() {
    application_initialize();
    while (1){
        for(int i =0;i<80;i++){
            ret = gpio_port_write_logic(PORTD_INDEX , 0x02);
            ret = seven_segement_write_number(&_7seg , hours/10);
            __delay_us(500);
            ret = gpio_port_write_logic(PORTD_INDEX , 0x04);
            ret = seven_segement_write_number(&_7seg , hours%10);
            __delay_us(500); 
            ret = gpio_port_write_logic(PORTD_INDEX , 0x08);
            ret = seven_segement_write_number(&_7seg , minutes/10);
            __delay_us(500);
            ret = gpio_port_write_logic(PORTD_INDEX , 0x10);
            ret = seven_segement_write_number(&_7seg , minutes%10);
            __delay_us(500);
            ret = gpio_port_write_logic(PORTD_INDEX , 0x20);
            ret = seven_segement_write_number(&_7seg , seconds/10);
            __delay_us(500);
            ret = gpio_port_write_logic(PORTD_INDEX , 0x40);
            ret = seven_segement_write_number(&_7seg , seconds%10);
            __delay_us(500);
        }
        seconds++;
        if(60 == seconds){
            seconds =0;
            minutes++;
        }
        if(60 == minutes){
            minutes =0;
            hours++;
        }
        if(24 == hours){
            hours =0;
        }
  
    }
    
    return (EXIT_SUCCESS);
}


