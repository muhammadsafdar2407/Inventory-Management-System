#ifndef AVL_INVENTORY_H
#define AVL_INVENTORY_H

#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <list>
#include "Inventory.h"

class AVL
{
public:
    Order *root;
    AVL()
    {
        root = NULL;
    }

    int height(Order *n)
    {
        if (n == NULL)
        {
            return -1;
        }

        else
        {
            int lheight = height(n->left);
            int rheight = height(n->right);

            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }
    int BalanceFactor(Order *n)
    {
        if (!n)
        {
            return -1;
        }

        return (height(n->left) - height(n->right));
    }

    Order *RotateRight(Order *n)
    {
        Order *temp1 = n->left;
        Order *temp2 = temp1->right;

        temp1->right = n;
        n->left = temp2;
        return temp1;
    }

    Order *RotateLeft(Order *n)
    {
        Order *temp1 = n->right;
        Order *temp2 = temp1->left;

        temp1->left = n;
        n->right = temp2;
        return temp1;
    }

    Order *Insert(Order *r, Order *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            return root;
        }

        if (r == NULL)
        {
            r = new_node;
            return r;
        }

        if (new_node->product.name < r->product.name)
        {
            r->left = Insert(r->left, new_node);
        }
        else if (new_node->product.name > r->product.name)
        {
            r->right = Insert(r->right, new_node);
        }
        else
        {
            cout << "Product's Quantity Updated..." << endl;
            r->quantity += new_node->quantity;
            return r;
        }

        int balancefactor = BalanceFactor(r);

        if (balancefactor > 1 && new_node->product.name < r->left->product.name)
        {
            return RotateRight(r);
        }
        if (balancefactor < -1 && new_node->product.name > r->right->product.name)
        {
            return RotateLeft(r);
        }
        if (balancefactor > 1 && new_node->product.name > r->left->product.name)
        {
            r->left = RotateLeft(r->left);
            return RotateRight(r);
        }
        if (balancefactor < -1 && new_node->product.name < r->right->product.name)
        {
            r->right = RotateRight(r->right);
            return RotateLeft(r);
        }
        return r;
    }

    bool Search(string name, Order *n)
    {
        if (n == NULL)
        {
            return false;
        }

        else if (name == n->product.name)
        {
            return true;
        }

        else if (name < n->product.name)
        {
            return Search(name, n->left);
        }

        else if (name > n->product.name)
        {
            return Search(name, n->right);
        }
    }

    bool Update(string i, int q, Order *n)
    {
        if (n == NULL)
        {
            return false;
        }

        else if (i == n->product.name)
        {
            n->quantity = q;
            return true;
        }

        else if (i < n->product.name)
        {
            return Update(i, q, n->left);
        }

        else if (i > n->product.name)
        {
            return Update(i, q, n->right);
        }
    }

    Order *minValueNode(Order *node)
    {
        Order *current = node;

        while (current->left != NULL)
            current = current->left;

        return current;
    }

    Order *deleteNode(Order *root, string prod_name)
    {

        if (root == NULL)
            return root;

        if (prod_name < root->product.name)
            root->left = deleteNode(root->left, prod_name);

        else if (prod_name > root->product.name)
            root->right = deleteNode(root->right, prod_name);

        else
        {
            if ((root->left == NULL) ||
                (root->right == NULL))
            {
                Order *temp = root->left ? root->left : root->right;

                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                    *root = *temp;
                free(temp);
            }
            else
            {
                Order *temp = minValueNode(root->right);
                root->product.name = temp->product.name;

                root->right = deleteNode(root->right,
                                        temp->product.name);
            }
        }
        if (root == NULL)
            return root;

        int balance = BalanceFactor(root);

        // Left Left Case
        if (balance > 1 &&
            BalanceFactor(root->left) >= 0)
            return RotateRight(root);

        // Left Right Case
        if (balance > 1 &&
            BalanceFactor(root->left) < 0)
        {
            root->left = RotateLeft(root->left);
            return RotateRight(root);
        }

        // Right Right Case
        if (balance < -1 &&
            BalanceFactor(root->right) <= 0)
            return RotateLeft(root);

        // Right Left Case
        if (balance < -1 &&
            BalanceFactor(root->right) > 0)
        {
            root->right = RotateRight(root->right);
            return RotateLeft(root);
        }

        return root;
    }

    double preorder(Order *root,double sum)
    {
        if (root != NULL)
        {
            cout << "Name: " << root->product.name << " "
                 << "  Price: $" << root->product.price << " "
                 << "  Quantity: " << root->quantity << endl;
                 sum+=(root->product.price*root->quantity);
            preorder(root->left,sum);
            preorder(root->right,sum);
            return sum;
        }
    }
};

#endif 