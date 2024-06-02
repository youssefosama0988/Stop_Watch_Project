/* 
 * File:   mcal_std_types.h
 * Author: Admin
 *
 * Created on February 4, 2024, 1:32 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

#include "std_libraries.h"
#include "compiler.h" 

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

typedef uint8 Std_ReturnType;

#define E_OK          (Std_ReturnType)0x01
#define E_NOT_OK      (Std_ReturnType)0x00

#define STD_HIGH     0x01
#define STD_LOW      0x00

#define STD_ACTIVE   0x01
#define STD_IDLE     0x00

#define STD_ON       0x01
#define STD_OFF      0x00

#endif	/* MCAL_STD_TYPES_H */

