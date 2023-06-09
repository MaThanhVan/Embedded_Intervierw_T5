/*
* File: B9_Exercise_Equation
* Author: MA THANH VAN
* Date: 8/06/2023
* Description: This is a file for caculate equation
*/

#include "EQUATION.h"


/*
* Function: fistDegreeEquation
* Description: This function use for caculate fist Degree Equation
* Input:
*   char pointer arr
* Output:
*   return: none
*/
void fistDegreeEquation(char *ptrarr)
{
    uint8_t a, b;
    char math;
    for(int i = 0; i <= strlen(ptrarr); i++)
    {
        if(ptrarr[i] == 'x'){
            a = ptrarr[i-1];
            math = ptrarr[i + 2];
        }
        if(ptrarr[i] == '\0'){
            b = ptrarr[i - 1];
        }
    }
    switch (math)
    {
    case '-':
        printf("\nban vua nhap phuong trinh bac nhat co nghiem x = %.2f", (float)(b/a));
        break;
    
    case '+':
        printf("\nban vua nhap phuong trinh bac nhat co nghiem x = %.2f", (float)(-b/a));
        break;
    }
}

/*
* Function: quadratic
* Description: This function use for caculate quadratic
* Input:
*   char pointer arr
* Output:
*   return: none
*/
void quadratic(char *ptrarr)
{
    float a, b, c, delta, x1, x2;
    for(int i = 0; i <= strlen(ptrarr); i++)
    {
        if(ptrarr[i] == '^'){
            a = ptrarr[i-1];
        }
        if((ptrarr[i] == 'x') && (i > 5)){
            if(ptrarr[i - 3] == '-'){
                b = ptrarr[i-1] * -1;
            }
            if(ptrarr[i - 3] == '+'){
                b = ptrarr[i-1];
            }
        }
        if(ptrarr[i] == '\0'){
            if(ptrarr[i - 3] == '-'){
                c = ptrarr[i-1] * -1;
            }
            if(ptrarr[i - 3] == '+'){
                c = ptrarr[i-1];
            }
        }
    }
    delta = pow(b, 2) - 4*a*c;
    if(delta > 0){
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        printf("phuong trinh co hai nnghiem phan biet la x1 = %.2f x2 =%.2f\n", x1,x2);

    }
    else if(delta == 0){
        x1 = -b/(2*a);
        printf("Phuong trinh co nghiem kep  x1=x2= %.2f\n", x1);
    }
    else{
        printf("phuong trinh vo ngiem\n");
    }
}

/*
* Function: check_Equation
* Description: This function use for check Equation
* Input:
*   char pointer arr
* Output:
*   return: none
*/
void check_Equation(char *ptrarr)
{
    
    for( int i = 0; i <= strlen(ptrarr); i++){
        if (ptrarr[i] == '^')
        {
            quadratic(ptrarr);
            return;
        }
    }
    fistDegreeEquation(ptrarr);
}