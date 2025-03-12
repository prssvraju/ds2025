#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int cof;
    int exp;
    struct node *next;
};
struct node * insertTerm(struct node*,int,int);
struct node * getNode(int,int);
void display(struct node *);
int main()
{
    int n,i,c,e;
    struct node *phead;
    phead=NULL;

    printf("Enter no of Terms in experssion");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the %d conf and exp",i+1);
        scanf("%d%d",&c,&e);
        phead=insertTerm(phead,c,e);
    }
    display(phead);
    return 0;

}
void display(struct node * phead)
{
    struct node *temp;
    temp=phead;
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
    struct node *newnode;
    newnode=getNode(c,e);
    if(phead==NULL||e>temp->exp)
    {
        newnode->next=phead;
        phead = newnode;
        return phead;
    }
    else
    {
        while(temp->next!=NULL && temp->exp>e)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next= newnode;
        return phead;
    }
}
struct node* getNode(int c,int e)
{
    struct node *pnp;
    pnp=(struct node *)malloc(sizeof(struct node));
    pnp->cof=c;
    pnp->exp=e;
    pnp->next=NULL;
    return pnp;
}