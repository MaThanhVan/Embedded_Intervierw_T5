#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class People
{
    private:
        string Name;
        uint8_t Age;
        string Address;
        
    public:
        People(string Name, uint8_t Age, string Address);
        string getName();
        uint8_t getAge();
        string getAddress();
        void Display();
        uint8_t Caculate();
};

People::People(string name, uint8_t age, string address){
    this->Name = name;
    this->Age = age;
    this->Address = address;

}

string People::getName(){
    return this->Name;
}

uint8_t People::getAge(){
    return this->Age;
}

string People::getAddress(){
    return this->Address;
}

void People::Display(){
    cout<<"Ten:" <<this->Name<<endl;
    cout<<"Tuoi:"<<this->Age<<endl;
    cout<<"Dia chi: "<<this->Address<<endl;

}

int main()
{
    People peo("nhj", 24, "52 bb");
    peo.Display();
    return 0;
}
