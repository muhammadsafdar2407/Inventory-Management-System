#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <list>
#include "Inventory.h"
#include "AVL_Inventory.h"
#include "List.h"
#include "Hashing.h"

using namespace std;

class Manager
{
public:
    void AddToInventoryManager()
    {
        Product prod;
        cout << "Enter Product Name: ";
        cin.ignore();
        cin >> prod.name;
        cout << "Enter Product Quantity: ";
        cin.ignore();
        cin >> prod.stock;
        cout << "Enter Product price: ";
        cin.ignore();
        cin >> prod.price;
        AddToInventory(prod);
    }

    void SearchManager()
    {
        string pName;
        cout << "Enter Name of Product: ";
        cin.ignore();
        cin >> pName;

        Product Prod = Search(pName);

        cout << "Name: " << Prod.name;
        cout << "  Price: $" << Prod.price;
        cout << "  Stock: " << Prod.stock << endl;
    }

    void UpdateManager()
    {
        Product prod;
        cout << "Enter Product Name: ";
        cin.ignore();
        cin >> prod.name;
        cout << "Enter Product Quantity: ";
        cin.ignore();
        cin >> prod.stock;
        cout << "Enter Product price: $";
        cin.ignore();
        cin >> prod.price;
        Update(prod.name, prod.stock, prod.price);
    }
};

#endif