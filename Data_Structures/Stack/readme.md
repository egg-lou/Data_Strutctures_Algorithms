# Introduction to Stacks

## Stack as an Abstract Data Type

A **stack** is a fundamental abstract data type that follows the **Last-In-First-Out (LIFO)** principle. This means that the last item added to the stack is the first one to be removed. It has a simple and essential logical view with distinct features and operations.

### Real-World Examples

1. Stack of Plates
2. Tower of Hanoi
3. Pack of Tennis Balls

## Stack Characteristics

In a stack:
- An item can only be inserted or removed from one end, known as the **top of the stack**.
- Only the top element is accessible at any given time.
- It enforces the **LIFO** collection behavior, ensuring that the most recently added item is the first to be removed.

## Operations

1. **Push(x)**: Adds an element to the top of the stack.
2. **Pop()**: Removes the top element from the stack.
3. **Top()**: Retrieves the element at the top of the stack without removing it.
4. **IsEmpty()**: Returns `True` if the stack is empty; otherwise, returns `False`.

These operations have a constant time complexity of **O(1)**.

## Applications

Stacks find applications in various scenarios, including:

- **Function Calls / Recursion**: Stacks are used to manage function calls and their respective contexts.
- **Implementing UNDO Operation for Editors**: Stacks can store previous states to enable the undo functionality.
- **Balanced Parentheses**: Stacks help validate expressions by checking the balance of parentheses and other symbols.

## Implementations of Stacks

Stacks can be implemented using different data structures, such as:

1. **Arrays**: See `Array_Stack.c` for an example implementation.
2. **Linked Lists**: See `LinkedList_Stack.c` for an example implementation.
3. **ReverseString**: See `ReverseString.cpp` for an example implementation.