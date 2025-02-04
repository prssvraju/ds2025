#include<stdio.h>
struct node* create();
void traves(struct node*);
struct node
{
    int data;
    struct node * add; 
};
int main()
{
  int ch;
  struct node *head,*first,*newnode;
  while(1)
  {
    printf("\n1.create\n2.display\n3.Exit");
    printf("Enter your choice");
    scanf("%c",&ch);
    switch(ch)
    {
        case 1 :head=create();
                break;
        case 2 :traves(head);
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