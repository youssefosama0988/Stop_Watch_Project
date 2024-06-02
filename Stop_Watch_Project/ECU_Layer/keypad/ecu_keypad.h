/* 
 * File:   ecu_keypad.h
 * Author: Admin
 *
 * Created on February 21, 2024, 6:21 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

#include "../../MCAL_Layer/GPIO/hal_gpio.h"

#define KEYPAD_ROWS      4
#define KEYPAD_COLUMNS   4

typedef struct{
    pin_confg_t keypad_rows_pins    [KEYPAD_ROWS];
    pin_confg_t keypad_columns_pins [KEYPAD_COLUMNS];

}keypad_t;

#endif	/* ECU_KEYPAD_H */

