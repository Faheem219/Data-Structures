#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
};

struct Node* root = NULL;

// Insert function
void Insert(int key) {
    struct Node* t = root;
    struct Node* r = NULL;
    struct Node* p;

    if (root == NULL) {
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL) {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }

    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

// Inorder traversal
void Inorder(struct Node* p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// Search function
struct Node* Search(int key) {
    struct Node* t = root;
    while (t != NULL) {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

// Main function
int main() {
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(25);

    printf("Inorder Traversal: ");
    Inorder(root);
    printf("\n");

    struct Node* search = Search(25);
    if (search)
        printf("Element found: %d\n", search->data);
    else
        printf("Element not found.\n");

    return 0;
}