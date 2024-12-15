#include<stdio.h>
int max,min;
void maxmin_dac(int arr[],int i,int j)
{
    int max1,min1,mid;
    if(i == j)
    max = min = arr[i];
    else if(i == j-1)
    {
        if(arr[i] < arr[j])
        {
            max = arr[j],min = arr[i];
        }
        else
        {
           max = arr[i],min = arr[j];
        }
    }
    else{
        mid = (i+j)/2;
        maxmin_dac(arr,i,mid);
        max1 = max,min1 = min;
        maxmin_dac(arr,mid+1,j);
        if(max1> max)
        max = max1;
        if(min1<min)
        min=min1;
    }
}
int main()
{
    int arr[6]={2,7,4,5,6,1};
    max=min=arr[0];
    maxmin_dac(arr,0,6-1);
    printf("%d\n",max);
    printf("%d\n",min);
    return 0;
}