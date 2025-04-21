#include<stdio.h>
#include<stdlib.h>
struct node
{   
    int data;
    struct node *left,*right;
};
struct node * create(struct node *);
void insert(struct node *,struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node* getNode();
struct node * getNode()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=0;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node * create(struct node *root)
{
  struct node * newnode;
  newnode=getNode();
  printf("Entet the data in node if we want to cancle creation of tree press -9\n");
  scanf("%d",&newnode->data);
  while(newnode->data!=-9)
  {
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        insert(root,newnode);
        newnode=getNode();
        printf("Entet the data in node if we want to cancle creation of tree press -9\n");
        scanf("%d",&newnode->data);
    }
  }
  return root;

}
void insert(struct node *root,struct node *newnode)
{
    if(newnode->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left = newnode;
        }
        else
        {
            insert(root->left,newnode);
        }
    }
    if(newnode->data>root->data)
    {
        if(root->right==NULL)
        {
            root->right = newnode;
        }
        else
        {
            insert(root->right,newnode);
        }
    }
}
void preorder(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}


void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d \t",temp->data);
        inorder(temp->right);
    }
}
void postorder(struct node *temp)
{
    while(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->data);
    }
    
}
int main()
{
    struct node *root;
    int ch;
    root=NULL;
    root=create(root);
    while(1)
    {
        printf("\n---Menu----\n");
        printf("1.inorder\n2.preorder\n3.postorder\n4.Exit\nEnnter Your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: inorder(root);
                    break;
            case 2: preorder(root);
                    break;
            case 3: postorder(root);
                    break;
            case 4: exit(0);
                    break;
            default : printf("Invalid Choice");
                    break;
        }
    }
}