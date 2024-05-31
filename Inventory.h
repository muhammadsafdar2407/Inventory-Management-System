#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Product
{
public:
    string name;
    int stock;
    double price;
    Product *next;

    Product()
    {
        name = " ";
        next=NULL;
    }

    Product(string n)
    {
        name = n;
        next=NULL;
    }
};

class Order
{
public:
    Product product;
    int quantity;
    Order *left, *right;

    Order()
    {
        left = right = NULL;
        quantity = 0;
    }

    Order(Product obj, int q)
    {
        left = right = NULL;
        product = obj;
        quantity = q;
    }
};

#endif // INVENTORY_H