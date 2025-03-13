#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp;
    int cof;
    struct node *next;
};
struct node *insertPolyNode(struct node*,int,int);
struct node *getTerm(int,int);
void display(struct node *);
struct node *polyadd(struct node*,struct node*);

int main()
{
    int c,e,n,i;
    struct node *polyhead1,*polyhead2,*polyhead3;
    polyhead1=NULL;
    printf("Enter the no of terms in 1st expression");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter cof and expo of %d term",i+1);
        scanf("%d%d",&c,&e);
        polyhead1=insertPolyNode(polyhead1,c,e);
    }

    printf("Enter the no of terms in 2nd expression");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter cof and expo of %d term",i+1);
        scanf("%d%d",&c,&e);
        polyhead2=insertPolyNode(polyhead2,c,e);
    }

    printf("Polynomila 1\n");
    display(polyhead1);
    printf("\nPolynomila 2\n");
    display(polyhead2);

    //polyhead3=polyadd(polyhead1,polyhead2);

    //printf("\nAdditon is \n");
    //display(polyhead3);
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
struct node * insertPolyNode(struct node* phead,int cof,int exp)
{
    struct node *temp,*newnode;
    temp=phead;
    newnode = getNode(cof,exp);
    // newnode=(struct node *)malloc(sizeof(struct node));
    // newnode->cof=cof;
    // newnode->exp=exp;
    // newnode->next = NULL;
    //if head node is null or we are trying to add term with highest exponent it need to add at staring of linke list so we compare exp>temp->exp
    if(temp==NULL||exp>temp->exp) 
    {
        newnode->next = phead;
        phead = newnode;
        return phead;
    }
    else{
        //for checking next node is null we use temp->next!=NULL and
        //find exat location of term based on exp we will check temp->next->exp>exp
         while(temp->next!=NULL && temp->next->exp > exp)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return phead;
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
struct node *polyadd(struct node*ph1,struct node*ph2)
{
    struct node *ph1temp,*ph2temp,*ph3;
    ph1temp=ph1;
    ph2temp=ph2;
    while(ph1temp!=NULL && ph2temp!=NULL)
    {
        if(ph1temp->exp == ph1temp->exp)
        {
            ph3=insertPolyNode(ph3,ph1temp->cof+ph2temp->cof,ph1temp->exp);
            ph1temp=ph1temp->next;
            ph2temp=ph2temp->next;
        }
        else if(ph1temp->exp > ph2temp->exp)
        {
            ph3=insertPolyNode(ph3,ph1temp->cof,ph1temp->exp);
            ph1temp=ph1temp->next;
        }
        else if(ph1temp->exp < ph2temp->exp)
        {
            ph3=insertPolyNode(ph3,ph2temp->cof,ph2temp->exp);
            ph2temp=ph2temp->next;
        }
    }
    while (ph1temp!=NULL)
    {
        ph3=insertPolyNode(ph3,ph1temp->cof,ph1temp->exp);
        ph1temp=ph1temp->next;
    }
    while (ph2temp!=NULL)
    {
        ph3=insertPolyNode(ph3,ph2temp->cof,ph2temp->exp);
        ph2temp=ph2temp->next;    
    }
    return ph3;
}