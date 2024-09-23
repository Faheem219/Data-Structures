#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortAdaptive(int a[], int n){
    int flag;

    for(int i = 0; i < n - 1; i++){
        flag = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }

        if(flag == 0) break;
    }
}

void selectionSort(int a[], int n){
    int minIndex;

    for(int i = 0; i < n - 1; i++){
        minIndex = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        if(minIndex != i)
            swap(&a[i], &a[minIndex]);
    }
}

void insertionSort(int a[], int n){
    int i, j, x;

    for(i = 1; i < n; i++){
        j = i - 1;
        x = a[i];
        while(j > -1 && a[j] > x){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = x;
    }
}

int main(){
    int *a;
    int n;

    printf("\nEnter size of array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    printf("\nEnter elements of the array:\n");
    for(int i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    // bubbleSortAdaptive(a, n);
    // selectionSort(a, n);
    insertionSort(a, n);

    printf("\nSorted Array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}