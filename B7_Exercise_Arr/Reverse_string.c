#include <stdio.h>
#include <stdint.h>


int main()
{
    char arr[] = {"mot hai ba bon nam sau"};
    int size = sizeof(arr) / sizeof(arr[0]);
    int prei = size-1;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] == ' ' || i == 0) {
            if (i == 0) {
                for (int j = i; j <= prei; j++) {
                    printf("%c", arr[j]);
                }
            }
             if(i != 0) {
                for (int j = i + 1; j <= prei; j++) {
                    printf("%c", arr[j]);
                }
                printf(" ");
            }
            prei = i - 1;
        }
    }
    printf("\n");
}
