#define MAX 50
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct stack
{
	int top;
	double items[MAX];
};
void push(struct stack *,double);
double pop(struct stack *);
int empty(struct stack *);
int isOperand(char);
double operate(char,double,double);
struct stack st;
int main()
{
    char exp[MAX];
    st.top=-1;
    int i;
    char sym;
    double result;
    double opnd1,opnd2,value;

    printf("Enter  expressoin");
    scanf("%s",exp);
    printf("\n Expressions is %s",exp);
    for(i=0;(sym=exp[i])!='\0';i++)
    {
        if(isOperand(sym))
        {
            push(&st,(double)sym-'0');
        }
        else
        {
            opnd2=pop(&st);
            opnd1=pop(&st);
            value=operate(sym,opnd1,opnd2);
            push(&st,value);
        }
    }
    result=pop(&st);
    printf("Result is %lf",result);
}
double operate(char sym,double op1,double op2)
{
    switch(sym)
    {
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '$': return (pow(op1,op2));
        default : printf("Invalid");
                  exit(0);
    }
}
int isOperand(char c)
{
    if(c>='0'&&c<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
void push(struct stack *st,double a)
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

double pop(struct stack *st)
{
	double a;
	if(empty(st))
		return -1;
	else
	{
		a=st->items[st->top];
		st->top--;
		return a;
	}
}
