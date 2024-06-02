/* 
 * File:   ecu_relay.h
 * Author: Admin
 *
 * Created on February 16, 2024, 10:57 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

#include "../../MCAL_Layer/GPIO/hal_gpio.h"

#define RELAY_ON    0x01
#define RELAY_OFF   0x00

/* Data Type Declarations */

typedef struct {
    uint8 port  : 4 ;
    uint8 pin   : 3 ;
    uint8 state : 1 ;
}relay_t;

/* Function Declarations */
Std_ReturnType relay_initialize(const relay_t * relay);
Std_ReturnType relay_turn_on(const relay_t * relay);
Std_ReturnType relay_turn_off(const relay_t * relay);
Std_ReturnType relay_toggle(const relay_t * relay);


#endif	/* ECU_RELAY_H */

