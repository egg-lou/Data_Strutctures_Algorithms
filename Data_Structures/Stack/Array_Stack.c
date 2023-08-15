/*
    Array Implementation of Stack Data Structure
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x);
void Pop();
int Top();

int main(){

    int choice;

    while(choice != 4){

        printf("\nChoose one Operation\n");
        printf("\n1. Insert\n");
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

                for(int i = top; i >= 0; i--){
                    printf("\n%d ", A[i]);
                }
                printf("\n");
                break;
            }

            case 2: {
                printf("Remove Recent Number: %d\n\n", Top());

                Pop();
                
                for(int i = top; i >= 0; i--){
                    printf("\n%d ", A[i]);
                }
                printf("\n");
                break;
            }

            case 3: {
                printf("The Most Recent Number: %d\n", Top());
            }
            break;
        }
    }

    return 0;
}

void Push(int x){
    if(top == MAX_SIZE -1){
        printf("\nStack Overflow\n");
        return;
    }
    A[++top] = x;
}

void Pop(){
    if(top == -1){
        printf("\nError: No Element to Pop\n");
        return;
    }
    top--;
}

int Top(){
    return A[top]; 
}