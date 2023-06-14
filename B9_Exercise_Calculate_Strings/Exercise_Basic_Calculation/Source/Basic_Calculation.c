/*
* File: Basic_Calculation.c
* Author: MA THANH VAN
* Date: 13/06/2023
* Description: This is a file for basic caculate in a string
*/


#include "Basic_Caculation.h"


/*
* Function: Basic_Calculation
* Description: This function use for caculate basic calculate in a string
* Input:
*   string of characters name input of type char
*    string of characters name ouput of type struct
* Output:
*   return: none
*/
void String(char input[], typeMaths ouput[])
{
    static uint16_t number = 0;
    uint8_t i = 0;
    while ( *input != '\0')
    {
        
        if(*input >= '0' && *input <= '9')
        {
            uint8_t temp = *input - '0';
            number = 10 * number + temp;
            input++;
            continue;       // den day se dung cac lenh phis duoi, quay lai doc thang tiep theo
        }
        else if(*input == '+' || *input == '-' || *input == '*' || *input == '/')
        {
            ouput[i].key = OPERATOR;
            ouput[i].value.opera = *input;
            input++;
            i++;
            continue;
        }
        else{
            if(number != 0){

                ouput[i].key = NUMBER;
                ouput[i].value.number = number;
                i++;
                number = 0;
            }
        }
        input++;
        
    }
    ouput[i].key = NUMBER;
    ouput[i].value.number = number;
    
}

