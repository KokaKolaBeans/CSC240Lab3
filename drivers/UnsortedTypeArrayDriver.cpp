#include "ItemType.h"
#include "UnsortedTypeArray.h"
#include <iostream>
using namespace std;

// overload the << for a CFF??

int main()
{

     UnsortedTypeArray list;
     UnsortedTypeArray listLow;
     UnsortedTypeArray listHigh;

     int numbers[] = {5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12};

     //    int numLength = sizeof(numbers) / sizeof(numbers[0]);

     for (int k = 0; k < 14; k++) // wraps ints in ItemType wrapper; places them in list
     {

          list.PutItem(ItemType(numbers[k]));
     }

     // ==========================================
     //              Print ArrayList
     // ==========================================
     cout << "List: ";

     list.Print();
     cout << endl
          << endl;

     // ==========================================
     //              Run .SplitLists
     // ==========================================

     ItemType splitPoint(15); // SplitLists arg 2 is an ItemType, not an int!
     list.SplitLists(list, splitPoint, listLow, listHigh);

     // ==========================================
     //       Print Resulting Split Lists
     // ==========================================

     cout << "List Less than or Equal to: ";

     listLow.Print();
     cout << endl
          << endl;

     cout << "List Greater than: ";

     listHigh.Print();
     cout << endl
          << endl;

     return 0;
}

// g++ UnsortedTypeArrayDriver.cpp UnsortedTypeArray.cpp ItemType.cpp -o array_lab && ./array_lab

// g++ drivers/UnsortedTypeArrayDriver.cpp src/UnsortedTypeArray.cpp src/ItemType.cpp -Iinclude -o array_lab && ./array_lab