

#include "ecu_led.h"

/**
 * 
 * @param led pointer to the led configuration
 * @return status of the function 
 *         E_OK if done successfully
 *         E_NOT_OK if done unsuccessfully
 */
Std_ReturnType led_initialize(const led_t* led ){
    Std_ReturnType ret = E_OK;
    
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_confg_t pin = {.port = led->port , .pin = led->pin , .direction = OUTPUT , .logic = led->status};
        gpio_pin_direction_initialize(&pin);
    }  
    return ret;
}

/**
 * 
 * @param led pointer to the led configuration
 * @return status of the function 
 *         E_OK if done successfully
 *         E_NOT_OK if done unsuccessfully
 */
Std_ReturnType led_turn_on(const led_t * led ){
    Std_ReturnType ret = E_OK;
    
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_confg_t pin = {.port = led->port , .pin = led->pin , .direction = OUTPUT , .logic = led->status};
        gpio_pin_write_logic(&pin,HIGH);
    }  
    return ret;
}

/**
 * 
 * @param led pointer to the led configuration
 * @return status of the function 
 *         E_OK if done successfully
 *         E_NOT_OK if done unsuccessfully
 */
Std_ReturnType led_turn_off(const led_t * led ){
    Std_ReturnType ret = E_OK;
    
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_confg_t pin = {.port = led->port , .pin = led->pin , .direction = OUTPUT , .logic = led->status};
            ret = gpio_pin_write_logic(&pin,LOW); 
    }  
    return ret;
}

/**
 * 
 * @param led pointer to the led configuration
 * @return status of the function 
 *         E_OK if done successfully
 *         E_NOT_OK if done unsuccessfully
 */
Std_ReturnType led_toggle(const led_t * led ){
    Std_ReturnType ret = E_OK;
    
    if(NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_confg_t pin = {.port = led->port , .pin = led->pin , .direction = OUTPUT , .logic = led->status};
        ret = gpio_pin_toggle_logic(&pin);
    }  
    return ret;
}