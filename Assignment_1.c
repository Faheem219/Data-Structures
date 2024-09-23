#include <stdio.h>
#include <stdlib.h>

int linearSearch(int a[], int len, int key){
    int count = 0;

    for(int i = 0; i < len; i++){
        if(a[i] == key) 
            count++;
    }

    return count;
}

int binarySearch(int a[], int len, int key){
    int l = 0, mid;
    int h = len - 1;
    
    while(l <= h){
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key > a[mid])
            l = mid + 1;
        else 
            h = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(int a[], int l, int h, int key){
    int mid;

    if(l <= h){
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return recursiveBinarySearch(a, l, mid - 1, key);
        else
            return recursiveBinarySearch(a, mid + 1, h, key);
    }

    return -1;
}

int main(){
    int *a;
    int n, key;

    printf("\nEnter size of array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    printf("\nEnter elements of the array:\n");
    for(int i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    printf("\nEnter key to search: ");
    scanf("%d", &key);

    linearSearch(a, n, key) ? printf("\nElement found with %d occurances (LS).\n", linearSearch(a, n, key)) : printf("\nElement not found (LS).\n");
    (binarySearch(a, n, key) == -1) ? printf("\nElement not found (BS).\n") : printf("\nElement found at index %d (BS).\n", binarySearch(a, n, key));
    (recursiveBinarySearch(a, 0, n - 1, key) == -1) ? printf("\nElement not found (RBS).\n") : printf("\nElement found at index %d (RBS).\n", recursiveBinarySearch(a, 0, n - 1, key));

    return 0;
}