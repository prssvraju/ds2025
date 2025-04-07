#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front,*rear;
};
void enqueue(struct queue*,int);
int dequeue(struct queue*);
void display(struct queue*);
struct node* getNode();
struct node* getNode()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->data=0;
    newnode->next=NULL;
    return newnode;
}
void enqueue(struct queue *qu,int ele)
{
    struct node *newnode;
    newnode=getNode();
    newnode->data=ele;
    if(qu->front==NULL)
    {
        qu->front=newnode;
        qu->rear=newnode;
    }
    else
    {
        qu->rear->next=newnode;
        qu->rear=newnode;
    }
}
int dequeue(struct queue *qu)
{
    int ele;
    if(qu->front==NULL)
    {
        return -1;
    }
    else
    {
        ele=qu->front->data;
        qu->front=qu->front->next;
        return ele;
    }
}
void display(struct queue *qu)
{
    struct node *temp;
    temp=qu->front;
    if(temp==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("|%d|",temp->data);
            temp=temp->next;  
        }
    }
}

int main()
{
   int ch,ele;
   struct queue qu;
   qu.front=NULL;
   qu.rear=NULL;

  while (1)
  {
       printf("\n1.enqueue\n2.dequeue\n3.diplay\n4.exit");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1: printf("Enter element to push");
                scanf("%d",&ele);
                enqueue(&qu,ele);
                break;
        case 2: 
                ele=dequeue(&qu);
                if(ele==-1)
                {
                    printf("Queue empty");
                }
                else
                {
                    printf("The deleted element is %d",ele);
                }
                break; 
        case 3: display(&qu);
                break;
        case 4: exit(0);
                break;
        default :
                printf("Eneter Valid choice");
                break;
       }
  }
}