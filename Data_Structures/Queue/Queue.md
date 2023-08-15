# Introduction to Queues

## Queue as an Abstract Data Type

A **queue** is a fundamental abstract data type that follows the **First-In-First-Out (FIFO)** principle. This means that the first item added to the queue is the first one to be removed. It has a straightforward logical view with distinct features and operations.

### Real-World Examples

1. Waiting in Line
2. Print Queue
3. Breadth-First Search (BFS) in Graphs

## Queue Characteristics

In a queue:
- An item can be inserted at the **rear** and removed from the **front**.
- The **front** item is the one that has been in the queue the longest.
- It enforces the **FIFO** collection behavior, ensuring that the first item added is the first to be removed.

## Operations

1. **Enqueue(x)**: Adds an element to the rear of the queue.
2. **Dequeue()**: Removes the front element from the queue.
3. **Front()**: Retrieves the front element without removing it.
4. **IsEmpty()**: Returns `True` if the queue is empty; otherwise, returns `False`.

These operations generally have a constant time complexity of **O(1)**.

## Applications

Queues find applications in various scenarios, including:

- **Task Scheduling**: Managing tasks in the order they are received.
- **Print Queue**: Handling print jobs in the order they are submitted.
- **Breadth-First Search (BFS)**: Exploring graph structures layer by layer.

## Implementations of Queues

Queues can be implemented using different data structures, such as:

1. **Arrays**: See `Array_Queue.c` for an example implementation.
2. **Linked Lists**: See `LinkedList_Queue.c` for an example implementation.

Choose the implementation based on your specific use case and programming preferences.