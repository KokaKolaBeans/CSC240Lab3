#include "UnsortedTypeArray.h"
#include "ItemType.h"
#include <iostream>
#include <cassert>
using namespace std;

UnsortedTypeArray::UnsortedTypeArray() { length = 0; }

void UnsortedTypeArray::MakeEmpty() // sets all values to 0
{
    for (int k = 0; k < length; k++)
    {
        info[k].SetValue(0);
    }
    length = 0;
}

bool UnsortedTypeArray::IsFull() const // he might want this the other way around–check StudentType
{
    if (length == 50)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int UnsortedTypeArray::GetLength() const { return length; }

ItemType UnsortedTypeArray::GetItem(ItemType &item, bool &found)

{
    currentPos = 0;
    ItemType Match;

    found = false;

    int k = 0;

    switch (item.ComparedTo(info[k]))
    {
        if (k = length + 1)
        {
            break;
        }
    case LESS:
    case GREATER:
        break;
    case EQUAL:
        Match = info[k];
        found = true;
        break;
        k++;
    }
    if (found)
    {
        return Match;
    }
    else
    {
        return;
    }
}

void UnsortedTypeArray::DeleteItem(ItemType item)
{
    currentPos = 0;
    ItemType Match;

    bool found = false;

    int k = 0;

    switch (item.ComparedTo(info[k]))
    {
        if (k = length + 1)
        {
            break;
        }
    case LESS:
    case GREATER:
        break;
    case EQUAL:
        Match = info[k];
        found = true;
        break;
        k++;
    }
    if (found)
    {
        return info;
    }
    else
    {
        return;
    }
}

void UnsortedTypeArray::SplitLists(UnsortedTypeArray list, ItemType item, UnsortedTypeArray &list1, UnsortedTypeArray &list2)
{
    currentPos = 0;
}
