# Introduction to Linked Lists

## Linked List as a Data Structure

A **linked list** is a linear data structure in which elements, called nodes, are connected using pointers. Unlike arrays, linked lists do not require a fixed amount of memory and can grow or shrink dynamically. Each node in a linked list consists of data and a reference (or pointer) to the next node in the sequence.

### Real-World Analogy

Think of a linked list as a chain of nodes, where each node holds a piece of data and points to the next node in the chain.

## Linked List Characteristics

In a linked list:
- Elements are not stored in contiguous memory locations.
- Insertions and deletions can be performed efficiently, even in the middle of the list.
- Linked lists come in various forms, such as singly linked lists, doubly linked lists, and circular linked lists.

## Operations

Common operations on linked lists include:

1. **Insertion at Front**: Adds a new node at the beginning of the list.
2. **Insertion at Specific Position**: Adds a new node at a given position in the list.
3. **Insertion at End**: Adds a new node at the end of the list.
4. **Deletion at Front**: Removes the first node from the list.
5. **Deletion at Specific Position**: Removes a node from a given position in the list.
6. **Deletion at End**: Removes the last node from the list.
7. **Display**: Prints the elements of the linked list.
8. **Freeing Memory**: Deallocates the memory used by the linked list.

## Applications

Linked lists find applications in various scenarios, including:

- **Dynamic Data Storage**: When the size of the data is unknown or changes frequently.
- **Implementing Stacks and Queues**: As building blocks for more complex data structures.
- **Undo Functionality in Software**: Storing previous states of data.

## Implementations

This repository provides example implementations of linked lists using C programming language:
1. **LinkedList**: See `LinkedList.c`.