#include <stdint.h>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

class Animal
{
private:
    /* data */
    string Name;
    uint8_t Age;
    uint8_t Weight;
    uint8_t Height;
public:
    Animal(string name = " ", uint8_t age = 0, uint8_t weight = 0, uint8_t hight = 0 );
    string getName();
    uint8_t getAge();
    uint8_t getWeight();
    uint8_t getHight();
    float BMI();
};

Animal::Animal(string name, uint8_t age, uint8_t weight, uint8_t height)
{
    this->Name = name;
    this->Age = age;
    this->Weight = weight;
    this->Height = height;

}

string Animal::getName(){
    return this->Name;
}

uint8_t Animal::getAge(){
    return this->Age;
}

uint8_t Animal::getWeight(){
    return this->Weight;
}

uint8_t Animal::getHight(){
    return this->Height;
}

class compareAnimal
{
private:
    /* data */
    
public:
    compareAnimal(uint8_t AnimalA, uint8_t AnimalB);
};

Bai4_Animal::Bai4_Animal(/* args */)
{
}

Bai4_Animal::~Bai4_Animal()
{
}




int main(int argc, char const *argv[])