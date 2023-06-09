
#include "equation.c"


int main(int argc, char const *argv[])
{
    char arr[20];

    printf("Enter your eqution: ");
    fgets(arr, sizeof(arr), stdin);

    check_Equation(arr);

}