#include<stdio.h>
#include<stdlib.h>
#define MAX 40
struct stack
{
    int items[MAX];
    int top;
};
void push(struct stack*,int);
int pop(struct stack*);
void display(struct stack*);
int peek(struct stack*);
int isOperand(char);
void infixpost(char []);
int isEmpty(struct stack *);
struct stack st;
int icp(char); 
int isp(char); 
int main()
{
    char inf[10];
    st.top=-1;
    printf("Enter infix string");
    scanf("%s",inf);
    printf("infix string %s",inf);
    infixpost(inf);
    return 0;
}
int isOperand(char c)
{
    if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infixpost(char infix[10])
{
    int i,j=0;
    char post[10];
    char sym,topsym;
    for(i=0;(sym=infix[i])!='\0';i++)
    {
        if(isOperand(sym))
        {
            post[j]=sym;
            j++;
            printf("\nSymbol %c\tInside Operand %s",sym,post);
        }
        else if(sym=='(')
        {
            push(&st,sym);
        }
        else if(sym ==')')
        {
            topsym = pop(&st);
            while(topsym!='(' && !isEmpty(&st))
            {
                post[j]=topsym;
                j++;
                printf("\nSymbol %c\tInside ) %s",topsym,post);
                topsym=pop(&st);
            }
        }
        else
        {
            while(!isEmpty(&st)&& icp(sym)<=isp(peek(&st)))
            {
                topsym=pop(&st);
                post[j]=topsym;
                j++;
                printf("\nSymbol %c\tInside operator) %s",topsym,post);

            }
            push(&st,sym);
            printf("\nSymbol %c\tInside operator) %s",topsym,post);

        }
    }
    while(!isEmpty(&st))
    {
        topsym=pop(&st);
        post[j]=topsym;
        j++;
    }
    post[j]='\0';
    printf("\nPostfix String is %s",post);
}
int isp(char c)
{
    switch(c)
    {
        case '(' : return 0; 
        case '+' :
        case '-' :return 1; 
        case '/' :
        case '*' :return 2; 
        case '$' :
        case '^' :return 3; 
    }
}
int icp(char c)
{
    switch(c)
    {
        case '+' :
        case '-' :return 1; 
        case '/' :
        case '*' :return 2; 
        case '$' :
        case '^' :return 3; 
    }
}
int isEmpty(struct stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
void push(struct stack *stp,int ele)
{
    if(stp->top==MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        stp->top=stp->top+1;       
        stp->items[stp->top]=ele;
    }
}
int pop(struct stack *st)
{
    int ele;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        ele=st->items[st->top];
        st->top=st->top-1;
        return ele;
    }
}
int peek(struct stack *st)
{
    int ele;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        ele=st->items[st->top];
        return ele;
    }
}
void display(struct stack *st)
{
    int i;
    if(st->top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=st->top;i>=0;i--)
        {
            printf("|%d|\n",st->items[i]);
        }
    }
}