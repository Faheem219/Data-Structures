#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

typedef struct Node node;

void push(int data){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> next = top;
    top = temp;
}

int pop(){
    node *temp;
    int x = -1;
    if(top == NULL) printf("\nStack is empty.");
    else{
        temp = top;
        top = top -> next;
        x = temp -> data;
        free(temp);
    }
    return x;
}

int main(){
    int choice, data;
    while(1){
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter data to be pushed to stack: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                printf("\nPoped data from stack: %d\n", pop());
                break;
            case 3: 
                exit(0);
            default:
                printf("\nInvalid choice! Please enter valid choice.\n");
        }
    }
    return 0;
}