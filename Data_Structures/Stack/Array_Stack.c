/*
    Array Implementation of Stack Data Structure
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];  // Array to store stack elements
int top = -1;     // Index of the top element in the stack

// Function prototypes
void Push(int x);
void Pop();
int Top();
void PrintStack();

int main(){

    int choice;

    // Menu-driven loop to perform stack operations
    while(choice != 4){

        printf("\nChoose one Operation\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. View Top Element\n");
        printf("4. Exit\n");

        printf("\nResponse: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: {
                int number;

                printf("\nEnter Number to Insert: ");
                scanf("%d", &number);
                printf("\nAdding %d to the stack\n", number);

                Push(number);

                PrintStack();  // Display the current stack contents
                break;
            }

            case 2: {
                if(Top() == -1)
                    break;

                printf("Removed %d from the stack\n", Top());
                Pop();
                
                PrintStack();  // Display the current stack contents
                break;
            }

            case 3: {
                if(Top() == -1)
                    break;

                printf("The Most Recent Number: %d\n", Top());
                break;
            }
        }
    }

    return 0;
}

void Push(int x){
    if(top == MAX_SIZE -1){
        printf("\nStack Overflow\n");
        return;
    }
    A[++top] = x; // Increment top and add element to the stack
}

void Pop(){
    if(top == -1){
        printf("\nError: No Element to Pop\n");
        return;
    }
    top--; // Decrement top to remove the top element from the stack
}

int Top(){
    if(top == -1){
        printf("Stack is Empty\n");
        return -1;
    }
    return A[top]; // Return the element at the top of the stack
}

void PrintStack(){
    if(top == -1){
        printf("Stack is Empty\n");
        return;
    }

    printf("Current Stack: ");
    for(int i = top; i >= 0; i--){
        printf("%d ", A[i]);
    }
    printf("\n");
}
