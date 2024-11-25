#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define arr_size 10
void Randomint(int *arr,int count){ 
    for (int i=0;i<count;i++)
        arr[i]=(rand()%100)+1; 
}
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c; 
}
int partition(int arr[], int p, int r){
    int x=arr[r];
    int i,j;
    i=p-1;
    for(j=p;j<=r-1;j++){
        if(arr[j]<=x){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return(i+1);
}


void QuickSort(int arr[], int p, int r){
    if(p<r){
    int q=partition(arr, p ,r);
    QuickSort(arr, p, q-1);
    QuickSort(arr, q+1, r);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[arr_size];
    Randomint(arr,arr_size);
    
    printf("Original Array: ");
    for(int i=0;i<arr_size;i++)
        printf("%d ",arr[i]);  
     
    clock_t begin = clock(); 
    QuickSort(arr,0,arr_size-1);
    clock_t end = clock();
    double time_spent = end-begin;
    printf("\nSorted Array: ");
    for(int i=0;i<arr_size;i++)
        printf("%d ",arr[i]);
       
    printf("\nTime spent: %f seconds", time_spent / (double)CLOCKS_PER_SEC);
}