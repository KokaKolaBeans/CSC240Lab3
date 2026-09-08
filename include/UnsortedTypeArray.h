#ifndef UNSORTEDTYPEARRAY_H
#define UNSORTEDTYPEARRAY_H
#include "ItemType.h"

const int MAX_ITEMS = 50;

class UnsortedTypeArray
{

public:
    UnsortedTypeArray();
    // Pre: Default constructor – object doesn't exist
    // Post: object is initialized with no elements; associated private data members are also initialized
    // ~UnsortedTypeArray(); // Need to Make
    void MakeEmpty();
    // Pre: object exists
    // Post: the backing array info is zero'd out; currentPos  and length = 0
    bool IsFull() const;
    // Pre: Object has been initialized
    // Post: If list is full (50 items), returns true; if 0 < n < 50, returns false
    int GetLength() const;
    // Pre: Object and associated private data members are initailized
    // Post: int length is returned
    ItemType GetItem(ItemType &item, bool &found);
    // Pre: Object and members are initialized
    // Post: Found item is returned if it exists; bool argument tells us if item was or wasn't found
    ItemType GetCurrentItem();
    // Pre: Object and members are initialized
    // Post: Item at index currentPos is returned
    void PutItem(ItemType item);
    // Pre: Object and members are initialized; object exists in list
    // Post: Item passed into the function is added to the front; other all other n's moved to the right by one space
    void DeleteItem(ItemType item);
    // Pre: Object and members are initialized; object exists in list
    // Post: Item is removed; items at indices greater than the removed item are shifted left
    void ResetList();
    // Function: Gets the next element in list.
    // Pre:  List has been initialized and has not been changed since last call.
    //       Current position is defined.
    //       Element at current position is not last in list.
    //
    // Post: Current position is updated to next position.
    //       item is a copy of element at current position.
    ItemType GetNextItem();
    // Pre: currentPos points to an item
    // Post: currentPos points to the next item; that item is returned
    void Print();
    // Pre: Object and members exist
    // Post: Items at indices up to length are printed
    void SplitLists(UnsortedTypeArray list, ItemType item, UnsortedTypeArray &list1, UnsortedTypeArray &list2);
    // Pre: list, item, list1, list2 have been initialized
    // Post: list 1 and list 2 are filled with the appropriate values.

private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};

// typedef int ItemType;

#endif