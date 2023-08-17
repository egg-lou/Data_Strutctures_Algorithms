#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int A[MAX_SIZE];
int front = -1;
int rear = -1;
int itemCount = 0; // Keep track of the number of items in the queue

void Enqueue(int x);
void Dequeue();
int Front();
bool IsEmpty();
bool IsFull();
void PrintQueue();

int main() {
    int choice;

    while (choice != 4) {
        printf("\nChoose one Operation\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. View First in Queue\n");
        printf("4. Exit\n");

        printf("Response: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int number;
                printf("\nEnter Number to Insert: ");
                scanf("%d", &number);
                printf("Adding %d to the queue\n", number);

                Enqueue(number);

                PrintQueue();
                break;
            }

            case 2: {
                if (IsEmpty()) {
                    printf("Queue is empty.\n");
                    break;
                }

                Dequeue();

                PrintQueue();
                break;
            }

            case 3: {
                if (IsEmpty()) {
                    printf("Queue is empty.\n");
                    break;
                }

                printf("The First in Queue is %d\n", Front());
                break;
            }
        }
    }

    return 0;
}

void Enqueue(int x) {
    if (IsFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    
    if (IsEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    
    A[rear] = x;
    itemCount++; // Increment the number of items
}

void Dequeue() {
    if (IsEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    
    front = (front + 1) % MAX_SIZE;
    itemCount--; // Decrement the number of items

    if (itemCount == 0) {
        front = rear = -1; // Reset the front and rear when the queue becomes empty
    }
}

int Front() {
    if (IsEmpty()) {
        printf("Queue is empty. No front element.\n");
        return -1; // Return a default value or handle the error as needed.
    }
    return A[front];
}

bool IsEmpty() {
    return itemCount == 0;
}

bool IsFull() {
    return itemCount == MAX_SIZE;
}

void PrintQueue() {
    if (IsEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Current Queue: ");
    
    int count = itemCount;
    int i = front;

    while (count > 0) {
        printf("%d ", A[i]);
        i = (i + 1) % MAX_SIZE;
        count--;
    }
    
    printf("\n");
}
