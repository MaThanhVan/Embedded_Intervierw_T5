/*
* File: Manager.hpp
* Author: MA THANH VAN
* Date: 07/08/2023
* Description: This is file for management table
*/
#ifndef __TABLE_H
#define __TABLE_H

#include "Dish.hpp"
#include "Manager.hpp"

class Information_of_a_Table : public Manager
{
private:

    uint8_t number_of_Table;
    bool status;

    typedef struct{
        Dish dish_in_Table;
        int number_of_Dish;

    }TypeDish;

    list<TypeDish> dish_Information_of_a_Table;

public:

    Information_of_a_Table(uint8_t numberOfTable, bool status);
    
    uint8_t getNumberOfTable();
    bool setStatus(bool status);
    bool getStatus();
    void getListDish();

    void addDishInTheTable();
    void fixDishInTheTable();
    void deleteDish(uint8_t id);
};




#endif