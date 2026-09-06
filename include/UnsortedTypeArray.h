#ifndef UNSORTEDTYPEARRAY_H
#define UNSORTEDTYPEARRAY_H
#include "ItemType.h"

const int MAX_ITEMS = 50;

class UnsortedTypeArray
{

public:
    UnsortedTypeArray();
    // ~UnsortedTypeArray(); // Need to Make
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType &item, bool &found);
    ItemType GetCurrentItem();
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem(); // Need to Write
    void Print();           // Need to Write
    void SplitLists(UnsortedTypeArray list, ItemType item, UnsortedTypeArray &list1, UnsortedTypeArray &list2);

private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};

// typedef int ItemType;

#endif