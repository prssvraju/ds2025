#include<stdio.h>
#include<stdlib.h>
struct node * getNode();
struct node * create();
void traversal(struct node *);
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * getNode()
{
    struct node *np = (struct node *)malloc(sizeof(struct node));
    np->data=0;
    np->next=NULL;
    np->prev=NULL;
    return np;
}
struct node * create()
{
    struct node *first,*newnode,*head;
    first=getNode();
    head=first;
    newnode=getNode();
    printf("Enter Data");
    scanf("%d",&newnode->data);
    while(newnode->data!=-9)
    {
        first->next=newnode;
        newnode->prev=first;
        first=newnode;
        
        newnode=getNode();
        printf("Enter Data");
        scanf("%d",&newnode->data);
    }
    return head->next;
}
void traversal(struct node *head)
{
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    } 
}

int main()
{
    int ch;
    struct node *head;
    while(1)
    {
        printf("\n1.create\n2.display\n3.Insert\n4.Delete\n5.Exit");
        printf("Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : head=create();
                     traversal(head);
                     break;
            case 2 : printf("Display");
                     break;
            case 3 : printf("Insert");
                     break;
            case 4 : printf("Delete");
                     break;
            case 5 : printf("Exit");
                     break;
            default : printf("Invalid choice");
                      break;
        }
    }
 

}