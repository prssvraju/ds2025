#include<stdio.h>
int main()
{
    int i, n, a[10],key,low,high,mid;
    printf("Enter size of array less than 10");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the key value");
    scanf("%d", &key);
    low=0;
    high=n-1;
    while(low<high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            printf("Element is found at %d",mid);
            break;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(low>=high)
    {
        printf("Element not found");

    }
}