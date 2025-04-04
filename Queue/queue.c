#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct queue
{   
    int items[MAX];
    int rear,front;
};
void enqueue(struct queue*,int);
int dequeue(struct queue*);
//int peek(struct queue*);
void display(struct queue*);


int main()
{
  int ch,ele;
  //top=-1;
  struct queue qu;
  qu.rear=-1;
  qu.front=0;
  while (1)
  {
     printf("\n1.Enqueue\n2.Dequeue\n3.peek\n4.diplay\n5.exit");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1: printf("Enter element to Enqueue");
                scanf("%d",&ele);
                enqueue(&qu,ele);
                break;
        case 2: ele=dequeue(&qu);
                if(ele==-1)
                {
                    printf("Queue is empty");
                }
                else
                {
                    printf("The deleted element is %d",ele);
                }
                break; 
        // case 3: ele=peek(&qu);
        //         if(ele==-1)
        //         {
        //             printf("queue is empty");
        //         }
                
        //         else
        //         {
        //             printf("The top element is %d",ele);
        //         }
                break;
        case 4: display(&qu);
                break;
        case 5: exit(0);
                break;
        default :
                printf("Eneter Valid choice");
                break;
       }
  }

}
void enqueue(struct queue *qu, int ele)
{
    if(qu->rear==MAX-1)
    {
        printf("unable to insert :: Queu is full");
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
void display(struct queue *qu)
{
    int i;
    if(qu->rear<qu->front)
    {
        printf("stack is empty");
    }
    else
    {
        for(i=qu->front;i<=qu->rear;i++)
        {
            printf("\n|%d|",qu->items[i]);
        }
    }
}
// int peek(struct stack *stp)
// {
//     int ele;
//     if(stp->top==-1)
//     {
//         return -1;
//     }
//     else
//     {
//         ele=stp->items[stp->top];
//         return ele;
//     }

// }
