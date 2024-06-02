/* 
 * File:   ecu_led.h
 * Author: Admin
 *
 * Created on February 4, 2024, 1:38 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "led_cfg.h"

/* Data Type Declarations*/
typedef enum {
    LED_OFF=0,
    LED_ON
}led_status_t;

typedef struct {
    uint8 port   : 4 ;
    uint8 pin    : 3 ;
    uint8 status : 1 ;
}led_t;

/* Function Declarations*/

Std_ReturnType led_initialize(const led_t * led );
Std_ReturnType led_turn_on(const led_t * led );
Std_ReturnType led_turn_off(const led_t * led );
Std_ReturnType led_toggle(const led_t * led );

#endif	/* ECU_LED_H */

