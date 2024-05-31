#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <list>
#include "Inventory.h"
#include "AVL_Inventory.h"

class SinglyLinkedList{
    public:
    Product *head;

	SinglyLinkedList(){
		head=NULL;
	}

    void insertAtHead(Product *n){
        n->next=n;
        head=n;
    }

    void insertAtTail(Product *n){
        if(head==NULL){
            head=n;
        }
        else{
        Product *temp = head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        }
    }

    Product search(string n){
        Product *temp=head;
        // cout<<2000;
        while (temp!=NULL)
        {
            // cout<<3000;
            if(temp->name==n){
                // cout<<"Product Found"<<endl;
                return *temp;
            }
            temp=temp->next;
        }
        Product *P= new Product();
        return *P;
    }

    void deleteproduct(string name){
        if(head==NULL){
            return;
        }

        if(head->name==name){
            Product *temp=head;
            head=head->next;
            delete temp;
            return;
        }
        Product *prev,*curr=head;
        while (curr->name!=name&&curr!=NULL)
        {   
            prev=curr;
            curr=curr->next;
        }

        if(curr!=NULL){
        prev->next=curr->next;
        delete curr;}
    }

    void update(string prod_name,int q,double p){
        if(head==NULL){
            return;
        }
        Product *temp=head;

        while (temp!=NULL)
        {
            if (temp->name==prod_name)
            {
                temp->stock=q;
                temp->price=p;
                // cout<<"Product Updated: "<<endl;
            }
            temp=temp->next;
        }
        
    }

    void printList(){
        Product *temp=head;

        while (temp!=NULL)
        {
            cout<<"Product Name: "<<temp->name<<" "
                <<"Product Price: "<<temp->price<<" "
                <<"Product Stock: "<<temp->stock<<endl;
            temp=temp->next;
        }
        
    }
};

#endif