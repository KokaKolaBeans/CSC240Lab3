UnsortedTypeArrayDriver (ArrayList/Integers/Part B/UnsortedTypeArray)

g++ UnsortedTypeArrayDriver.cpp UnsortedTypeArray.cpp ItemType.cpp -o array_lab && ./array_lab

StudentTypeDriver (Linked List/Student/Part A/Unsorted)

??

NOTES - ArrayList SplitLists Implementation:

I think the linked implementation in the lab uses a freelist, but i'm not sure that's going to play any role because we aren't deleting items. Check list node 0. If it is GREATER, PutItem in listHigh. Advance to node one. If it is LESS, Putitem in listLow... wait this won't work because this would involve a bunch of copying. We have to move nodes from list to list1 and list2

So we should pass the master list in by value so we can rip apart the two linked lists and splice them into separate output lists. So...

Check list(0). list(0) > item.value? YES

listData(High) (currently empty list) will now point to this node. currentPosHigh will also point to this node

list(1) > item.value? YES

listDataHigh AND list(1) now point to listHigh(0)
currentPos points to list(1)

start at the first node and compare. if it's greater, add it tot \*/

Change RelationType Return to StudentStatus Return in Student Type?? Will this break my code? This is technically what the professor suggests, however.

don't need to make this change

Can replace all NULL with nullptr (for pointers)
