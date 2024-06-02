




#include "hal_gpio.h"

volatile uint8 * tris_registers[] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 * lat_registers [] = {&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 * port_registers[] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
/**
 * 
 * @param pin pointer to the configurations @ref pin_confg_t  
 * @return Function Status 
 *         E_OK if excuted successfully 
 *         E_NOT_OK if excuted unsuccessfully
 */
Std_ReturnType gpio_pin_direction_initialize_write(const pin_confg_t * pin){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  pin || pin->pin > MAX_PIN_SIZE){
         ret = E_NOT_OK;
    }
    else{
        switch(pin->direction){
            case OUTPUT :
                CLEAR_BIT(*tris_registers[pin->port] ,pin->pin );
                break;
                
            case INPUT :
                SET_BIT(*tris_registers[pin->port] ,pin->pin );                
                break;
                
            default: ret = E_NOT_OK;
        }
        ret = gpio_pin_write_logic(pin , pin->logic);
    }
    return ret;
}
Std_ReturnType gpio_pin_direction_initialize(const pin_confg_t * pin){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  pin || pin->pin > MAX_PIN_SIZE){
         ret = E_NOT_OK;
    }
    else{
        switch(pin->direction){
            case OUTPUT :
                CLEAR_BIT(*tris_registers[pin->port] ,pin->pin );
                break;
                
            case INPUT :
                SET_BIT(*tris_registers[pin->port] ,pin->pin );                
                break;
                
            default: ret = E_NOT_OK;
        }
    }
    return ret;

}
/**
 * 
 * @param pin pointer to the configurations @ref pin_confg_t
 * @param direction
 * @return Function Status 
 *          E_OK if excuted successfully 
 *          E_NOT_OK if excuted unsuccessfully
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_confg_t * pin , direction_t * direction){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  pin || NULL == direction || pin->pin > MAX_PIN_SIZE){
        ret = E_NOT_OK;
    }
    else{
        *direction = READ_BIT(*tris_registers[pin->port] ,pin->pin);
    }
    return ret;
}

/**
 * 
 * @param pin pointer to the configurations @ref pin_confg_t
 * @param logic
 * @return Function Status 
 *          E_OK if excuted successfully 
 *          E_NOT_OK if excuted unsuccessfully
 */
Std_ReturnType gpio_pin_write_logic(const pin_confg_t * pin , logic_t logic){
    Std_ReturnType ret = E_OK;
    if(NULL ==  pin || pin->pin > MAX_PIN_SIZE){
        ret = E_NOT_OK;
    
    }
    else{
        switch(logic){
            case LOW :
                CLEAR_BIT(*lat_registers[pin->port] ,pin->pin );
                break;
                
            case HIGH :
                SET_BIT(*lat_registers[pin->port] ,pin->pin );     
                break;
                
            default: ret = E_NOT_OK;
        }    
        
    }
    
    return ret;
}

/**
 * 
 * @param pin pointer to the configurations @ref pin_confg_t
 * @param logic
 * @return Function Status 
 *          E_OK if excuted successfully 
 *          E_NOT_OK if excuted unsuccessfully
 */
Std_ReturnType gpio_pin_read_logic(const pin_confg_t * pin , logic_t * logic){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  pin || NULL == logic || pin->pin > MAX_PIN_SIZE){
        ret = E_NOT_OK;    
    }
    else{
        *logic = READ_BIT(*port_registers[pin->port] ,pin->pin);
    }  
    return ret;
}

/**
 * 
 * @param pin pointer to the configurations @ref pin_confg_t  
 * @return Function Status 
 *          E_OK if excuted successfully 
 *          E_NOT_OK if excuted unsuccessfully
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_confg_t * pin){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  pin || pin->pin > MAX_PIN_SIZE){
        ret = E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*lat_registers[pin->port] ,pin->pin);
    }    
    return ret;
}

/**
 * 
 * @param port
 * @param direction
 * @return Function Status 
 *          E_OK if excuted successfully 
 *          E_NOT_OK if excuted unsuccessfully
 */
Std_ReturnType gpio_port_direction_initialize(port_index_t port , uint8 direction){
    Std_ReturnType ret = E_OK;
    
    if(port > MAX_PORT_SIZE){
        ret = E_NOT_OK;
    }
    else{
        *tris_registers[port] = direction;
    }   
    return ret;
}

/**
 * 
 * @param port
 * @param direction_status
 * @return 
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port , uint8 * direction_status){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  direction_status || port > MAX_PORT_SIZE){
        ret = E_NOT_OK;
    }
    else{
        *direction_status = *tris_registers[port];
    }   
   return ret;
}

/**
 * 
 * @param port
 * @param logic
 * @return Function Status 
 *          E_OK if excuted successfully 
 *          E_NOT_OK if excuted unsuccessfully
 */
Std_ReturnType gpio_port_write_logic(port_index_t port , uint8 logic){
    Std_ReturnType ret = E_OK;
    
    if(port > MAX_PORT_SIZE){
        ret = E_NOT_OK;
    }
    else{
        *lat_registers[port]=logic;
    }   
    return ret;
}

/**
 * 
 * @param port
 * @param logic
 * @return 
 */
Std_ReturnType gpio_port_read_logic(port_index_t port , uint8 * logic){
    Std_ReturnType ret = E_OK;
    
    if(NULL ==  logic || port > MAX_PORT_SIZE){
        ret = E_NOT_OK;
    }
    else{
        * logic = *lat_registers[port];
    }
    return ret;
}

/**
 * 
 * @param port
 * @return Function Status 
 *          E_OK if excuted successfully 
 *          E_NOT_OK if excuted unsuccessfully
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port ){
    Std_ReturnType ret = E_OK;
    
    if(port > MAX_PORT_SIZE){
        ret = E_NOT_OK;
    }
    else{
        *lat_registers[port] ^= PORT_MASK; 
    }

    return ret;
}
