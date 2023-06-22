#include <stdint.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Circle
{
    private:
        /* data */
        double circleRadius;
    public:
        Circle(double circleRadius);
        double getcircleDiameter();
        double getcircleArea();
};

Circle::Circle(double Radius)
{
    this->circleRadius = Radius;

}


double Circle::getcircleArea(){
    return (double) (pow(this->circleRadius,2)  * 3.14);
}

double Circle::getcircleDiameter(){
    return (double) ((this->circleRadius) * 2 * 3.14);
}

int main(int argc, char const *argv[])
{
    Circle HinhTron(2.6);
    printf("Dien tich hinnh tron = %.2f\n", HinhTron.getcircleArea());
    printf("Chu vi hinh tron = %.2f", HinhTron.getcircleDiameter());
}