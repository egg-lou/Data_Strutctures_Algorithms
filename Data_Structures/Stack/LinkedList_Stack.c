/*
    Linked List Implementation of Stack
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL; // Pointer to the top node of the stack

// Function prototypes
void Push(int x);
void Pop();
int Top();
void PrintList();

int main() {
    int choice;

    // Menu-driven loop to perform stack operations
    while (choice != 4) {
        printf("\nChoose one Operation\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. View Top Element\n");
        printf("4. Exit\n");

        printf("\nResponse: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int number;
                printf("\nEnter Number to Insert: ");
                scanf("%d", &number);
                printf("Adding %d to the stack\n", number);

                Push(number);

                PrintList(); // Display the current stack contents

                break;
            }

            case 2: {
                if (top == NULL) {
                    printf("Error: No Element to Pop\n");
                } else {
                    printf("Removed Element: %d\n", Top());
                    Pop();
                    PrintList(); // Display the current stack contents
                }
                break;
            }

            case 3: {
                if (top == NULL) {
                    printf("Stack is Empty\n");
                } else {
                    printf("Top Element: %d\n", Top());
                }
                break;
            }
        }
    }

    return 0;
}

void Push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp; // Update the top pointer to the new node
}

void Pop() {
    if (top == NULL) {
        printf("Error: No Element to Pop\n");
        return;
    }
    struct Node* temp = top;
    top = top->link; // Update the top pointer to the next node
    free(temp); // Free the memory of the removed node
}

int Top() {
    return top->data; // Return the data of the top node
}

void PrintList(){
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Current List: ");
    struct Node* current = top;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}
