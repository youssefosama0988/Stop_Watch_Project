

#include "../ECU_Layer/button/ecu_button.h"

Std_ReturnType button_initialize(const button_t * button){
    Std_ReturnType ret = E_OK;
    
    if(NULL == button ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize(&(button->button_pin));
    }
    return ret;
}


Std_ReturnType button_read_state(const button_t * button , button_state_t * state){
    Std_ReturnType ret = E_OK;
    logic_t logic=LOW;
    
    if(NULL == button || NULL == state ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_read_logic(&(button->button_pin), &logic);
        if(BUTTON_ACTIVE_HIGH == button->button_connection){
            
            if(HIGH == logic){
                *state = BUTTON_PRESSED;
            }
            else{
                *state = BUTTON_RELEASED;
            }
            
        }
        else if(BUTTON_ACTIVE_LOW == button->button_connection){
            if(LOW == logic){
                *state = BUTTON_PRESSED;
            }
            else{
                *state = BUTTON_RELEASED;
            }
        }
        else{/*nothing*/}   
    }
    return ret;
}