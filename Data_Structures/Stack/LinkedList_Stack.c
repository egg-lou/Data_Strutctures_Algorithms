/*
    Linked List Implementation of Stack
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x);
void Pop();
int Top();
void PrintList();

int main() {
    int choice;

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

                PrintList();

                break;
            }

            case 2: {
                if (top == NULL) {
                    printf("Error: No Element to Pop\n");
                } else {
                    printf("Removed Element: %d\n", Top());
                    Pop();
                    PrintList();
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
    top = temp;
}

void Pop() {
    if (top == NULL) {
        printf("Error: No Element to Pop\n");
        return;
    }
    struct Node* temp = top;
    top = top->link;
    free(temp);
}

int Top() {
    return top->data;
}

void PrintList(){
    printf("Current List: ");
    struct Node* current = top;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}
