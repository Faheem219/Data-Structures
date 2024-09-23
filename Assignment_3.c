#include <stdio.h>
#include <stdlib.h>

void Merge(int a[], int l, int mid, int h){
    int i = l, j = mid + 1, k = l;
    int b[100];

    while(i <= mid && j <= h){
        if(a[i] < a[j])
            b[k++] = a[i++];
        else   
            b[k++] = a[j++];
    }
    for(; i <= mid; i++)
        b[k++] = a[i];
    for(; j <= h; j++)
        b[k++] = a[j];

    for(i = l; i <= h; i++)
        a[i] = b[i];
}

void MergeSort(int a[], int l, int h){
    int mid;

    if(l < h){
        mid = (l + h) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, h);
        Merge(a, l, mid, h);
    }   
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int h){
    int pivot = a[l];
    int i = l, j = h;
    
    do{
        do{i++;}while(a[i] <= pivot);
        do{j++;}while(a[i] > pivot);
        if(i < j) swap(&a[i], &a[j]);
    } while(i < j);

    swap(&a[l], &a[j]);
    return j;
}

void QuickSort(int a[], int l, int h){
    int j;

    if(l < h){
        j = partition(a, l, h);
        QuickSort(a, l, j);
        QuickSort(a, j + 1, h);
    }
}

int main(){
    int *A;
    int n;
    printf("\nEnter no. of elements of array: ");
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));

    printf("\nEnter elements of the array:\n");
    for(int i = 0; i < n; i++) 
        scanf("%d", &A[i]);

    MergeSort(A, 0, n - 1);
    // QuickSort(A, 0, n - 1);
    printf("\nSorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}