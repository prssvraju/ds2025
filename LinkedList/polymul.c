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
struct node * polyAdd(struct node*,struct node*);
struct node *polyMul1(struct node*,struct node*);
struct node *polyMul2(struct node*,struct node*);
int main()
{
    int n,i,c,e;
    struct node *phead1,*phead2,*phead3;
    phead1=NULL;
    phead2=NULL;
    phead3=NULL;


    printf("Enter no of Terms in 1st experssion");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the %d conf and exp",i+1);
        scanf("%d%d",&c,&e);
        phead1=insertTerm(phead1,c,e);
    }
    printf("Enter no of Terms in 2nd experssion");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the %d conf and exp",i+1);
        scanf("%d%d",&c,&e);
        phead2=insertTerm(phead2,c,e);
    }
    printf("\nPoly Nomial Expression 1\n");
    display(phead1);
    printf("\nPoly Nomial Expression 2\n");
    display(phead2);
    phead3=polyMul2(phead1,phead2);
    printf("\nPoly Mul is  2\n");
    display(phead3);
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
struct node *polyMul2(struct node *phead1,struct node* phead2)
{
    struct node *ptr1,*ptr2;
    ptr1=phead1;
    int rc,re;
    struct node *sop =NULL,*pos=NULL;
    while (ptr1!=NULL)
    {
        ptr2=phead2;
        while (ptr2!=NULL)
        {
            rc=ptr1->cof*ptr2->cof;
            re=ptr1->exp+ptr2->exp;
            pos=insertTerm(pos,rc,re);
            ptr2=ptr2->next;
        }
        sop=polyAdd(sop,pos);
        pos=NULL;
        ptr1=ptr1->next;
    }
    return sop;
}

struct node *polyMul1(struct node *phead1,struct node* phead2)
{
    struct node *ptr1,*ptr2,*phead3;
    ptr1=phead1;
    int rc,re;
    phead3=NULL;
    while (ptr1!=NULL)
    {
        ptr2=phead2;
        while (ptr2!=NULL)
        {
            rc=ptr1->cof*ptr2->cof;
            re=ptr1->exp+ptr2->exp;
            phead3=insertTerm(phead3,rc,re);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return phead3;
}
struct node * polyAdd(struct node* phead1,struct node* phead2)
{
    struct node *ptr1,*ptr2,*phead3;
    ptr1=phead1;
    ptr2=phead2;
    phead3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {   
        if(ptr1->exp==ptr2->exp)
        {
            phead3=insertTerm(phead3,ptr1->cof+ptr2->cof,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->exp>ptr2->exp)
        {
            phead3=insertTerm(phead3,ptr1->cof,ptr1->exp);
            ptr1=ptr1->next;
        }
        else if(ptr1->exp<ptr2->exp)
        {
            phead3=insertTerm(phead3,ptr2->cof,ptr2->exp);
            ptr2=ptr2->next;
        }   
    }
    while (ptr1!=NULL)
    {
        phead3=insertTerm(phead3,ptr1->cof,ptr1->exp);
        ptr1=ptr1->next;    
    }
    while (ptr2!=NULL)
    {
        phead3=insertTerm(phead3,ptr2->cof,ptr2->exp);
        ptr2=ptr2->next;    
    } 
    
    return phead3;
}