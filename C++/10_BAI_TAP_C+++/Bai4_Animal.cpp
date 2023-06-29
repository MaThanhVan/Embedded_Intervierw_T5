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

float Animal::BMI(){
    return Weight / (pow((Height),2));
}

class compareAnimal
{
private:
    Animal animalA;
    Animal animalB;
    
public:
    compareAnimal(Animal animalA, Animal animalB);
    void compareAge();
    void compareWeight();
};

compareAnimal::compareAnimal(Animal animalA, Animal animalB){
    this->animalA = animalA;
    this->animalB = animalB;
}

void compareAnimal::compareAge(){
    if(animalA.getAge() == animalB.getAge()){
        printf("\nanimalA and animalB have age age the same is %s", animalA.getAge());
    }
    else if(animalA.getAge() > animalB.getAge()){
        printf("\nanimalA have age %s is larger than animalB have age is %s", animalA.getAge(), animalB.getAge());
    }
    else {
        printf("\nanimalA have age %s is lighter than animalB have age is %s", animalA.getAge(), animalB.getAge());
    }
}

void compareAnimal::compareWeight(){
    if(animalA.getWeight() == animalB.getWeight()){
        printf("\nanimalA and animalB have weight weight the same is %s", animalA.getWeight());
    }
    else if(animalA.getAge() > animalB.getAge()){
        printf("\nanimalA have weight %s is larger than animalB have weight is %s", animalA.getWeight(), animalB.getWeight());
    }
    else {
        printf("\nanimalA have weight %s is lighter than animalB have weight is %s", animalA.getWeight(), animalB.getWeight());
    }
}



int main(int argc, char const *argv[])
{
    Animal AnimalA("chicken", 3, 1, 3), AnimalB("duck", 3, 2, 3);
    printf("BMI AnimalA is %.2f,  BMI Animalb is %.2f", AnimalA.BMI(), AnimalB.BMI());

    compareAnimal typesAnimal(AnimalA, AnimalB);
    typesAnimal.compareAge();
    typesAnimal.compareWeight();
    return 0;
}