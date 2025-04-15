#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack
{   
    char items[MAX];
    int top;
};
struct queue
{   
    char items[MAX];
    int rear,front;
};
void enqueue(struct queue*,char);
char dequeue(struct queue*);
void push(struct stack*,char);
char pop(struct stack*);
int isPalandrom(char []);
int strLen(char []);


void push(struct stack *stp, char ele)
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
char pop(struct stack *stp)
{
    char ele;
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
void enqueue(struct queue *qu, char ele)
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
char dequeue(struct queue *qu)
{
    char ele;
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
int strLen(char str[10])
{
    int len=0,i;
    for(i=0;str[i]!='\0';i++)
    {
        len=len+1;
    }
    return len;
}
int isPalandrom(char str[10])
{
    int len,i;
    struct stack st;
    struct queue qu;

    st.top=-1;
    qu.rear=-1;
    qu.front=0;
    len =strLen(str);
    // printf("%s",str);
    // printf("%d",strLen(str));
    for(i=0;i<len;i++)
    {
        push(&st,str[i]);
        enqueue(&qu,str[i]);
    }
    for(i=0;i<len;i++)
    {
        if(pop(&st)!=dequeue(&qu))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char str[10];
    printf("Enter String");
    scanf("%s",str);
    if(isPalandrom(str))
    {
        printf("\n NotPlandrom");
    }
    else
    {
        printf("\n Plandrom");
    }
}