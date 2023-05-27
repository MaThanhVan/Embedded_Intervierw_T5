#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00000000;
uint8_t PORTB = 0b11111111;
uint8_t PORTC = 0b11111111;

typedef enum{
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7

}pins;

typedef enum{
    LOW,
    HIGHT
}Status;

void readByte(uint8_t byte){
    uint8_t temp = 0b10000000;
    uint8_t temp2;
    printf("0b");
    for(int i = 0; i < 8; i++)
    {
        temp2 = temp & byte;
        if(temp2 != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        byte = byte << 1;
    }
    printf("\n");
}

void pinHight(pins PIN){
    PORTA = PORTA | (1 << PIN);    
}
/*
    ///   (0b00000001 << 4) = 0b00001000
             OR  0b00000000 | 0b000001000
                     == 0b000001000
*/

void pinLow(pins PIN){
    PORTB = PORTB ^ (1 << PIN);    /// 1 = 0b00000001
}

void digitalWrite(pins PIN, Status status){
    if(status == LOW){
        PORTC = PORTC ^ (1 << PIN);
    }
    if(status == HIGHT){
        PORTC = PORTC | (1 << PIN); 
    }
}

int main()
{
    pinHight(PIN4);

    pinLow(PIN3);

    digitalWrite( PIN4, LOW);

    readByte(PORTA);
    readByte(PORTB);
    readByte(PORTC);
}