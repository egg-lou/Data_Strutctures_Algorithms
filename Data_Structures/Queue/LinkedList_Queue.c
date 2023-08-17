#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* queue, int data);
void dequeue(Queue* queue);
int front(Queue* queue);
bool isEmpty(Queue* queue);
void printQueue(Queue* queue);

int main() {
    Queue* queue = createQueue();

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

                enqueue(queue, number);

                printQueue(queue);
                break;
            }

            case 2: {
                if (isEmpty(queue)) {
                    printf("Queue is empty.\n");
                    break;
                }

                dequeue(queue);

                printQueue(queue);
                break;
            }

            case 3: {
                if (isEmpty(queue)) {
                    printf("Queue is empty.\n");
                    break;
                }

                printf("The First in Queue is %d\n", front(queue));
                break;
            }
        }
    }

    // Free memory used by the queue
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);

    return 0;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element.\n");
        return -1; // Return a default value or handle the error as needed.
    }
    return queue->front->data;
}

bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Current Queue: ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
