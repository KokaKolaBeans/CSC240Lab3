
    **1. State the invariant your Print function relies on as it walks the list. Write it as a comment above the function. (Graded under Design and Documentation.)**

    - List is null terminated – location only points to valid node or nullptr – never dereferences a nullptr – empty list: listData == nullptr
    - Unsorted LINE 169

    2. What is the running time of your Print, and what specifically in your loop determines it? Answer by pointing at your code, not at the general case.
    
    The running time is O(n), but more specifically, it's big-Theta(n) -->  unsorted LINE 182 --> while (location != nullptr)

    3. Run the driver and confirm Print list 3: outputs Empty. Show the line in your function that produces it. What would the output have been if you had omitted that check?

    g++ drivers/StudentTypeDriver.cpp src/unsorted.cpp src/StudentType.cpp src/PersonType.cpp src/DateType.cpp src/ItemType.cpp -Iinclude -o student_lab && ./student_lab
  
    Unsorted LINE 176: if (listData == nullptr)

    Dereferencing a nullptr typically causes a segmentation fault.

    4. Your ComparedTo returns EQUAL for two students in some circumstance. Describe exactly when, and say whether that is what you intended.

    g++ drivers/StudentTypeDriver.cpp src/unsorted.cpp src/StudentType.cpp src/PersonType.cpp src/DateType.cpp src/ItemType.cpp -Iinclude -o student_lab && ./student_lab

    It returns EQUAL when enrollment statuses are the same. I DID intend this to ahppen

    5. Give the running time of your array SplitLists and your linked version. If they are the same order, say what is different about the constant factor and why.

    SplitList Array is O(n^2). It is an expensive impelmentation because it places elements at the front using PutItem--> reshuffling required
    --> UnsortedTypeArray LINES 160 and 72 (this is the alternative implementation–I made two!)

    SplitList Linked is O(n); but each operation is much cheaper – rewire some nodes, no copying required (except for the pass by value), no reshuffling
    --> unsorted 193

    6. Did your linked version copy items into the new lists or relink existing nodes? Point to the code. If you copied, describe what relinking would have changed.

    --> unsorted 193 

    It relinks the nodes

    7. Run Part B on the test data and confirm both 34s and both 5s land correctly. Show the output.

    Yep
