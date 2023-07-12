/*
* File: Table.cpp
* Author: MA THANH VAN
* Date: 07/08/2023
* Description: This is file have function for management dinner table
*/

#include "Restaurant_Manager/Header/Staff.hpp"

/*
* Class: Information_of_a_Table
* Function: Information_of_a_Table
* Description: This function use for set up number and status of dinner table
* Input:
*   uint8_t NumberOfTable
    bool    Status
* Output:
*   return: None
*/
Information_of_a_Table::Information_of_a_Table(uint8_t numberOfTable, bool status)
{
    this->number_of_Table = numberOfTable;
    this->status = status;
}

/*
* Class: Information_of_a_Table
* Function: getNumberOfTable
* Description: This function use for get number of dinner table
* Input:
*   None
* Output:
*   return: None
*/
uint8_t Information_of_a_Table::getNumberOfTable(){
    return this->number_of_Table;
}

/*
* Class: Information_of_a_Table
* Function: setStatus
* Description: This function use for set status of dinner table
* Input:
*   bool status
* Output:
*   return: None
*/
bool Information_of_a_Table::setStatus(bool status){
    this->status = status;
}

/*
* Class: Information_of_a_Table
* Function: getStatus
* Description: This function use for get status of dinner table
* Input:
*   None
* Output:
*   return: Status
*/
bool Information_of_a_Table::getStatus(){
    return this->status;
}

/*
* Class: Information_of_a_Table
* Function: AddDishInTheTable
* Description: This function use for add dish in the dinner table
* Input:
*   None
* Output:
*   return: Status
*/
void Information_of_a_Table::addDishInTheTable(){
    int id, numberDish;
    this->displayDish();
    
    cout << "----------------------------- Please choose Id the Dish ---------------------------" << endl;
    cin >> id;
    for (Dish item : dataDish)
    {
        if(item.getID() == id){
            cout << "Food with id " << id << "" << item.getName() << endl;
            cout << "Enter the number of dish = " << endl;
            cin >> numberDish;
            TypeDish dishTable;
            dishTable.dish_in_Table = item;
            dishTable.number_of_Dish = numberDish;
            cout << "Add dish to the table finish" << endl;
            break;
        }
        else{
            cout << "is not any dish have id " << id << endl;
        }
    }
    
}

/*
* Class: Information_of_a_Table
* Function: getListDish
* Description: This function use for get list dish of the dinner table
* Input:
*   None
* Output:
*   return: Status
*/
void Information_of_a_Table::getListDish(){
    cout << "LIST DISH" << endl;
    cout << "ID\t Name\t Price " << endl;
    for(auto item : dish_Information_of_a_Table){
        cout << " " << item.dish_in_Table.getName() << "\t";
        cout << " " << item.number_of_Dish << endl;
    }
}

/*
* Class: Information_of_a_Table
* Function: FixDishInTheTable
* Description: This function use for fix dish in the dinner table 
* Input:
*   None
* Output:
*   return: Status
*/
void Information_of_a_Table::fixDishInTheTable(){
    int id;
    int Quantity_new;
    cout << "Chose ID" << endl;
    cin >> id;

    for(auto item : dish_Information_of_a_Table){
        if(item.dish_in_Table.getID() ==  id){
            cout << "Chose Quantity " << endl;
            cin >> Quantity_new;
            item.number_of_Dish = Quantity_new;
            break;
        }
        else{
            cout << "is not any dish have id " << id << endl;
        }
        
    }
}

/*
* Class: Information_of_a_Table
* Function: DeleteDish
* Description: This function use for delete dish in the dinner table 
* Input:
*   None
* Output:
*   return: Status
*/
void Information_of_a_Table::deleteDish(uint8_t id)
{

    auto position = dish_Information_of_a_Table.begin();

    for(auto item : dish_Information_of_a_Table){
        if(item.dish_in_Table.getID() ==  id){
            dish_Information_of_a_Table.erase(position);
            break;
        }
        else{
            cout << "is not any dish have id " << id << endl;
            
        }
        position++;
    }
}
