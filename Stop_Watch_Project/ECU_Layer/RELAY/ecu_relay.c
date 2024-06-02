

#include "ecu_relay.h"

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_initialize(const relay_t * relay){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  relay){
         ret = E_NOT_OK;
    }
    else{
        pin_confg_t pin = { .port = relay->port , .pin = relay->pin , 
                            .direction = OUTPUT , .logic = relay->state};
        ret= gpio_pin_direction_initialize_write(&pin);
    }
    return ret;
}

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_on(const relay_t * relay){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  relay){
         ret = E_NOT_OK;
    }
    else{
        pin_confg_t pin = { .port = relay->port , .pin = relay->pin , 
                            .direction = OUTPUT , .logic = relay->state};
        ret = gpio_pin_write_logic(&pin , HIGH);
    }
    return ret;
}

/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_off(const relay_t * relay){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  relay){
         ret = E_NOT_OK;
    }
    else{
         pin_confg_t pin = { .port = relay->port , .pin = relay->pin , 
                            .direction = OUTPUT , .logic = relay->state};
        ret = gpio_pin_write_logic(&pin , LOW);
    }
    return ret;
}


Std_ReturnType relay_toggle(const relay_t * relay){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  relay){
         ret = E_NOT_OK;
    }
    else{
         pin_confg_t pin = { .port = relay->port , .pin = relay->pin , 
                            .direction = OUTPUT , .logic = relay->state};
        ret = gpio_pin_toggle_logic(&pin);
    }
    return ret;
}