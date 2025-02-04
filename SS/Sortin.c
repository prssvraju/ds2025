#include<stdio.h>
void b_sort(int[],int);
<<<<<<< HEAD
void s_sort(int[],int);
void i_sort(int[],int);
=======
>>>>>>> 3852a94dd5f94115749532d5d7fa63478427f9ff
int main()
{
    int arr[10],n,i;
    printf("Enter the size of array less than 10");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
<<<<<<< HEAD
    i_sort(arr,n);
=======
    s_sort(arr,n);
>>>>>>> 3852a94dd5f94115749532d5d7fa63478427f9ff
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

void s_sort(int a[10],int n)
{
    int i,j,temp,min;
    printf("====SelectionSort=====\n");
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }

}
void i_sort(int a[10],int n)
{
    int i,j,temp;
    printf("====InsertionSort=====\n");
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1]=temp;
    }
}
