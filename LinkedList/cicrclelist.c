#include<stdio.h>
#include<stdlib.h>
struct node* create();
void display (struct node*);
struct node * getNode();
struct node * insert(struct node *);
struct node * delete(struct node *);
struct node * revList(struct node *);
int count(struct node*);
struct node
{
        int data;
        struct node *next;
};

int  main()
{
    int ch,c;
    struct node *head;
    head=NULL;
    while(1)
    {
       printf("\n1.create\n2.display\n3.insert\n4.delete\n5.reverse\n6.count\n7.exit1");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1: head=create();
                break;
        case 2: if(head==NULL)
                {
                        printf("\nList is empty\n");      
                }
                else
                {
                        display(head);
                }
                break;
        case 3: head=insert(head);
                break;
        case 4: head=delete(head);
                break;
        case 5: head=revList(head);
                display(head);
                break;
        case 6: c=count(head);
                printf("Count of List is %d",c);
                break;
        case 7: exit(0);
                break;
        default :
                printf("Eneter Valid choice");
                break;
       }
    }
}
struct node *create()
{
  struct node *head,*first,*newnode;
  first =getNode();
  head=first;
  newnode = getNode();
  printf("Enter the value");
  scanf("%d",&newnode->data);
  while(newnode->data!=-9)
  { 
        first->next=newnode;
        first=newnode;
         newnode =getNode();
        printf("Enter the value");
        scanf("%d",&newnode->data);
        newnode->next=head->next;
  }
  return head->next;      
}
void display(struct node *head)

{
        struct node *temp;
        temp=head;
        if(head==NULL)
        {
                printf("List is empty");
        }
        //printf("Count of List is %d",count(head));
        while(temp->next!=head)
        {
                printf("%d->",temp->data);
                temp=temp->next;
        }
        printf("%d->",temp->data);

}
struct node *getNode()
{
        struct node *np;
        np=(struct node*)malloc(sizeof(struct node));
        np->data=0;
        np->next=NULL;
        return np;
}
struct node * insert(struct node *head)
{
        struct node *newnode,*temp;
        int ch,pos,i;
        temp=head;
        newnode=getNode();
        printf("Enter the value");
        scanf("%d",&newnode->data);
        printf("\n1.Insert at Beg\n2.Insert at end\n3.Insert at pos");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:
                        while(temp->next!=head)
                        {
                            temp=temp->next;
                        }
                        newnode->next=head;
                        temp->next=newnode;
                        head=newnode;
                        return head;
                        break;
                case 2: 
                        while(temp->next!=head)
                        {
                                temp=temp->next;
                        }
                        newnode->next=head;
                        temp->next=newnode;
                        return head;
                        break;
                case 3:
                        printf("Enter poss");
                        scanf("%d",&pos);
                        if(pos==1)
                        {
                            while(temp->next!=head)
                            {
                                temp=temp->next;
                            }
                            newnode->next=head;
                            temp->next=newnode;
                            head=newnode;
                            return head;
                            break;
                            
                        }
                        else
                        {
                                for(i=1;i<pos-1;i++)
                                {
                                        temp=temp->next;
                                }
                                newnode->next=temp->next;
                                temp->next=newnode;
                                return head;
                                break;
                        }
                      
                default:
                        printf("Enter valid choice");
                        break;
        }


}
struct node * delete(struct node *head)
{
        struct node * temp,*temp2;
        int ch,pos,i;
        temp=head;
        if(temp==NULL)
        {
            printf("List is empty");
        }
        else
        {   
            printf("\n1.Delete at Beg\n2.Delete at end\n3.Delete at pos");
            scanf("%d",&ch);
            switch(ch)
            {
                    case 1 :
                                if(head->next==head)
                                {
                                        head=NULL;
                                        return head;
                                }
                                else
                                {
                                        while(temp->next!=head)
                                        {
                                                temp=temp->next;
                                        }
                                        // This code will not remove the head 
                                        // but the first node will go to last node as it is circle
                                        
                                        // temp=head->next;
                                        // head=head->next;
                                        // return head;
                                        temp2=head->next;
                                        temp->next=temp2;
                                        //This line is optional as it remove first link
                                        head->next=NULL;
                                        return temp2;
                                }
                    case 2 : 
                        if(head->next==head)
                        {
                                head=NULL;
                                return head;
                        }
                        else
                        {
                                while(temp->next->next!=head)
                                {
                                        temp=temp->next;
                                }
                                temp->next=head;
                                return head;
                                break;
                        }

                    case 3 :

                            printf("Enter poss");
                            scanf("%d",&pos);

                                if(pos == 1)
                                {
                                        if(head->next==head)
                                        {
                                                head=NULL;
                                                return head;
                                        }
                                        else
                                        {
                                                while(temp->next!=head)
                                                {
                                                        temp=temp->next;
                                                }
                                                temp2=head->next;
                                                temp->next=temp2;
                                                head->next=NULL;
                                                return temp2;
                                        }   
                                }
                                else
                                {
                                        for(i=1;i<pos-1;i++)
                                        {
                                                temp=temp->next;
                                        }
                                        temp->next=temp->next->next;
                                        return head;
            
                                        break;
                                }
                    default : printf("Invalid choice");
                            break;
            }
        }

}
struct node * revList(struct node *head)
{
        struct node *temp,*rhead,*newnode;
        temp=head;
        rhead=getNode();
        rhead->data=temp->data;
        newnode=getNode();
        while (temp->next!=head)
        {
                temp=temp->next;
                newnode->data=temp->data;
                newnode->next= rhead;
                rhead=newnode;
                newnode=getNode();
        }
        return rhead;
}
int count(struct node *head)
{
        int count=0;
        struct node *temp;
        temp=head;
        printf("test-1");
        while(temp!=head);
        {
                printf("test-2");
                count=count+1;
                temp=temp->next;
        }
        return count;
}