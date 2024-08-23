## Hard Disk Defragmentation
This project is a C program that simulates the management of multiple dynamic sets using doubly linked lists stored in a contiguous memory array, mimicking how objects and pointers are managed in RAM. The program provides a menu-driven interface to perform various operations on the lists, including defragmentation to maintain contiguous data.

### Learning Outcomes
* **Understanding Memory Management**: Learn how objects and pointers are implemented and managed in RAM.
* **Defragmentation**: Explore how defragmentation works to maintain data contiguity in memory.

### Project Overview
A linked list is an Abstract Data Type (ADT) in which objects are arranged linearly using pointers rather than indices. In this assignment, we:
* Implement doubly linked lists using a single array to simulate RAM memory.
* Manage multiple dynamic sets in the form of doubly linked lists.
* Perform defragmentation to maintain data contiguity in memory.

### Program Features
The program offers the following menu-driven operations:
1. **Create a New List**: Initialize a new doubly linked list.
2. **Insert a Node**: Insert a new node in a given list in sorted order.
3. **Delete a Node**: Remove an element from a given list.
4. **Count Total Elements (Excluding Free List)**: Display the total number of elements across all lists.
5. **Count Elements of a List**: Show the number of elements in a specified list.
6. **Display All Lists**: Print all existing lists.
7. **Display Free List**: Show the free list with unallocated nodes.
8. **Perform Defragmentation**: Rearrange nodes to ensure data contiguity.
9. **Exit**: Terminate the program.

### Defragmentation
Over time, insertions and deletions may cause nodes in the free list to become scattered. Defragmentation (or compaction) rearranges these non-contiguous nodes to restore them to a contiguous order, ensuring efficient memory usage.

### How to Run
1. Clone the Repository:
2. Compile the Program: `$ make`
3. Run the executable