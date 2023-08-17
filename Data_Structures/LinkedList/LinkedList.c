#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** head, int data);
void insertPosition(struct Node** head, int data, int position);
void insertEnd(struct Node** head, int data);

void deleteFront(struct Node** head);
void deletePosition(struct Node** head, int position);
void deleteEnd(struct Node** head);

void display(struct Node* head);
void freeList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nChoose one Operation\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Specific Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at Specific Position\n");
        printf("6. Delete at End\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Response: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("\nEnter Number to Insert at Front: ");
                scanf("%d", &data);

                insertFront(&head, data);

                printf("Element %d inserted at the front.\n", data);
                break;
            }

            case 2: {
                printf("\nEnter Number to Insert: ");
                scanf("%d", &data);
                printf("Enter Position: ");
                scanf("%d", &position);

                insertPosition(&head, data, position);

                printf("Element %d inserted at position %d.\n", data, position);
                break;
            }

            case 3: {
                printf("\nEnter Number to Insert at End: ");
                scanf("%d", &data);

                insertEnd(&head, data);

                printf("Element %d inserted at the end.\n", data);
                break;
            }

            case 4: {
                deleteFront(&head);
                printf("Deleted element from the front.\n");
                break;
            }

            case 5: {
                printf("\nEnter Position to Delete: ");
                scanf("%d", &position);

                deletePosition(&head, position);

                printf("Element at position %d deleted.\n", position);
                break;
            }

            case 6: {
                deleteEnd(&head);
                printf("Deleted element from the end.\n");
                break;
            }

            case 7: {
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("Linked List: ");
                    display(head);
                }
                break;
            }

            case 8: {
                // Free memory used by the linked list
                freeList(head);
                printf("Exiting the program.\n");
                exit(0);
            }

            default: {
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }

    return 0;
}

void insertFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertPosition(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertFront(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deletePosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteFront(head);
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    int i;

    for (i = 1; i < position && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}