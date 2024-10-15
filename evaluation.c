#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define max 50

int flag = 0;

struct node
{
   int top, stack[max];
}s;

int pop()
{
    if (s.top == -1) 
    {
        printf("Stack Underflow\n");
    }
    else 
    {
        int del = s.stack[s.top];
        s.top--;
        return del;
    }
}

void push (int data)
{
    if (s.top == max)
    {
        printf("Stack Overflow\n");
        return;
    }
    if (flag == 1)
    {
        int num = pop();
        s.stack[++s.top] = num*10 + data;
    }
    else if (flag == 0)
    {
        s.top++;
        s.stack[s.top] = data;
        flag = 1;
    }
}

isOperator (char ch)
{
    if (ch == '+' || ch =='-' || ch == '*' ||ch == '/' || ch == '^')
    {
        return 1;
    }
    return 0;
}


int evaluate (char expr[])
{
    int result, val1, val2,l,i;
    l = strlen(expr);
    for (i=0;i<l;i++)
    {
        if (isdigit(expr[i]))
        {
            int x = expr[i] - '0';
            push(x);
        }
        if (expr[i] == ' ')
        {
            flag = 0;
        }
        if (isOperator(expr[i]))
        {
            flag = 0;
            val1 = pop();
            val2 = pop();
            switch(expr[i])
            {
                case '+' : result = val1 + val2;
                break;
                case '-' : result = val2 - val1;
                break;
                case '*' : result = val1*val2;
                break;
                case '/' : result = val2 / val1;
                break;
                case '^' : result = pow(val2,val1);
                break;
            } 
            push(result);
        }
    }
    result = pop();
    return result;
}
