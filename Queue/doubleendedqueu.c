#define max 10
#include<stdio.h>
#include<stdlib.h>
struct deque
{
    int front,rear;
    int items[max];
};
void insert_front(struct deque *,int); 
void insert_rear(struct deque *,int); 
int del_front(struct deque *); 
int del_rear(struct deque *); 
int empty(struct deque *);
int peek_front(struct deque *);
int peek_rear(struct deque *);
void display(struct deque *);
int main()
{
    int choice, x;
    struct deque dq;
    dq.front = dq.rear = -1;
    while (1)
    {
        printf("\n\n***************************\n\n");
        printf("\t\tMENU\n");
        printf("\n***************************\n");
        printf("1.insert at front\n2.insert at rear\n3.delete at front\n4.delete at rear");
        printf("\n5.peek at front\n6.peek at rear\n7.Empty\n8.Display\n9.exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element:");
            scanf("%d", &x);
            insert_front(&dq, x);
            printf("\nElements are:");
            display(&dq);
            break;
        case 2:
            printf("\nEnter the element:");
            scanf("%d", &x);
            insert_rear(&dq, x);
            printf("\nElements are:");
            display(&dq);
            break;
        case 3:
            x = del_front(&dq);
            if (x == -1)
                printf("\nqueue is empty");
            else
                printf("\ndeleted element is %d", x);
            printf("\nelements are:");
            display(&dq);
            break;
        case 4:
            x = del_rear(&dq);
            if (x == -1)
                printf("\nqueue is empty");
            else
                printf("\ndeleted element is %d", x);
            printf("\nelements are:");
            display(&dq);
            break;
        case 5:
            x = peek_front(&dq);
            if (x == -1)
                printf("\nCircular queue is empty");
            else
                printf("\nfirst element in Circular queue is:%d", x);
            break;
        case 6:
            x = peek_rear(&dq);
            if (x == -1)
                printf("\nCircular queue is empty");
            else
                printf("\nlast element in Circular queue is:%d", x);
            break;
        case 7:
            x = empty(&dq);
            if (x == 1)
                printf("\nqueue is empty");
            else
                printf("\nqueue is not empty");
                display(&dq);
            break;
        case 8:
            printf("\nElements are\n");
            display(&dq);
            break;
        case 9:
            exit(0);
        }
    }
}

void insert_front(struct deque *dq, int a)
{
    if (((dq->front == 0) && (dq->rear == max - 1)) || (dq->front == dq->rear + 1))
    {
        printf("\nCircular queue is Overflow");
        return;
    }
    else if (dq->front == -1)
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else
    {
        if (dq->front == 0)
            dq->front = max - 1;
        else
            dq->front = dq->front - 1;
    }
    dq->items[dq->front] = a;
}

void insert_rear(struct deque *dq, int a)
{
    if (((dq->front == 0) && (dq->rear == max - 1)) || (dq->front == dq->rear + 1))
    {
        printf("\nCircular queue is Overflow");
        return;
    }
    else if (dq->front == -1)
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else
    {
        if (dq->rear == max - 1)
            dq->rear = 0;
        else
            dq->rear = dq->rear + 1;
    }
    dq->items[dq->rear] = a;
}

int del_front(struct deque *dq)
{
    int a;
    if (dq->front == -1)
        return -1;
    a = dq->items[dq->front];
    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else
    {
        if (dq->front == max - 1)
            dq->front = 0;
        else
            dq->front++;
    }
    return a;
}
int del_rear(struct deque *dq)
{
    int a;
    if (dq->front == -1)
        return -1;
    a = dq->items[dq->rear];
    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else
    {
        if (dq->rear == 0)
            dq->rear = max - 1;
        else
            dq->rear--;
    }
    return a;
}

void display(struct deque *cqu)
{
    // int i, j;
    // i = dq->front;
    // j = dq->rear;
    // if (dq->front == -1)
    //     printf("Circular Queue is Empty");
    // else
    // {
    //     if (i <= j)
    //         while (i <= j)
    //         {
    //             printf("%d\t", dq->items[i]);
    //             i++;
    //         }
    //     else
    //     {
    //         while (i <= max - 1)
    //         {
    //             printf("%d\t", dq->items[i]);
    //             i++;
    //         }
    //         i = 0;
    //         while (i <= j)
    //         {
    //             printf("%d\t", dq->items[i]);
    //             i++;
    //         }
    //     }
    // }

    int i;
    if(cqu->front == -1)
    {
        printf("Circle queue is empty");
    }
    else
    {
        if(cqu->front <= cqu->rear)
        {
            for(i=cqu->front;i<=cqu->rear;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
        }
        else
        {
            for(i=cqu->front;i<=max-1;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
            for(i=0;i<=cqu->rear;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
        }
    }
}
int empty(struct deque *dq)
{
    if (dq->front == -1)
        return 1;
    else
        return 0;
}
int peek_front(struct deque *dq)
{
    if (dq->front == -1)
        return -1;
    else
        return dq->items[dq->front];
}
int peek_rear(struct deque *dq)
{
    if (dq->front == -1)
        return -1;
    else
        return dq->items[dq->rear];
}