/*
* File: Staff.cpp
* Author: MA THANH VAN
* Date: 07/08/2023
* Description: This is file have function for management dinner table
*/

#include "Dish.hpp"
#include "Manager.hpp"
#include "Table.hpp"
#include "Staff.hpp"

Staff_in_Restaurant::Staff_in_Restaurant(){

    if(this->getTable() == 0 && DataDish.size() == 0){
        cout << "is not have any Dish and table dinner" << endl;
    }
    else{
        for (int i = 1 ; i <= this->getTable(); i++)
        {
            Information_of_a_Table Table(i, false);
            Data_table_dinner.push_back(Table);
        }
    }

    int orderTable;
    this->Display_Information_Table();
    cout << "Enter the number of order table ";
    cin >> orderTable;

    for(auto item : Data_table_dinner){
        if(item.getTable() == orderTable){
            int choose;
            cout << "1. Add Dish in the table" << endl;
            cout << "2. Fix Dish in the table" << endl;
            cout << "3. Delete Dish in the table" << endl;
            cout << "4. Display infomation Dish in the table" << endl;
            cout << "5. Pay for the dinner" << endl;
            cout << "0. Exit" << endl;
            cout << "please choose a function" << endl;
            cin >> choose;
            switch (choose)
            {
            case 1:
                this->addDishInTheTable(orderTable);
                break;

            case 2:
                this->fixDishInTheTable();
                break;

            case 3:
                this->deleteDish();
                break;

            case 4:
                this->displayDish();
                break;
            
            case 5:
            
            default:
                break;
            }
        }
    }   
}

void Staff_in_Restaurant::Display_Information_Table(){
    cout << "-------------- Status Table ---------------------";
    cout << " " << this->getNumberOfTable();
    cout << " " << this->getStatus();

}


