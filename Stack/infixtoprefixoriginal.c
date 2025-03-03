/*Infix to prefix Program*/
#define MAX 50
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct stack
{
    int top;
    char items[MAX];
};
struct stack s;
char postfix[MAX], prefix[MAX];
int isp(char);
int icp(char);
void push(struct stack *, char);
char pop(struct stack *);
int empty(struct stack *);
void intopost(char[]);
int isoper(char);
char peek(struct stack *);
void main()
{
    char c, infix[MAX], infix1[MAX];
    int i;
    s.top = -1;
    printf("enter the infix expression");
    scanf("%s", infix);
    for (i = 0; (c = infix[i]) != '\0'; i++)
    {
        if (c == ')')
            push(&s, '(');
        else if (c == '(')
            push(&s, ')');
        else
            push(&s, c);
    }
    i = 0;
    while (!empty(&s))
    {
        c = pop(&s);
        infix1[i] = c;
        i++;
    }
    infix1[i] = '\0';
    printf("reverse expression is:%s", infix1);
    intopost(infix1);
}
void intopost(char expr[])
{
    int i, j = 0;
    char symb, topsymb;
    for (i = 0; (symb = expr[i]) != '\0'; i++)
        if (isoper(symb))
            postfix[j++] = symb;
        else if (symb == '(')
            push(&s, symb);
        else if (symb == ')')
        {
            topsymb = pop(&s);
            while ((!empty(&s)) && (topsymb != '('))
            {
                postfix[j++] = topsymb;
                topsymb = pop(&s);
            }
        }
        else
        {
            while (!empty(&s) && icp(symb) < isp(peek(&s)))
            {
                topsymb = pop(&s);
                postfix[j++] = topsymb;
            }
            push(&s, symb);
        }
    while (!empty(&s))
    {
        topsymb = pop(&s);
        postfix[j++] = topsymb;
    }
    postfix[j] = '\0';
    printf("\npostfix expression is:%s", postfix);
    for (i = 0; (symb = postfix[i]) != '\0'; i++)
        push(&s, symb);
    i = 0;
    while (!empty(&s))
    {
        topsymb = pop(&s);
        prefix[i] = topsymb;
        i++;
    }
    prefix[i] = '\0';
    printf("\nprefix expression is: %s", prefix);
}
int isoper(char symb)
{
    if ((symb >= '0' && symb <= '9') || (symb >= 'a' && symb <= 'z') || (symb > 'A' && symb <= 'Z'))
        return 1;
    else
        return 0;
}
void push(struct stack *st, char a)
{
    if (st->top == MAX - 1)
    {
        printf("\nstack is overflow");
    }
    else
    {
        st->top++;
        st->items[st->top] = a;
    }
}
char pop(struct stack *st)
{
    int a;
    if (empty(st))
        return -1;
    else
    {
        a = st->items[st->top];
        st->top--;
        return a;
    }
}
int empty(struct stack *st)
{
    if (st->top == -1)
        return 1;
    else
        return 0;
}
int isp(char c)
{
    switch (c)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '$':
        return 3;
    }
}
char peek(struct stack *st)
{
    if (empty(&s))
        return -1;
    else
        return st->items[st->top];
}
int icp(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '$':
        return 3;
    }
}