#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <list>

using namespace std;

class  Dish
{
private:
    uint8_t ID;
    string Name;
    double Price;
public:
    Dish(string name, double price);
    uint8_t getID();
    string getName();
    double getPrice();

    uint8_t seID();
    string setName(string name);
    double setPrice(double price);
};

Dish::Dish(string name, double price){
    this->Name = name;
    this->Price = price
}

uint8_t Dish::setID(){
    static uint8_t id = 0;
    ID = id;
    id++;
    this->ID = id;
}

uint8_t Dish::getID(){
    return this->ID;
}

string Dish::setName(string name){
    this->Name = name;
}

string Dish::getName(){
    return this->Name;
}

double Dish::setPrice(double price){
    this->Price = price;
}

double Dish::getPrice(){
    return this->Price;
}



class Manager
{
    private:
        list<Dish> Data;
        uint8_t Table;

        void AddDish(){
            string nameDish;
            double priceDish;
            Dish dishTemple

            cout << "enter Name Dish " << endl;
            cin >> nameDish;
            cout << "enter Price Dish " << endl;
            cin >> priceDish;

            dishTemple.setID();
            dishTemple.setName(nameDish);
            dishTemple.setPrice(priceDish);
            Data.push_back(dishTemple);           
        };
        void FixTheDish(){
            string fixnameDish;
            double fixpriceDish;
            int temple;
            int idDish;

            if(sinhvien.empty()) cout << "is empty\n";

            cout << "Enter the ID of a dish you want change = "; 
            scanf("%d", &idDish);
        

            for(Dish item : Data )
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
                        item.setName(fixpriceDish);
                        break;
                    
                    default:
                        break;
                    }
                }
                   
            }
        };
    
        void AddTable(){
            cout << "Enter the Table";
            cin >> Table;
            
        };
        void DeleteDish(){
            uint8_t idDish;
            if(Data.empty()) cout << "is empty\n";

            cout << "Enter the ID of a dish you want delete = "; 
            scanf("%d", &idDish);

            for(Dish item : Data){
                if(item.getID == idDish){
                    Data.erase(Data.begin() + idDish);
                    break;
                }
                else{
                    cout << "Don't find ID = " << idDish << "of a dish you want delete" << endl;
                }
            }
        };
    public:
        Manager(); // nhap thong tin switch case
        list<Dish> getData();
        uint8_t getTable();
        void DisplayDish();

};

Manager::Manager(){
    uint8_t key;
    do
    {
        cout << "Chose one number" << endl;
        cout << "1. Add dish " << endl;
        cout << "2. Fix the dish " << endl;
        cout << "3. Delete dish " << endl;
        cout << "4. List dish " << endl;
        cout << "5. Add table " << endl;
        cout << "0. Return " << endl;
        
        scanf("%d", &key);
    } while ((key = 1) || (key = 2) || (key = 3) || (key = 4) || (key = 5) || (key = 0));
    
    switch (key)
    {
    case 1:
        Manager::AddDish();
        break;
    
    case 2:
        Manager::FixTheDish();
        break;
    
    case 3:
        Manager::DeleteDish();
        break;

    case 4:
        Manager::DisplayDish();
        break;
    
    case 5:
        Manager::AddTable();
        break;
    default:
        break;
    }
}

void Manager::AddTable(){

}

void Manager::FixTheDish(){
    
}

list<Dish> Manager::getData(){
    return this->Data;
}

uint8_t Manager::getTable(){
    return this->Table;
}

void Manager::DisplayDish(){
    cout << "LIST DISH" << endl;
    cout << "ID\t Name\t Price " << endl;
    for(Dish item : Data){

        printf("%d\t", item.getID());
        cout << " " << item.getName() << "\t";
        cout << " " << item.getPrice() << endl;
    }
}

class Information_of_a_Table
{
private:
    uint8_t Number_of_Table;
    bool Status;
    typedef struct{
        Dish dish_in_Table;
        uint8_t Number_of_Dish;
    }TypeDish;
    list<Dish> dataDish;
public:
    Information_of_a_Table(uint8_t NumberOfTable, bool Status);
    uint8_t getNumberOfTable();
    bool getStatus();
    void ListDish();
    void AddDishInTheTable(Dish dish, uint8_t Quantity);
    void FixDishInTheTable(uint8_t id, uint8_t Quantity);
    void DeleteDish(uint8_t id);
};

Information_of_a_Table::Information_of_a_Table(uint8_t NumberOfTable, bool Status)
{
    this->Number_of_Table = NumberOfTable;
    this->Status = Status;
}

uint8_t Information_of_a_Table::getNumberOfTable(){
    return this->Number_of_Table;
}

bool Information_of_a_Table::getStatus(){
    return this->Status;
}

void Information_of_a_Table::ListDish(){
    cout << "LIST DISH" << endl;
    cout << "ID\t Name\t Price " << endl;
    for(Dish item : Data){

        printf("%d\t", item.getID());
        cout << " " << item.getName() << "\t";
        cout << " " << item.getPrice() << endl;
    }
}

void Information_of_a_Table::DeleteDish(uint8_t id)
{
    uint8_t id;

    auto position = dataDish.begin();

    for(auto item : dataDish){
        if(item.getID() = id){
            dataDish.erase(position);
        }
        position++;
    }
}



class Staff
{
private:
    list<Dish> data_Dish;
    bool Status;
    typedef struct{
        Dish dish;
        uint8_t NumberOfTable;
    }
public:
    Staff (list<Dish> dish);
};




