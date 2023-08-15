    INTRODUCTION TO STACKS

    STACK AS ABSTRACT DATA TYPE
    - Only logical view of stack
    - Features/Operations

    Real Word Examples:
        1. Stack of Plates
        2. Tower of Hanoi
        3. Pack of Tennis Balls

    Stack is a collection wherein an item in a stack must only be inserted or removed from the same end that is called 
    the TOP OF STACK which is a constrain, only the top of the stack is accessible
    or
    A list with the restriction that insertion and deletion can be performed only from one end called the top

    L-I-F-O Collection 
    or
    Last - In - First - Out 

    OPERATION
        (1) Push(x) - Inserting an element on top of te stack
        (2) Pop() - Removing the most recent item from the stack / the top item of the stack
        (3) Top() - Returns the element at the top of the stack
        (4) IsEmpty() - Returns a boolean value True or False if the stack is empty or not

    Time Complexity - Constant Time or O(1)

    APPLICATIONS:
        - Function Calls / Recursion
        - Implement UNDO Operation for editors
        - Balanced Parentheses

    IMPLEMENTATION OF STACKS

    We can implement stacks using:
        (1) Arrays 
            - See Array_Stack.c
        (2) Linked Lists
            - See LinkedList_Stack.c

