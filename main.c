#include <stdio.h>
#include <stdint.h>


void readByte(uint8_t byte){
    uint8_t temp = 0b10000000;
    uint8_t temp2;
    printf("0b");
    for(int i = 0; i <= 8; i++)
    {
        temp2 = temp & byte;
        if(temp2 == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        byte = byte << 1;
    }
    printf("\n");
}
int main()
{
    uint8_t test = 0b10010001;
    readByte(test);
    
}