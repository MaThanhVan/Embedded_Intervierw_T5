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

void String(char input[], typeMaths ouput[]);



#endif
