#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void push(int);
int pop();
int peek();
void display();
int items[MAX],top=-1;
int main()
{
  int ch,ele;
  //top=-1;
  while (1)
  {
     printf("\n1.push\n2.pop\n3.peek\n4.diplay\n5.exit");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1: printf("Enter element to push");
                scanf("%d",&ele);
                push(ele);
                break;
        case 2: ele=pop();
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                else
                {
                    printf("The deleted element is %d",ele);
                }
                break; 
        case 3: ele=peek();
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                
                else
                {
                    printf("The top element is %d",ele);
                }
                break;
        case 4: display();
                break;
        case 5: exit(0);
                break;
        default :
                printf("Eneter Valid choice");
                break;
       }
  }

}
void push(int ele)
{
    if(top==MAX-1)
    {
        printf("unable to insert");
    }
    else
    {
        top=top+1;
        items[top]=ele;
    }
}
int pop()
{
    int ele;
    if(top==-1)
    {
        return -1;
    }
    else
    {
        ele=items[top];
        top=top-1;
        return ele;
    }

}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n|%d|",items[i]);
        }
    }
}
int peek()
{
    int ele;
    if(top==-1)
    {
        return -1;
    }
    else
    {
        ele=items[top];
        return ele;
    }

}