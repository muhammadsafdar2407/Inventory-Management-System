#ifndef USER_H
#define USER_H

#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <list>
#include "Inventory.h"
#include "AVL_Inventory.h"
#include "List.h"
#include "Hashing.h"
#include "Manager.h"

using namespace std;

class user
{
public:
    AVL cart;

    void addtocart(string prod_name, int quant)
    {
        // cout<<"100000"<<endl;
        Product Prod = Search(prod_name);

        if (Prod.name==" "){
            cout<<"Product Not Found"<<endl;
            return;
        }
        // cout<<Prod.name<<endl;
        if (Prod.stock<quant){
            cout<<"Stock Not Available"<<endl;
            return;
        }

        Order *O = new Order(Prod, quant);
        // cout<<O->quantity<<endl;
        cart.root = cart.Insert(cart.root, O);
        // cout<<"Insert"<<endl;
        Update(Prod.name, Prod.stock - quant, Prod.price);
        // cout<<"Update"<<endl;
    }

    void removefromcart(string prod_name)
    {
        cart.root = cart.deleteNode(cart.root, prod_name);
    }

    int printCart()
    {
        if (cart.root==NULL){
            cout<<"Cart is Empty."<<endl;
            return -1;
        }
        double Bill=cart.preorder(cart.root,0);
        cout<<"Total Bill: "<<Bill<<endl<<"Thank You For Your Purchase"<<endl;
        return 0;
    }
};

#endif