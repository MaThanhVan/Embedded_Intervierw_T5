/*
* File: Manager.hpp
* Author: MA THANH VAN
* Date: 07/08/2023
* Description: This is file for management person
*/
#ifndef __MANAGER_H
#define __MANAGER_H

#include "Dish.hpp"



class Manager
{
    private:
        uint8_t table;

        void addDish();
        void fixTheDish();
    
        void addTable();
        void deleteDish();

    public:
        list<Dish> &dataDish;
        Manager(); // nhap thong tin switch case
        
        list<Dish> &getDataDish();
        uint8_t getTable();
        void displayDish();

};


#endif