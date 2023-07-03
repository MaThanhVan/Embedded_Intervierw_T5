#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

using namespace std;

typedef enum{
    Black,
    White,
    Red,
    Green
}Color;

typedef enum{
    Honda,
    Toyota,
    Mazda,
    Subaru
}Engine;

class Cars
{
private:
    Color typeColor;
    Engine typeEngine;
    uint64_t Kilometers;
public:
    C
    COLOR getColor();
    uint32_t getEngine();
    void MaintenanceFee();
    void DisplayInformation();
};

Color Cars::getColor(){

}
