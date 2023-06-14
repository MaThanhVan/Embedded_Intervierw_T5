/*
* File Name: main.c
* Author: MA THANH VAN
* Date: 13/06/2023
* Description: Using a basic caculate in a string to store and manage a list of data.
*/

#include "Basic_Calculation.c"

 int main(int argc, char const *argv[])
{
    char input[] = "10 + 8 - 614 + 7 - 532 * 2";
    typeMaths ouput[20];
    String(input, ouput);
    return 0;
}
