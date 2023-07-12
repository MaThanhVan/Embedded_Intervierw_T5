/*
* File: Staff.hpp
* Author: MA THANH VAN
* Date: 07/08/2023
* Description: This is file have staff person in restaurant
*/
#ifndef __STAFF_H
#define __STAFF_H

#include "Dish.hpp"
#include "Manager.hpp"
#include "Table.hpp"

using namespace std;

class Staff_in_Restaurant : public Information_of_a_Table
{
private:
    list<Dish> DataDish;
    list<Information_of_a_Table> Data_table_dinner;
    bool Status;
    
public:
    Staff_in_Restaurant();
    void Display_Information_Table();

};


#endif