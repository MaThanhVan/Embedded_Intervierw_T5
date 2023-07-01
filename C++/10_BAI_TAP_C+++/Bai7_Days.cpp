#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

class Days
{
private:
    int8_t DAY;
    int8_t MONTH;
    int16_t YEAR;
public:
    Days(int8_t DAY, int8_t MONTH, int16_t YEAR);
    int checkLeapYear(int16_t YEAR);
    int8_t getDay();
    int8_t getMonth();
    int16_t getYears();
    void checkHoliDays(int8_t day, int8_t month, int16_t year);
    void CalculateAge_Person( int16_t year);
};

int Days::checkLeapYear(int16_t YEAR){
    if(YEAR % 400 == 0){
        return 1;
    }
    else{
        return 0;
    }
    if((YEAR % 4 == 0) && (YEAR % 100 != 0)){
        return 1;    
    }
    else{
        return 0;
    }
}

Days::Days(int8_t day, int8_t month, int16_t year){
    switch (month)
    {
    case 2:
        if(checkLeapYear(year) == 1 ){
            if(day > 29){
                printf("Ban da nhap sai hay nhap lai ngay <= 29");
            }
            else{
                this->DAY = day;
            }
        }
        else{
            if(day > 28){
                printf("Ban da nhap sai hay nhap lai ngay <= 28");
            }
            else{
                this->DAY = day;
            }
        }
        break;
    
    case 4:
        if(day > 30 ){
            printf("Ban nhap ngay sai hay nhap lai ngay <= 30");
        }
        else{
            this->DAY = day;
        }

    case 6:
        if(day > 30 ){
            printf("Ban nhap ngay sai hay nhap lai ngay <= 30");
        }
        else{
            this->DAY = day;
        }
    
    case 9:
        if(day > 30 ){
            printf("Ban nhap ngay sai hay nhap lai ngay <= 30");
        }
        else{
            this->DAY = day;
        }
    case 11:
        if(day > 30 ){
            printf("Ban nhap ngay sai hay nhap lai ngay <= 30");
        }
        else{
            this->DAY = day;
        }
    
    default:
        if((month > 12) || (day > 31)){
            printf("Ban da nhap sai hay nhap lai ");
        }
        break;
    }
    this->MONTH = month;
    this->YEAR = year;
}

int8_t Days::getDay(){
    return this->DAY;
}

int8_t Days::getMonth(){
    return this->MONTH;
}

int16_t Days::getYears(){
    return this->YEAR;
}

void Days::checkHoliDays(int8_t day, int8_t month, int16_t year){
    if((day == 1) && (month == 1)){
        printf("Happy news year\n");
    }
    else if((day == 10) && (month == 3)){
        printf("Hung Kings Commemorations\n");
    }
    else if((day == 30) && (month == 4)){
        printf("Liberation Day\n");
    }
    else if((day == 1) && (month == 5)){
        printf("International Worker's Day\n");
    }
    else if((day == 2) && (month == 9)){
        printf("National Day\n");
    }
    else{
        printf("It's not a holidays\n");
    }

}


void Days::CalculateAge_Person( int16_t year){
    int a =0;
    a = 2023 - year; 
    printf("that person is %d Age\n", a);
}

int main(int argc, char const *argv[])
{
    Days DAY(20,8,2015);
    DAY.CalculateAge_Person(2001);
    DAY.checkHoliDays(1,5,2023);
    return 0;
}

