#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct 
{
    char *array;
    uint8_t size_t;
}Words;

Words words[100];

void splitArray(char arr[]){
    Words word;
    int size;
    int count = 0;
    int index = 0;
    for(int i = 0; i<100; i++){
        if(arr[i] == ' ' && arr[i] == '.' && arr[i] == '!')
        {
            
            word.size_t = count;
            word.array = (arr - count);
            words[index] = word;
            index++;
            count = 0;
        }
        else {
           count ++;
        }
        
        

        
    }
    word.size_t = size;
   for(int i=0; i <= size; i++){
        printf("\n%c", arr[i]);
   }
}


bool isEqual(const char arr1[], const char arr2[], int size1)
{
    int dem = 0;
    for(int i = 1; i <= 10; i++ )
    {
        uint8_t KQ;
        KQ = arr1[i] - arr2[i];
        if(KQ == 0)
        {
            dem ++;
        }
        else{
            printf("false");
            return false;
            
        }
        if(dem == size1){
            printf("true");
            return true;
        }
    
    }
}



int main()
{
    char arr1[] = {"motj hai"};
    char arr2[] = {"motl"};

    int size1 = sizeof (arr1) - 1;
    int size2 = sizeof(arr2) - 1 ;
    //printf("%d", size);
   //isEqual(arr1, arr2, size1);
    splitArray(arr1);
}