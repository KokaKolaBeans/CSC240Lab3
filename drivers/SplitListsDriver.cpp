#include "UnsortedTypeArray.h"

void SplitLists(UnsortedTypeArray list, ItemType item, UnsortedTypeArray &list1, UnsortedTypeArray &list2)
{

     list.ResetList();
     int length = list.GetLength();
     ItemType data = list.GetCurrentItem();
     int counter = 0;

     while (counter <= length)
     {
          switch (item <)
          {
          case LESS:
          case EQUAL:
               list1.PutItem(info[currentPos]);
               break;
          case GREATER:
               list2.PutItem(info[currentPos]);
               break;
          }
          currentPos++;
     }

     return 0;
}

int main()
{
}

typedef int ItemType;
// g++ drivers/SplitListsDriver.cpp src/UnsortedTypeLinkedInt.cpp -Iinclude -o splitTest && ./splitTest