#include <stdio.h>
#include <stdint.h>




int main()
{
    uint8_t arr[] = {1,9,8,5,7,4,6,3,2,14};
     
     for(int i=0; i<=10 - 1; i++){
        for(int j = i+1; j<=10; j++)
        {
            if(arr[i] > arr[j])
            {
               
                int temp = arr[i] ;
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("cac phan tu cua mang = ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", arr[i]);
    }

}