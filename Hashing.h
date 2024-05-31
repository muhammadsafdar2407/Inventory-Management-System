#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <list>
#include "Inventory.h"
#include "AVL_Inventory.h"
#include "List.h"

// hash Table
static const int ARR_SIZE = 100;

SinglyLinkedList Inventory[ARR_SIZE];

static int hashFunc(string key)
{
    int sum=0;
    for (int i = 0; i < key.length(); i++)
    {
        sum += key[i];
    }
    return sum % ARR_SIZE;
}

void AddToInventory(Product obj) {
    int index = hashFunc(obj.name);
    //cout<<"Insert Index: "<<index<<endl;
    // getch();
    Product *newProduct = new Product(obj.name);
    newProduct->stock = obj.stock;
    newProduct->price = obj.price;

    Inventory[index].insertAtTail(newProduct);
}


void DeleteFromInventory()
{
    string prod_name;
    cout << "Enter Product Name to Delete: ";
    cin.ignore();
    cin >> prod_name;
    int index = hashFunc(prod_name);

   Inventory[index].deleteproduct(prod_name);
    
}

Product Search(string name)
{
    int index = hashFunc(name);
    // cout<<"Search Index: "<<index<<endl;
    Product P=Inventory[index].search(name);
    return P;
}

void Update(string name, int quantity, double price)
{
    int index = hashFunc(name);
    Inventory[index].update(name,quantity,price);
}

void printAll()
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if(Inventory[i].head!=NULL)
        Inventory[i].printList();
    }
    cout << endl;
}
// Hash Table End


#endif