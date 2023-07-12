#include "Dish.hpp"
#include "Manager.hpp"
#include "Table.hpp"
#include "Staff.hpp"

int main(int argc, char const *argv[])
{
    
    int i = 1;
    while (i = 1){
        int choose;
        cout << "-------------Choose a Function ------------" << endl;
        cout << "1. Function Manager" << endl;
        cout << "2. Function Staff" << endl;
        cout << "0. Exit" << endl;
        cin >> choose;
        switch (choose)
        {
            exit(0);
        case 1:
           Manager();
           cout << "manager" << endl;
            break;

        case 2:
            Staff_in_Restaurant();
            break;

        default:
            break;
        }
    }
   // return 0;
}