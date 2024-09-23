#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

typedef struct Node node;

void enqueue(int data){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL;
    if(!first) first = last = temp;
    else{
        last -> next = temp;
        last = temp;
    }
}

int dequeue(){
    int x = -1;
    if(!first) printf("\nQueue is empty!\n");
    else{
        node *temp = first;
        first = first -> next;
        x = temp -> data;
        free(temp);
    }
    return x;
}

int main(){
    int choice, data;
    while(1){
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter data to be added to queue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("\nDequeued data from queue: %d\n", dequeue());
                break;
            case 3: 
                exit(0);
            default:
                printf("\nInvalid choice! Please enter valid choice.\n");
        }
    }
    return 0;
}