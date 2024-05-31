#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <list>

//Our Defined Header Files
#include "Inventory.h"
#include "AVL_Inventory.h"
#include "List.h"
#include "Hashing.h"
#include "Manager.h"
#include "User.h"
#include "Sorting.h"

using namespace std;



void managerMenu()
{
    Manager m;

    string c = "";
    while (c != "6")
    {
        system("CLS");
        cout << "MANAGER SETTINGS" << endl
             << endl;
        cout << "1. Add To inventory" << endl
             << "2. Update Inventory" << endl
             << "3. View Inventory" << endl
             << "4. Print Sorted Inventory"<<endl
             << "5. Delete From Inventory" << endl
             << "6. Exit Manager Portal" << endl
             << "Enter Choice: ";
        cin >> c;
        if (c == "1")
        {
            m.AddToInventoryManager();
        }
        else if (c == "2")
        {
            m.UpdateManager();
        }
        else if (c == "3")
        {
            printAll();
            getch();
        }
        else if (c=="4"){
            InventorySort();
            getch();
        }
        else if (c == "5")
        {
            DeleteFromInventory();
            getch();
        }
        else if (c=="6")
        {
            return;
        }
        else{
            cout<<"invalid Input"<<endl;
        }
    }
}

void userMenu(){
    system("CLS");
    
    user u;
    int choice=0;
    while (choice != 4)
    {
        cout << "\t\t\t\t\t\tINVENTORY MANAGMENT SYSTEM\n\n"
         << endl;
    cout << "1. Add To Cart" << endl
         << "2. Remove From Cart"<<endl
         << "3. Checkout" << endl
         << "4. Exit" << endl
         << "Enter Choice: ";
    cin >> choice;

        if (choice == 1)
        {
            int q;
            string n;
            printAll();
            cout << endl;
            cout << "Enter Name:";
            cin >> n;
            cout << "Enter Quantity: ";
            cin >> q;
            u.addtocart(n, q);
        }

        else if(choice==2){
            string n;
            cout<<endl<<"Cart: "<<endl;
            if (u.printCart()==0){
                cout << "Enter Name of Product to be removed:";
                cin >> n;
                u.removefromcart(n);
            }
        }

        else if (choice == 3)
        {
            u.printCart();
            u.cart.root=NULL;
        }
        
        else if (choice == 4)
        {
            exit(0);
        }
        else if (choice == 1010)
        {
            managerMenu();
        }
        else
        {
            cout << "Invalid Input..." << endl;
        }
     
    }
}



int main(int argc, char const *argv[])
{
    int choice;
    managerMenu();
    userMenu();
    
    return 0;
}