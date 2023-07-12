/*
* File: Dish.cpp
* Author: MA THANH VAN
* Date: 07/08/2023
* Description: This is file have function for dish management 
*/

#include "Restaurant_Manager/Header/Dish.hpp"


/*
* Class: Dish
* Function: getListDish
* Description: This function use for get list dish
* Input:
*   none
* Output:
*   return: None
*/
void Dish::getListDish(){
    cout << "ID\t" << "Name\t" << "Price" << endl;
    cout << " " << id << "\t" << " " << name << "\t" << " " << price << endl;
}


/*
* Class: Dish
* Function: set_ID
* Description: This function use for set ID of a dish
* Input:
*   none
* Output:
*   return: None
*/
void Dish::setID(){
    static uint8_t idTemp = 1;
    id = idTemp;
    id++;
    this->id = idTemp;
}

/*
* Class: Dish
* Function: getListDish
* Description: This function use for get list dish
* Input:
*   none
* Output:
*   return: ID
*/
uint8_t Dish::getID(){
    return this->id;
}

/*
* Class: Dish
* Function: setName
* Description: This function use for set name dish
* Input:
*   string name
* Output:
*   return: None
*/
string Dish::setName(string name){
    this->name = name;
}

/*
* Class: Dish
* Function: getName
* Description: This function use for get name dish
* Input:
*   None
* Output:
*   return: Name
*/
string Dish::getName(){
    return this->name;
}

/*
* Class: Dish
* Function: setPrice
* Description: This function use for set Price dish
* Input:
*   double price
* Output:
*   return: None
*/
double Dish::setPrice(double price){
    this->price = price;
}

/*
* Class: Dish
* Function: getPrice
* Description: This function use for get Price dish
* Input:
*   None
* Output:
*   return: Price
*/
double Dish::getPrice(){
    return this->price;
}