#include<stdio.h>
void b_sort(int[],int);
int main()
{
    int arr[10],n,i;
    printf("Enter the size of array less than 10");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    s_sort(arr,n);
    printf("After Sorting");
    for(i=0;i<n;i++)
    {
        printf("\n%d",arr[i]);
    }
}
void b_sort(int a[10],int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
