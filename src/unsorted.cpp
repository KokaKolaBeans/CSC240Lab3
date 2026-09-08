// This file contains the linked implementation of class
// UnsortedType.

#include "unsorted.h"
#include <iostream>
using namespace std;
struct NodeType
{
  ItemType info;
  NodeType *next;
};

UnsortedType::UnsortedType() // Class constructor
{
  length = 0;
  listData = NULL;
}
bool UnsortedType::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
  NodeType *location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch (std::bad_alloc exception)
  {
    return true;
  }
}

int UnsortedType::GetLength() const
// Post: Number of items in the list is returned.
{
  return length;
}

void UnsortedType::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
  NodeType *tempPtr;

  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
}
void UnsortedType::PutItem(ItemType item)
// item is in the list; length has been incremented.
{
  NodeType *location; // Declare a pointer to a node

  location = new NodeType;   // Get a new node
  location->info = item;     // Store the item in the node
  location->next = listData; // Store address of first node
                             //   in next field of new node
  listData = location;       // Store address of new node into
                             //   external pointer
  length++;                  // Increment length of the list
}

ItemType UnsortedType::GetItem(ItemType &item, bool &found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged.
{
  bool moreToSearch;
  NodeType *location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    switch (item.ComparedTo(location->info))
    {
    case LESS:
    case GREATER:
      location = location->next;
      moreToSearch = (location != NULL);
      break;
    case EQUAL:
      found = true;
      item = location->info;
      break;
    }
  }
  return item;
}

void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  NodeType *location = listData;
  NodeType *tempLocation;

  // Locate node to be deleted.
  if (item.ComparedTo(listData->info) == EQUAL)
  {
    tempLocation = location;
    listData = listData->next; // Delete first node.
  }
  else
  {
    while (item.ComparedTo((location->next)->info) != EQUAL)
      location = location->next;

    // Delete node at location->next
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}

void UnsortedType::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{
  ItemType item;
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
  return item;
}

UnsortedType::~UnsortedType()
// Post: List is empty; all items have been deallocated.
{
  NodeType *tempPtr;

  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}

/* Design and Documentation

State the invariant the Print function relies on as it walks the list.

Structurally, the linked list is always null-terminated. The loop invariant states that the scout node pointer 'location' will only ever point to a valid node or a nullptr,
the latter of which it refuses to dereference. When the length of the list is greater than zero, 'location' always safely starts at 'listData,' which points to the first element,
and safely traverses the list until the invariant is broken. If the list is empty, listData == nullptr, so Print() outputs empty.

*/

void UnsortedType::Print() // O(n)
{
  // ItemType item is a StudentType. listData points to the first node after each reset.
  // -> dereferences the listData pointer so that we can access the data sitting inside this node

  NodeType *location = listData; // scout node; starts at listData and iterates through the list

  if (listData == nullptr)
  {
    std::cout << "Empty" << std::endl;
    return;
  }
  else
  {
    while (location != nullptr)
    {
      ItemType item = location->info;
      std::cout << "Name: " << item.NameIs() << std::endl;
      std::cout << "Status: " << item.GetStatus() << std::endl;
      location = location->next;
      return;
      // Complete this.;
    }
  }
}

void UnsortedType::SplitLists(UnsortedType list, ItemType item, UnsortedType &list1, UnsortedType &list2)
{

  list.ResetList();
  list1.MakeEmpty();
  list2.MakeEmpty();
  list1.ResetList();
  list2.ResetList();

  NodeType *location = list.listData;

  if (list.listData == nullptr)
  {
    cout << "Input list is empty." << endl;
    return;
  }

  while (list.length > 0) // n
  {
    switch (location->info.ComparedTo(item)) // c
    {
    case LESS:
    case EQUAL:
      location->next = list1.listData; // selected Node's next pointer is assigned listData's address, which points to E1
      list1.listData = location;       // listData mvoes to the chain to point to the new first element (most recently added)
      break;
    case GREATER:
      location->next = list2.listData;
      list2.listData = location;
      break;
    }
    list.length--; // list is a copy; modify it if you'd like
  }
}
