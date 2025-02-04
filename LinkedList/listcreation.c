#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *add;
};
int  main()
{
    int ch;
    while(1)
    {
       printf("1.create\n2.insert\n3.delete\n4.exit");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1: printf("created");
                break;
        case 2: printf("Inserted");
                break;
        case 3: printf("Deleted");
                break;
        case 4: exit(0);
                break;
        default :
                printf("Eneter Valid choice");
                break;
       }
    }
    

}