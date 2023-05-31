#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t arr[10] = {1,1,1,2,2,5,6,6,7,7};
    uint8_t temp = 1;
    int a = 1;
    for(int i = 0; i <= 10 - 1; i++){
        
        //printf("so %d xuat hien", arr[i]);
        for(int j = i + 1; j <= 10; j++){
            if(arr[i] == arr[j]){
                temp++;
                break;
            }
           else
            {
                printf("so %d xuat hien %d lan\n",arr[i], temp);
                temp = 1;
            }
        }
         
    }
}