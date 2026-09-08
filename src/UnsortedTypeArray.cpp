#include "UnsortedTypeArray.h"
#include "ItemType.h"
#include <iostream>
#include <cassert>

UnsortedTypeArray::UnsortedTypeArray()
{
    length = 0;
    currentPos = 0;
}
// UnsortedTypeArray::~UnsortedTypeArray(); // Apparently don't need this guy

void UnsortedTypeArray::MakeEmpty() // sets all values to 0
{
    for (int k = 0; k < length; k++)
    {
        info[k].SetValue(0);
    }
    length = 0;
    currentPos = 0;
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

    while (currentPos < length - 1)
    {

        switch (item.ComparedTo(info[k]))
        {
        case LESS:
        case GREATER:
            break;
        case EQUAL:
            Match = info[k];
            found = true;
            break;
        }
        k++;
    }

    if (found)
    {
        return Match;
    }
    else
    {
        return NULL;
    }
}
void UnsortedTypeArray::PutItem(ItemType item) //
{
    if (length + 1 == 50)
    {
        std::cout << "List is Full";
        return;
    }
    else if (length > 0)
    {
        for (int k = length - 1; k >= 0; k--)
        {
            info[k + 1] = info[k];
        }
        info[0] = item;
    }
    else if (length == 0)
    {
        info[0] = item;
    }
    length++;
};

void UnsortedTypeArray::DeleteItem(ItemType item) // would be nice if this returned the Data/NULL or T/F but that doesn't follow the UnsortedLinked ADT
{
    currentPos = 0;
    ItemType MatchItemType;

    bool found = false;

    // int k = 0;
    while (currentPos < length - 1)
    {
        switch (item.ComparedTo(info[currentPos]))
        {
        case LESS:
        case GREATER:
            break;
        case EQUAL:
            MatchItemType = info[currentPos];
            found = true;
            break;
        }
        currentPos++;
    }
    if (found)
    {
        for (int k = currentPos; k < length - 1; k++) // shift elements left
        {
            info[k] = info[k + 1];
        }
    }
    return;
}

void UnsortedTypeArray::ResetList() { currentPos = 0; }

ItemType UnsortedTypeArray::GetNextItem()
{
    // Function: Gets the next element in list.
    // Pre:  List has been initialized and has not been changed since last call.
    //       Current position is defined.
    //       Element at current position is not last in list.
    //
    // Post: Current position is updated to next position.
    //       item is a copy of element at current position.

    currentPos++;
    return info[currentPos++];
};

void UnsortedTypeArray::Print() // Prints horiziontally with commas and braces
{
    currentPos = 0;
    std::cout << "{";
    while (currentPos < length)
    {

        int printValue = info[currentPos].GetValue();
        std::cout << printValue;
        if (currentPos < length - 1)
        {
            std::cout << ", ";
        }
        currentPos++;
    }
    std::cout << "}" << std::endl;
}

void UnsortedTypeArray::SplitLists(UnsortedTypeArray list, ItemType item, UnsortedTypeArray &list1, UnsortedTypeArray &list2)
{
    currentPos = 0;
    while (currentPos < length) // n
    {
        switch (item.ComparedTo(list.info[currentPos])) // n == n^2
        {
        case LESS:
        case EQUAL:
            list2.PutItem(info[currentPos]);
            break;
        case GREATER:
            list1.PutItem(info[currentPos]);
            break;
        }
        currentPos++;
    }
}

ItemType UnsortedTypeArray::GetCurrentItem()
{
    return info[currentPos];
}
