#ifndef SORTING_H
#define SORTINH_H

#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <list>
#include "Inventory.h"
#include "Hashing.h"



int partition(vector<Product> &arr, int start, int end)
{
    int pivot = arr[start].stock;

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i].stock <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i].stock <= pivot)
        {
            i++;
        }

        while (arr[j].stock > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<Product> &arr, int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}

void InventorySort()
{
    vector<Product> arr;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        Product *temp = Inventory[i].head;
        while (temp !=NULL)
        {
            if (temp->name != " ")
                arr.push_back(*temp);
            temp=temp->next;
        }
    }
    quickSort(arr, 0, (arr.size() - 1));
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Name: " << arr[i].name;
        cout << "  Price: $" << arr[i].price;
        cout << "  Stock: " << arr[i].stock << endl;
    }
}

#endif