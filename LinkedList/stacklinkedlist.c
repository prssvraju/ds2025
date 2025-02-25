#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct stack{
    struct node *top;
};
void push(struct stack*,int);
int pop(struct stack*);
int peek(struct stack*);
void display(struct stack*);
struct node * getnode();

int main()
{
        int ele,ch;
        struct stack st;
        st.top=NULL;
      
       while(1)
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

struct node* getnode()
{
    struct node *np;
    np=(struct node *)malloc(sizeof(struct node));
    np->data=0;
    np->next=NULL;
    return np;
}

void push(struct stack *st,int ele)
{
    struct node *newnode=getnode();
    newnode->data=ele;
    if(st->top==NULL)
    {
        st->top=newnode;
    }
    else{
        newnode->next=st->top;
        st->top=newnode;
    }
}
int peek(struct stack *st)
{
    int ele;
    if(st->top==NULL)
    {
        return -1;
    }
    else
    {
        ele=st->top->data;
        return ele;

    }
}
int pop(struct stack *st)
{
    int ele;
    if(st->top==NULL)
    {
        return -1;
    }
    else
    {
        ele=st->top->data;
        st->top=st->top->next;
        return ele;
    }
}
void display(struct stack *st)
{
    struct node *temp;
    temp=st->top;
    while (temp!=NULL)
    {
        printf("\n|%d|",temp->data);
        temp=temp->next;
    }
}
