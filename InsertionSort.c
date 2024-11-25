#include <stdio.h>
#include <time.h>
int main() {
    clock_t begin=clock();
    int arr[]={5,9,7,132,4,0,34,100,67,43,21,2,54,3};
    //int n;
    //printf("Enter the number of elements: ");
    //scanf("%d", &n);
    //int arr[n];
    //printf("Enter %d elements:\n", n);
    //for (int i = 0; i < n; i++) 
    //{
    //    scanf("%d", &arr[i]);
    //}
	for(int j=1;j<14;j++){
        int key=arr[j];
        int i=j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    } 
    for(int k =0; k<14; k++)
    printf("%d ", arr[k]);
    clock_t end=clock();
    double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime spent:.%f secs",time_spent);
}