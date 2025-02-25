
/*Infix to postfix*/
#define MAX 50
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct stack
{
	int top;
	char items[MAX];
};
void push(struct stack *,char);
char pop(struct stack *);
char peek(struct stack *);
void infixtopost(char[]);
int isOperand(char);
int empty(struct stack *);
int icp(char);
struct stack st;
char postfix[MAX];
int main()
{
    char infix[MAX];
    st.top=-1;
    printf("Enter infix expressoin");
    scanf("%s",infix);
    printf("Infix Expressions is %s",infix);
    infixtopost(infix);
    return 0;
 }
 int empty(struct stack *st)
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
int isOperand(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isp(char c)
{
    switch(c)
    {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*': 
        case '/': return 2;
        case '^':
        case '$': return 3;
    }
}
int icp(char c)
{
    switch(c)
    {
        case '+':
        case '-': return 1;
        case '*': 
        case '/': return 2;
        case '^':
        case '$': return 3;
    }
}
void infixtopost(char infix[])
{
    int i,j=0;
    char sym,topsym;
    for(i=0;(sym=infix[i])!='\0';i++)
    {
        if(isOperand(sym))
        {
            postfix[j]=sym;
            j++;
        }
        else if(sym=='(')
        {
            push(&st,sym);
        }
        else if(sym==')')
        {
            topsym = pop(&st);
            while (topsym!='(' && !empty(&st))
            {
                postfix[j]=topsym;
                j++;
                topsym =pop(&st);
            }  
        }
        else
        {
            while(!empty(&st)&& icp<=isp(peek(&st)))
            {
                topsym=pop(&st);
                postfix[j]=topsym;
                j++;
            }
            push(&st,sym);
        }

    }
    while(!empty(&st))
    {
        topsym=pop(&st);
        postfix[j]=topsym;
        j++;
    }
    postfix[j]='\0';
    printf("\nAPostFix expression is %s",postfix);
}

void push(struct stack *st,char a)
{
	if(st->top==MAX-1)
	{
		printf("\nstack is overflow");

	}
	else
	{
		st->top++;
		st->items[st->top]=a;
	}

}

char pop(struct stack *st)
{
	char a;
	if(empty(st))
		return -1;
	else
	{
		a=st->items[st->top];
		st->top--;
		return a;
	}
}

char peek(struct stack *st)
{
	if(empty(&st))
		return -1;
	else
		return st->items[st->top];
}
