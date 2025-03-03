#include<stdio.h>
#include<stdlib.h>
struct node* create();
void traversal(struct node*);
struct node *getNode();
struct node *insert(struct node*);
struct node *delete(struct node *);
struct node *reverse(struct node *);
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
    printf("\n1.create\n2.display\n3.Insert\n4.Delete\n5.Reverse\n6.exit");
    printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :head=create();
                break;
        case 2 :traversal(head);
                break;
        case 3 :head =insert(head);
                break;
        case 4 :head= delete(head);
                break;
        case 5 : head=reverse(head);
                 break;
        case 6 :exit(0);
                break;
        default :
                printf("Enter valid choice");
                break;
    }
  }
}
struct node * reverse(struct node * head)
{
    struct node *temp,*newnode,*rhead;
    temp=head;
    rhead=getNode();
    rhead->data=temp->data;
    while (temp->next!=NULL)
    {
        temp=temp->next;
        newnode=getNode();
        newnode->data=temp->data;
        newnode->next=rhead;
        rhead=newnode;
    }
    return rhead;
    
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
    printf("Enter the value");
    scanf("%d",&newnode->data);
    while(newnode->data!=-9)
    {
        first->next=newnode;
        first=newnode;
        newnode=getNode();
        printf("Enter the value");
        scanf("%d",&newnode->data); 
    }
    return head->next;
}
struct node* insert(struct node *head)
{
    struct node *temp,*newnode;
    int ch,pos,i;
    temp=head;

    newnode=getNode();
    printf("Enter the value");
    scanf("%d",&newnode->data); 

    printf("1.Insert in begning\n2.Insert at End\n3.Insert at position\n Enter your choice");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        newnode->next=head;
        head=newnode;
        break;
    case 2:
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        break;
    case 3:
        printf("Enter the position");
        scanf("%d",&pos);
        if(pos==1)
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
            for(i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
        break;
    }
    return head;
}
struct node *delete(struct node *head)
{
    struct node *temp;
    int ch,i;
    temp=head;
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("1.Delete in begning\n2.Delete at End\n3.Delete at position\n Enter your choice");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
                head=temp->next;
                free(temp);    
                return head;
                break;
        

        }
    }

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

