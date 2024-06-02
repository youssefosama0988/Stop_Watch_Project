/* 
 * File:   ecu_dc_motor.h
 * Author: Admin
 *
 * Created on February 17, 2024, 2:22 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Macro Definitions*/
#define MOTOR_ON    0x01
#define MOTOR_OFF   0x00

/* Data Type Declarations */

typedef struct {
    pin_confg_t dc_motor_pin[2];
}dc_motor_t;

/* Function Declarations */
Std_ReturnType dc_motor_initialize(const dc_motor_t * motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t * motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t * motor);
Std_ReturnType dc_motor_stop(const dc_motor_t * motor);

#endif	/* ECU_DC_MOTOR_H */

