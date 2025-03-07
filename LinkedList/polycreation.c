#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp;
    int cof;
    struct node *next;
};
struct node *insertTerm(struct node*,int,int);
struct node *getTerm(int,int);
void display(struct node *);

int main()
{
    int c,e,n,i;
    struct node *polyhead;
    polyhead=NULL;
    printf("Enter the no of terms in expression");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter cof and expo of %d term",i+1);
        scanf("%d%d",&c,&e);
        polyhead=insertTerm(polyhead,c,e);
    }
    display(polyhead);
    return 0; 
}
void display(struct node * phead)
{
    struct node *temp;
    temp=phead;
    // while(temp->next!=NULL)
    // {
    //     printf("%d*X^%d",temp->cof,temp->exp);
    //     if(temp!=NULL)
    //     {
    //         printf("+");
    //     }
    //     else
    //     {
    //         printf("\n");
    //     }
    //     temp=temp->next;
    // }
    // printf("%d*X^%d",temp->cof,temp->exp);
    while(temp!=NULL)
    {
        printf("%d*X^%d+",temp->cof,temp->exp);
        temp=temp->next;
    }

}
struct node * insertTerm(struct node *phead,int c,int e)
{
    struct node *temp;
    temp=phead;
    struct node *newnode=getTerm(c,e);
    if(phead==NULL||e>temp->exp)
    {
        newnode->next=phead;
        phead=newnode;
        return phead;
    }
    else
    {
        while (temp->next!=NULL && temp->next->exp>e)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return phead;
    }

}
struct node *getTerm(int c,int e)
{
    struct node *pnp;
    pnp=(struct node *)malloc(sizeof(struct node));
    pnp->cof=c;
    pnp->exp=e;
    pnp->next=NULL;
    return pnp;
}