/*
* File: Dish.cpp
* Author: MA THANH VAN
* Date: 07/08/2023
* Description: This is file have function for management person
*/

#include "Restaurant_Manager/Header/Manager.hpp"

/*
* Class: Manager
* Function: Mananger
* Description: This function use for choose function manager
* Input:
*   None
* Output:
*   return: None
*/
Manager::Manager(){
//     uint8_t key;
//     do
//     {
//         cout << "Chose one number" << endl;
//         cout << "1. Add dish " << endl;
//         cout << "2. Fix the dish " << endl;
//         cout << "3. Delete dish " << endl;
//         cout << "4. List dish " << endl;
//         cout << "5. Add table " << endl;
//         cout << "0. Return " << endl;
        
//         scanf("%d", &key);
//     } while ((key = 1) || (key = 2) || (key = 3) || (key = 4) || (key = 5) || (key = 0));
    
//     switch (key)
//     {
//     case 1:
//         Manager::addDish();
//         break;
    
//     case 2:
//         Manager::fixTheDish();
//         break;
    
//     case 3:
//         Manager::deleteDish();
//         break;

//     case 4:
//         Manager::displayDish();
//         break;
    
//     case 5:
//         Manager::addTable();
//         break;
//     default:
//         break;
//     }

KEY_INPUT(Manager,
            KEY_VALUE(
                KEY(1),
                NAME("Add dish")
            )
            KEY_VALUE(
                KEY(2),
                NAME("Fix the dish")
            )
            KEY_VALUE(
                KEY(3),
                NAME("Delete dish")
            )
            KEY_VALUE(
                KEY(4),
                NAME("List dish")
            )
            KEY_VALUE(
                KEY(5),
                NAME("Add table")
            )
        )
}
/*
* Class: Manager
* Function: AddDish
* Description: This function use for add dish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::addDish(){
    string nameDish;
    double priceDish;
    Dish dishTemple;

    cout << "enter Name Dish " << endl;
    cin >> nameDish;
    cout << "enter Price Dish " << endl;
    cin >> priceDish;

    dishTemple.setID();
    dishTemple.setName(nameDish);
    dishTemple.setPrice(priceDish);
    dataDish.push_back(dishTemple);
}

/*
* Class: Manager
* Function: FixTheDish
* Description: This function use for fix the dish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::fixTheDish(){
    string fixnameDish;
    double fixpriceDish;
    int temple;
    int idDish;

    if(dataDish.empty()) cout << "is empty\n";

    cout << "Enter the ID of a dish you want change = "; 
   // scanf("%d", &idDish);
    cin >> idDish;


    for(Dish item : dataDish )
    {
        if(item.getID() == idDish)
        {
            cout << "Chose one number" << endl;
            cout << "1. Fix the name dish " << endl;
            cout << "2. Fix the price dish " << endl;
            cout << "0. Return " << endl;
            cin >> temple;

            switch (temple)
            {
                exit(0);
            case 1:
                cout << " New name Dish" << endl;
                cin >> fixnameDish;
                item.setName(fixnameDish);
                break;

            case 2:
                cout << " New price Dish" << endl;
                cin >> fixpriceDish;
                item.setPrice(fixpriceDish);
                break;
            
            default:
                break;
            }
        }
            
    }
}

/*
* Class: Manager
* Function: AddTable
* Description: This function use for add table
* Input:
*   None
* Output:
*   return: None
*/
void Manager::addTable(){
    cout << "Enter the Table";
    cin >> table;
}

/*
* Class: Manager
* Function: AddDish
* Description: This function use for delete dish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::deleteDish(){
    uint8_t idDish;
            if(dataDish.empty()) cout << "is empty\n";

            cout << "Enter the ID of a dish you want delete = "; 
            scanf("%d", &idDish);

            auto position = dataDish.begin();

            for(auto item : dataDish){
                if(item.getID() ==  idDish){
                    dataDish.erase(position);
                    break;
                }
                position++;
                
            }
           
            cout << "Don't find ID = " << idDish << "of a dish you want delete" << endl;
            
}

/*
* Class: Manager
* Function: getDataDish
* Description: This function use for get data dish
* Input:
*   None
* Output:
*   return: DataDish
*/
list<Dish> Manager::getDataDish(){
    return this->dataDish;
}

/*
* Class: Manager
* Function: getTable
* Description: This function use for get table
* Input:
*   None
* Output:
*   return: Table
*/
uint8_t Manager::getTable(){
    return this->table;
}

/*
* Class: Manager
* Function: DisplayDish
* Description: This function use for DisplayDish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::displayDish(){
    cout << "LIST DISH" << endl;
    cout << "ID\t Name\t Price " << endl;
    for(Dish item : dataDish){

        printf("%d\t", item.getID());
        cout << " " << item.getName() << "\t";
        cout << " " << item.getPrice() << endl;
        
    }
}