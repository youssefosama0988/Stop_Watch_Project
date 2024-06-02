/* 
 * File:   7_seg.h
 * Author: Admin
 *
 * Created on February 12, 2024, 2:42 PM
 */


    /* Section : Includes */
    #include "../../MCAL_Layer/GPIO/hal_gpio.h"

    /* Section: Macro Declarations */
    #define SEGEMENT_PIN0 0
    #define SEGEMENT_PIN1 1
    #define SEGEMENT_PIN2 2
    #define SEGEMENT_PIN3 3

    /* Section: Macro Functions Declarations */

    /* Section: Data Type Declarations */
    typedef enum{
        SEGMENT_COMMON_ANODE,
        SEGMENT_COMMON_CATHODE
    }segment_type_t;

    typedef struct{
        pin_confg_t segment_pins[4];
        segment_type_t segment_type;
    }segment_t;

    /* Section: Function Declarations */
    Std_ReturnType seven_segement_intialize(const segment_t *seg);
    Std_ReturnType seven_segement_write_number(const segment_t *seg, uint8 number);



