// #include "UnsortedTypeArray.h"
#include <iostream>
#include <array>
#include <iterator>
using namespace std;

enum RelationType
{
     LESS,
     EQUAL,
     GREATER
};

void printArray(int list[], int len)
{

     // Pre: List array has been initialized; appropriate length has been input (segmentation fault can occur otherwise)
     // Post: List elements are printed in terminal

     std::cout << "{";
     for (int k = 0; k < len; k++)
     {
          cout << list[k];

          if (k < len - 1)
          {
               std::cout << ", ";
          }
     }
     cout << "}" << endl;
}

RelationType ComparedTo(int a, int measure)
{
     // Pre: Enums have been defined; a and measure are valid integers
     // Post: An Enum is provided as output
     if (a < measure)
     {
          return LESS;
     }
     else if (a == measure)
     {
          return EQUAL;
     }
     else
     {
          return GREATER;
     }
};

void SplitLists(int list[14], int item, int list1[14], int list2[14], int &len1, int &len2)
{
     // Pre: all relevant lists and pass-by-reference arguments have been initialized; item is a valid integer
     // Post: list is unmofodified; list 1 has all values less than or equal to and list 2 has all values greater than item

     int counter = 0;

     for (int k = 0; k < 14; k++)
     {
          switch (ComparedTo(list[k], item))
          {
          case LESS:
          case EQUAL:
               list1[len1] = list[k];
               len1++;
               break;

          case GREATER:
               list2[len2] = list[k];
               len2++;
               break;
          }
     }

     return;
}

int main()
{
     int numbers[14] = {5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12};
     int listLow[14];
     int listHigh[14];
     int lengthList1 = 0;
     int lengthList2 = 0;
     SplitLists(numbers, 8, listLow, listHigh, lengthList1, lengthList2);
     printArray(listLow, lengthList1);
     printArray(listHigh, lengthList2);
     return 0;
}

// typedef int ItemType;

// g++ drivers/SplitListsArrayDriver.cpp -o splitArrayTest && ./splitArrayTest