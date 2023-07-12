/*
* File: Dish.hpp
* Author: MA THANH VAN
* Date: 07/08/2023
* Description: This is file for dish management 
*/
#ifndef __DISH_H
#define __DISH_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <list>

using namespace std;

/*This is define for choose function*/

#define KEY_INPUT(function, ...)                            \
    void function(void (*arr[])()){                         \
                                                            \
        cout << "Function!!!" << #function << endl;         \
        int choose = 0;                                     \
        do                                                  \
        {                                                   \
            __VA_ARGS__                                     \
            cout << " Enter your choose"  << endl;          \
            cout << "0. Exit" << endl;                      \
            cin >> choose;                                  \
                                                            \
        } while (1);                                        \
                                                            \
    }                  
                                                            
                                                      
 
#define KEY(key) key

#define NAME(name) name

#define DISPLAY(key, name)                                  \
    cout << " " << key << ".  " << name << endl;            \


#define IF(key, name)                                       \
    if(choose == key){                                      \
        cout << "Your choose %s" << name << endl;           \
        arr[key-1]();                                       \
    } 
    
#define KEY_VALUE(key, name)                                \
DISPLAY(key, name)                                          \
IF(key, name)                           



class  Dish
{
private:

    uint8_t id;
    string name;
    double price;

public:
    Dish(uint8_t id = 1, string name = " ", double price = 0);
    uint8_t getID();
    string getName();
    double getPrice();
    void getListDish();

    void setID();
    string setName(string name);
    double setPrice(double price);
    
};



#endif