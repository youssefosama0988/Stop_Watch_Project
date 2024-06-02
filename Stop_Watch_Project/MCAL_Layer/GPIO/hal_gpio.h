

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


#include "../../MCAL_Layer/mcal_std_types.h"
#include "../../MCAL_Layer/confg.h"

#define _XTAL_FREQ       8000000
#define MAX_PIN_SIZE     7
#define MAX_PORT_SIZE    4
#define PORT_MASK        0xff

/* macro Functions Declarations */
#define HWREG8 (__x)     (*((volatile uint8 *)(__x)))

#define SET_BIT(REG,BIT_POSN)       (REG |= (1 << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)     (REG &= ~(1 << BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)    (REG ^= (1 << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)      ( (REG>>BIT_POSN) & (uint8)1 )

typedef enum{
    LOW=0,
    HIGH
}logic_t;

typedef enum{
    OUTPUT=0,
    INPUT
}direction_t;

typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct {
    uint8 port      :3;         /* @ref port_index_t */
    uint8 pin       :3;         /* @ref pin_index_t */
    uint8 direction :1;         /* @ref direction_t */
    uint8 logic     :1;         /* @ref logic_t */
}pin_confg_t;

Std_ReturnType gpio_pin_direction_initialize(const pin_confg_t * pin);
Std_ReturnType gpio_pin_direction_initialize_write(const pin_confg_t * pin);
Std_ReturnType gpio_pin_get_direction_status(const pin_confg_t * pin , direction_t * direction);
Std_ReturnType gpio_pin_write_logic(const pin_confg_t * pin , logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_confg_t * pin , logic_t * logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_confg_t * pin);

Std_ReturnType gpio_port_direction_initialize(port_index_t port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port , uint8 * direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t port , uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port , uint8 * logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port );

#endif	/* HAL_GPIO_H */

