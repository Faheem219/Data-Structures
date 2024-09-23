#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

typedef struct Node node;

void create(){
    node *p;
    int data;
    char choice;

    do{
        p = (node *)malloc(sizeof(node));
        printf("\nEnter data: ");
        scanf("%d", &data);
        getchar();

        if(!first){
            p -> data = data;
            p -> next = NULL;
            first = p;
            last = p;
        } else {
            p -> data = data;
            p -> next = NULL;
            last -> next = p;
            last = p;
        }

        printf("\nDo you wish to continue? (Y/N): ");
        scanf("%c", &choice);
    } while(choice == 'y' || choice == 'Y');
    printf("\nList created!\n");
}

void display(){
    node *p = first;

    printf("\n");
    while(p){
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("\n");
}

int count(){
    node *p = first;
    int count = 0;

    while(p){
        count++;
        p = p -> next;
    }
    return count;
}

int middleNode(){
    node *p = first;
    int len = count();

    for(int i = 0; i < (len / 2); i++) p = p -> next;
    return p -> data;
}

void search(int num){
    node *p = first;

    for(int i = 0; i < count(); i++){
        if(p -> data == num){
            printf("\nElement found at %d position.\n", i);
            return;
        }
        p = p -> next;
    }

    printf("\nElement not found!\n");
}

void reverse(node *p){
    if(!p -> next){
        first = p;
        return;
    }

    reverse(p -> next);
    node *q = p -> next;
    q -> next = p;
    p -> next = NULL;
}

void reverseBari(node *q, node *p){
    if(p){
        reverseBari(p, p->next);
        p->next = q;
    }
    else 
        first = q;
}

void delete(){
    node *p = first;
    node *q;

    while(p){
        q = p -> next;
        free(p);
        p = q;
    }
    first = NULL;
}

int main(){
    int choice, num, exit = 1;

    while(exit){
        printf("\nChoose Appropriately:\
        \n1. Create Linked List\
        \n2. Display Linked List\
        \n3. Count Nodes\
        \n4. Find Middle Node\
        \n5. Search Element\
        \n6. Reverse List\
        \n7. Delete List\
        \n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                if(first){
                    printf("\nDelete previous list first!");
                }
                else{
                    create();
                }
                break;
            case 2: 
                display();
                break;   
            case 3:
                printf("\nNumber of nodes: %d\n", count());
                break;
            case 4:
                printf("\nMiddle node: %d\n", middleNode());
                break;
            case 5:
                printf("\nEnter element to search: ");
                scanf("%d", &num);
                getchar();
                search(num);
                break;
            case 6:
                reverseBari(NULL, first);
                printf("\nList reversed\n");
                break;
            case 7:
                delete();
                printf("\nList deleted!\n");
                break;
            case 8:
                exit = 0;
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}