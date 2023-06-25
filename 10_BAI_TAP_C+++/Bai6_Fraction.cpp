#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

using namespace std;

class Fraction
{
protected:
    /* data */
    int8_t Numerator;
    int8_t Denominator;
public:
    Fraction(int8_t Numerator = 1, int8_t Denominator = 1);
     int8_t getNumerator();
     int8_t getDenominator();
    
    
};

Fraction::Fraction(int8_t Numerator, int8_t Denominator){
    this->Numerator = Numerator;
    this->Denominator = Denominator;

}
int8_t Fraction::getNumerator(){
    return this->Numerator;
}
int8_t Fraction::getDenominator(){
    return this->Denominator;
}

class Calculate
{
private:
    Fraction fractionA;
    Fraction fractionB;
public:
    Calculate(Fraction fractionA, Fraction fractionB);
    void Addition(Fraction fractionA, Fraction fractionB);
    void Subtraction(Fraction fractionA, Fraction fractionB);
    void Multiplication(Fraction fractionA, Fraction fractionB);
    void Division(Fraction fractionA, Fraction fractionB);
};

Calculate::Calculate(Fraction fractionA, Fraction fractionB){
    this->fractionA = fractionA;
    this->fractionB = fractionB;
}


void Calculate::Addition(Fraction fractionA, Fraction fractionB){
    int8_t denominator, numerator;
    
    if(fractionA.getDenominator() != fractionB.getDenominator()){
        numerator = (fractionA.getNumerator() * fractionB.getDenominator()) + (fractionB.getNumerator() * fractionA.getDenominator());
        denominator = (fractionA.getDenominator() * fractionB.getDenominator());
    }
    else{
        numerator = fractionA.getNumerator() + fractionB.getNumerator();
        denominator = fractionA.getDenominator();
    }
    printf("Addition fractionA and fractionB is %d/%d\n", numerator, denominator);
}

void Calculate::Subtraction(Fraction fractionA, Fraction fractionB){
    int8_t denominator, numerator;
    
    if(fractionA.getDenominator() != fractionB.getDenominator()){
        numerator = (fractionA.getNumerator() * fractionB.getDenominator()) - (fractionB.getNumerator() * fractionA.getDenominator());
        denominator = (fractionA.getDenominator() * fractionB.getDenominator());
    }
    else{
        numerator = fractionA.getNumerator() - fractionB.getNumerator();
        denominator = fractionA.getDenominator();
    }
    printf("subtraction fractionA and fractionB is %d/%d\n", numerator, denominator);
}

void Calculate::Multiplication(Fraction fractionA, Fraction fractionB){
   int8_t denominator, numerator;
   numerator = fractionA.getNumerator() * fractionB.getNumerator();
   denominator = fractionA.getDenominator() * fractionB.getDenominator();
    printf("Multiplication fractionA and fractionB is %d/%d\n", numerator, denominator);
}

void Calculate::Division(Fraction fractionA, Fraction fractionB){
   int8_t denominator, numerator;
   numerator = fractionA.getNumerator() * fractionB.getDenominator();
   denominator = fractionA.getDenominator() * fractionB.getNumerator();
    printf("division fractionA and fractionB is %d/%d\n", numerator, denominator);
}


int main(int argc, char const *argv[])
{
    Fraction fractionA(4, 5);
    Fraction fractionB(3, 5);

    Calculate calFraction(fractionA, fractionB);
    calFraction.Addition(fractionA, fractionB);
    calFraction.Subtraction(fractionA, fractionB);
    calFraction.Multiplication(fractionA, fractionB);
    calFraction.Division(fractionA, fractionB);

    return 0;
}






