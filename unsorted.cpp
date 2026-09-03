// This file contains the linked implementation of class
// UnsortedType.

#include "unsorted.h"
#include <iostream>
using namespace std;
struct NodeType // Node struct contains data and pointer to NEXT
{
  ItemType info;
  NodeType *next;
};

UnsortedType::UnsortedType() // Class constructor
{
  // Constructs an unsorted list with length 0

  length = 0;
  listData = NULL;
  head = new NodeType;
  head->next = NULL;
  tail = new NodeType;
  head->next = tail; // connects head and tail–all other elements will be placed between in between
  currentPos = cursor = head;
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
void UnsortedType::PutItem(ItemType item) // Rewrote this from scratch
// item is in the list; length has been incremented.
{

  NodeType *newNode = new NodeType;
  newNode->info = item;
  NodeType *temp = head->next;
  head->next = newNode;
  newNode->next = temp;

  length++;
}

// Came with Driver:

// ItemType UnsortedType::GetItem(ItemType &item, bool &found) // ItemType is a StudenType that inherets from PersonType
// // Pre:  Key member(s) of item is initialized.
// // Post: If found, item's key matches an element's key in the
// //       list and a copy of that element has been stored in item;
// //       otherwise, item is unchanged.
// {
//   bool moreToSearch;
//   NodeType *location;

//   location = listData;
//   found = false;
//   moreToSearch = (location != NULL);

//   while (moreToSearch && !found)
//   {
//     switch (item.ComparedTo(location->info))
//     {
//     case LESS:
//     case GREATER:
//       location = location->next;
//       moreToSearch = (location != NULL);
//       break;
//     case EQUAL:
//       found = true;
//       item = location->info;
//       break;
//     }
//   }
//   return item;
// }

// Kazim's Version:

ItemType UnsortedType::GetItem(ItemType &item, bool &found) // ItemType is a StudenType that inherets from PersonType
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged.
{

  ResetList(); // currentPos and cursor are at head

  found = true;

  for (int k = 0; k < length; k++)
  {
    currentPos = currentPos->next;
    while (!found)
    {
      switch (item.ComparedTo(currentPos->info))
      {
      case LESS:
        break;
      case GREATER:
        break;
      case EQUAL:
        found = true;
        break;
      }
    }
  }

  // bool moreToSearch;
  // NodeType *location;

  // location = listData;
  // found = false;
  // moreToSearch = (location != NULL);

  // while (moreToSearch && !found)
  // {
  //   switch (item.ComparedTo(location->info))
  //   {
  //   case LESS:
  //   case GREATER:
  //     location = location->next;
  //     moreToSearch = (location != NULL);
  //     break;
  //   case EQUAL:
  //     found = true;
  //     item = location->info;
  //     break;
  //   }
  // }
  // return item;
}

// void UnsortedType::DeleteItem(ItemType item)
// // Pre:  item's key has been initialized.
// //       An element in the list has a key that matches item's.
// // Post: No element in the list has a key that matches item's.
// {
//   NodeType *location = listData;
//   NodeType *tempLocation;

//   // Locate node to be deleted.
//   if (item.ComparedTo(listData->info) == EQUAL)
//   {
//     tempLocation = location;
//     listData = listData->next; // Delete first node.
//   }
//   else
//   {
//     while (item.ComparedTo((location->next)->info) != EQUAL)
//       location = location->next;

//     // Delete node at location->next
//     tempLocation = location->next;
//     location->next = (location->next)->next;
//   }
//   delete tempLocation;
//   length--;
// }

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
  // currentPos = NULL;
  currentPos = cursor = head;
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

void UnsortedType::Print()
{
  // ItemType item is a StudentType. listData points to the first node after each reset.
  // -> dereferences the listData pointer so that we can access the data sitting inside this node

  if (length == 0)
  {
    std::cout << "Empty" << std::endl;
    return;
  }
  else
  {
    for (int k = 0; k < length; k++)
    {
      ItemType item = listData->info;
      std::cout << "Name: " << item.NameIs() << std::endl;
      std::cout << "Status: " << item.GetStatus() << std::endl;
      listData = listData->next;
      // Complete this.;
    }
  }
  return;
}

/*
void UnsortedType::Print()
{
  // ItemType item is a StudentType. listData points to the first node after each reset.
  // -> dereferences the listData pointer so that we can access the data sitting inside this node
  if (listData->next == NULL)
  {
    std::cout << "Empty" << std::endl;
  }
  else
  {
    while (listData != NULL)
    {
      ItemType item = listData->info;
      std::cout << "Name: " << item.NameIs() << std::endl;
      std::cout << "Status: " << item.GetStatus() << std::endl;
      listData = listData->next;
      // Complete this.;
    }
  }
}
*/
// g++ *.cpp -o main && ./main