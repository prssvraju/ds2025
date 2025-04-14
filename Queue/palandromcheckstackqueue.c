#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
struct stack
{
    char items[MAX];
    int top;
};
struct queue
{
    char items[MAX];
    int front,rear;
};
void enqueue(struct queue*,char);
char dequeue(struct queue*);
void display(struct queue*);
void push(struct stack*,char);
char pop(struct stack*);
int palandrom(char []);
int strLength(char []);
void push(struct stack *stp,char ele)
{
    if(stp->top==MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        stp->top=stp->top+1;       
        stp->items[stp->top]=ele;
    }
}
char pop(struct stack *st)
{
    char ele;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        ele=st->items[st->top];
        st->top=st->top-1;
        return ele;
    }
}
void enqueue(struct queue *qu,char ele)
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
int strLength(char str[10])
{
    int len,i;
    for(i=1;str[i]!='\0';i++)
    {
        len=len+1;
    }
    return len;
}
int palandrom(char str[10])
{
    int len,i;
    struct stack st;
    struct queue qu;
    st.top=-1;
    qu.rear=-1;
    qu.front=0;

    printf("%s",str);
    len=strLength(str);

    for(i=0;i<len;i++)
    {
        //printf("\n%c",str[i]);
        push(&st,str[i]);
        enqueue(&qu,str[i]);
    }
    for(i=0;i<len;i++)
    {
       if(pop(&st) != dequeue(&qu))
       {
        return 0;
       }
    }
    return 1;
}
int main()
{
    char str[MAX];
    printf("Enter Name");
    scanf("%s",str);
    //str[strcspn(str, "\n")] = '\0';
    if(palandrom(str))
    {
        printf("\nPandrom");
    }
    else
    {
        printf("\nNot a plandrom");
    }
    return 0;
}