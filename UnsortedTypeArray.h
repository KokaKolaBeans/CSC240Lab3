#ifndef UNSORTEDTYPEARRAY_H
#define UNSORTEDTYPEARRAY_H
#include "ItemType.h"

const int MAX_ITEMS = 50;

class UnsortedTypeArray
{

public:
    UnsortedTypeArray();
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType &item, bool &found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();

    void SplitLists(UnsortedTypeArray list, ItemType item, UnsortedTypeArray &list1, UnsortedTypeArray &list2);

private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};
#endif