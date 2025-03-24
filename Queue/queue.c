#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct queue
{
    int items[MAX];
    int front,rear;
};
void enqueue(struct queue*,int);
int dequeue(struct queue*);
void display(struct queue*);
int main()
{
    int ch,ele;
    struct queue qu;
    qu.front=0;
    qu.rear=-1;    
    while(1)
    {
        printf("\n**** Menu *****\n");
        printf("\n1.Enque");
        printf("\n2.Deque");
        printf("\n3.display");
        printf("\n4.Queue is Empty");
        printf("\n5.Exit");
        printf("\nEnter your option\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
                printf("\nEnter element to insert\n");
                scanf("%d",&ele);
                enqueue(&qu,ele);
                break;
        case 2:
                ele=dequeue(&qu);
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                else
                {
                    printf("Removed element is %d\n",ele);
                }
                break;
        case 3:
                display(&qu);
                break;
        case 4:
                // ele=peek(&st);
                // if(ele==-1)
                // {
                //     printf("Stack is empty");
                // }
                // else
                // {
                //     printf("First element is %d\n",ele);
                // }
                // break;
        case 5:
                exit(0);
                break;
        default:
                printf("Invalid Choice");  
                break;
        }
    }
    

    return 0;
}
void enqueue(struct queue *qu,int ele)
{
    if(qu->rear==MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        qu->rear=qu->rear+1;       
        qu->items[qu->rear]=ele;
    }
}
int dequeue(struct queue *qu)
{
    int ele;
    if(qu->rear<qu->front)
    {
        return -1;
    }
    else
    {
        ele=qu->items[qu->front];
        qu->front=qu->front+1;
        return ele;
    }
}
// int peek(struct stack *st)
// {
//     int ele;
//     if(st->top==-1)
//     {
//         return -1;
//     }
//     else
//     {
//         ele=st->items[st->top];
//         return ele;
//     }
// }
void display(struct queue *qu)
{
    int i;
    if(qu->rear<qu->front)
    {
        printf("Q is empty");
    }
    else
    {
        for(i=qu->front;i<=qu->rear;i++)
        {
            printf("|%d|\n",qu->items[i]);
        }
    }
}