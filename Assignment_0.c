# include<stdio.h>
# include<stdlib.h>

// Create and print an array:
void printArray(int A[], int n){
    printf("\nArray is:\n");
    for(int i=0; i<n; i++) printf("%d ", A[i]);
    printf("\n");
}

// Find the largest number from the array:
int maxNumber(int A[], int n){
    int max = A[0];
    for(int i=1; i<n; i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}

// Find the second largest number from the array:
int secondLargest(int A[], int n){
    int max = maxNumber(A, n);
    int secLargest = A[0];
    for(int i=0; i<n; i++){
        if(A[i]>secLargest && A[i]!=max) secLargest = A[i];
    }
    return secLargest;
}

// Find factorial of a number using any loop:
int factLoop(int n){
    int factorial = 1;
    for(int i=n; i>0; i--) factorial *= i;
    return factorial;
}

// Find factorial using Recursion:
int factRecursion(int n){
    if(n==0) return 1;
    return n*factRecursion(n-1);
}

// To display Fibonacci using any loop:
void fibLoop(int n){
    if(n<=0){
        printf("\nInvalid number of elements!");
        return;
    }
    if(n==1){
        printf("0 ");
        return;
    }

    int *A;
    A = (int *)malloc(n*sizeof(int));
    A[0] = 0; A[1] = 1;

    for(int i=2; i<n; i++){
        A[i] = A[i-1] + A[i-2];
    }
    printArray(A, n);
}

// To display Fibonacci series using recursion:
int fibRecursion(int n){
    if(n<=0) return -1;
    if(n==1) return 0;
    if(n==2) return 1;
    return fibRecursion(n-1) + fibRecursion(n-2);
}

int main(){
    int A[10] = {10, 20, 30, 40, 50 ,60};
    int size = sizeof(A)/sizeof(int);
    int A1[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};
    int A2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int C[3][3];

    printArray(A, size);
    printf("\nLargest Element = %d\n", maxNumber(A, size));
    printf("\nSecond largest element = %d\n", secondLargest(A, size));
    printf("\nFactorial of 5 using loop = %d\n", factLoop(5));
    printf("\nFactorial of 5 using recursion = %d\n", factRecursion(5));
    printf("\nFibonacci using Loop (5 elements):"); fibLoop(5);
    printf("\nFibonacci series using recursion (5 elements):\n");
    for(int i=0; i<5; i++){
        printf("%d ", fibRecursion(i+1));
    }
    printf("\n");

    // Program for matrix multiplication:
    printf("\nMatrix Multiplication (A1 x A1):\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j] = 0;
            for(int k=0;k<3;k++){
                C[i][j]=C[i][j]+(A1[i][k]*A1[k][j]);
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    // Program for transpose of a matrix:
    printf("\nMatrix A2 (Transpose):\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d ", A2[j][i]);
        }
        printf("\n");
    }
}