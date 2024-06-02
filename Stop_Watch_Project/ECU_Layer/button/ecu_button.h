/* 
 * File:   ecu_button.h
 * Author: Admin
 *
 * Created on February 12, 2024, 9:29 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

#include "ecu_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_connection_t;

typedef struct{
    pin_confg_t button_pin ;
    button_state_t button_state ;
    button_connection_t button_connection ; 

}button_t;


Std_ReturnType button_initialize(const button_t * button);
Std_ReturnType button_read_state(const button_t * button , button_state_t * state);

#endif	/* ECU_BUTTON_H */

