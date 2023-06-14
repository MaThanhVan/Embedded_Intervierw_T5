/*
* File Name: Basic_Calculation.h
* Author: MA THANH VAN
* Date: 13/06/2023
* Description: This file is a header file that contains a data type definition and functions definition to use a Basic calculation to store and manage a list of data.  
*/

#ifndef __TEST_H
#define __TEST_H
#include <stdio.h>
#include <stdint.h>

typedef  enum{
    NUMBER,
    OPERATOR,
}TypeMath;

typedef struct{
    TypeMath key;
    union 
    {
        uint16_t number;
        char opera;
    }value;
    
}typeMaths;

void String(char input[], typeMaths ouput[]);       // use for save input string of type numbers and calculations



#endif
