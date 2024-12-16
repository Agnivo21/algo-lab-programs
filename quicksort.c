#include<stdio.h>
void swap(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i = low,j = high;

    while(i < j )
    {
        while(arr[i] <= pivot && i <= high-1)
        {
            i++;
        }
        while(arr[j] > pivot && j >= low+1)
        {
            j--;
        }
        if(i < j)
        swap(&arr[i],&arr[j]);
        else
        swap(&arr[low],&arr[j]);
    }
    return j;
}
void quicksort(int arr[],int low, int high)
{
if(low <high)
{
    int partitionindex = partition(arr,low,high);
    quicksort(arr,low,partitionindex-1);
    quicksort(arr,partitionindex+1,high);
}
}
int main(){
    int arr[]={19,7,12,8,16};
    quicksort(arr,0,4);
    for(int i = 0 ; i < 5 ;i++)
    printf("%d ",arr[i]);
    return 0;
}