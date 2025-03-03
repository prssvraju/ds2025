#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50
struct stack
{
    int top;
    double items[MAX];
};
struct stack st;
void push(struct stack *,double);
double pop(struct stack *);
int empty(struct stack *);
double eval(char[]);
int isDigit(char);
double opert(char,double,double);
int main()
{
    char exp[MAX];
    double res;
    st.top=-1;
    printf("Enter expression");
    scanf("%s",exp);
    printf("\n Given Expression %s",exp);
    res = eval(exp);
    printf("\nReslut is %lf",res);
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

int isDigit(char sym)
{
    if(sym>='0'&&sym<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double opert(char sym,double opnd1,double opnd2)
{
    switch(sym)
    {
        case '+': return(opnd1+opnd2);
        case '-': return(opnd1-opnd2);
        case '*': return(opnd1*opnd2);
        case '/': return(opnd1/opnd2);
        case '$': return(pow(opnd1,opnd2));
        default : printf("Illegal operator");
                    exit(0);
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
double eval(char exp[MAX])
{
    int i,sym;
    double opnd1,opnd2,value;
    for(i=0;(sym=exp[i])!='\0';i++)
    {
        if(isDigit(sym))
        {
            push(&st,(double)sym-'0');
        }
        else{
            opnd2=pop(&st);
            opnd1=pop(&st);
            value=opert(sym,opnd1,opnd2);
            push(&st,value);
        }
    }
    return(pop(&st));

}