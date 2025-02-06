#include<stdio.h>
#include<stdlib.h>
struct node* create();
void traversal(struct node*);
struct node *getNode();
struct node
{
    int data;
    struct node * next; 
};
int main()
{
  int ch;
  struct node *head,*first,*newnode;
  while(1)
  {
    printf("\n1.create\n2.display\n3.Exit");
    printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :head=create();
                break;
        case 2 :traversal(head);
                break;
        case 3 :
                exit(0);
                break;
        default :
                printf("Enter valid choice");
                break;
    }
  }
}
struct node* getNode()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=0;
    newnode->next=NULL;
    return newnode;
}
struct node* create()
{
    struct node *head,*first,*newnode;
    first=getNode();
    head=first;

    newnode=getNode();
    printf("Enter the value ");
    scanf("%d",&newnode->data);

    while(newnode->data!=-99)
    {
      first->next=newnode;
      first=newnode;
      newnode=getNode();
      printf("Enter the value ");
      scanf("%d",&newnode->data);
    }
    return head->next;
}
void traversal(struct node *np)
{
    struct node *temp;
    temp=np;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    //printf("%d->",temp->data);
}

