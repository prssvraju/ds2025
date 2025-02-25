#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void push(struct stack*,int);
int pop(struct stack*);
int peek(struct stack*);
void display(struct stack*);

struct stack
{   
    int items[MAX];
    int top;
};

int main()
{
  int ch,ele;
  //top=-1;
  struct stack st;
  st.top=-1;
  while (1)
  {
     printf("\n1.push\n2.pop\n3.peek\n4.diplay\n5.exit");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1: printf("Enter element to push");
                scanf("%d",&ele);
                push(&st,ele);
                break;
        case 2: ele=pop(&st);
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                else
                {
                    printf("The deleted element is %d",ele);
                }
                break; 
        case 3: ele=peek(&st);
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                
                else
                {
                    printf("The top element is %d",ele);
                }
                break;
        case 4: display(&st);
                break;
        case 5: exit(0);
                break;
        default :
                printf("Eneter Valid choice");
                break;
       }
  }

}
void push(struct stack *stp, int ele)
{
    if(stp->top==MAX-1)
    {
        printf("unable to insert");
    }
    else
    {
        stp->top=stp->top+1;
        stp->items[stp->top]=ele;
    }
}
int pop(struct stack *stp)
{
    int ele;
    if(stp->top==-1)
    {
        return -1;
    }
    else
    {
        ele=stp->items[stp->top];
        stp->top=stp->top-1;
        return ele;
    }

}
void display(struct stack *stp)
{
    int i;
    if(stp->top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        for(i=stp->top;i>=0;i--)
        {
            printf("\n|%d|",stp->items[i]);
        }
    }
}
int peek(struct stack *stp)
{
    int ele;
    if(stp->top==-1)
    {
        return -1;
    }
    else
    {
        ele=stp->items[stp->top];
        return ele;
    }

}