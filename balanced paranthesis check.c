#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inputExpression(char[]);
int checking(char expression[], int length );

char array[50];
int top = -1;

int main()
{
    char expression[50];
    inputExpression(expression);
    int length = strlen(expression);
    int result = checking(expression, length);
    if(result == -1)
        printf("NOT BALANCED");
    else if(top == -1)
        printf("BALANCED");
}


void inputExpression( char expression[])
{
    printf("Enter an expression : ");
    scanf("%s", expression);
}

void push( char c)
{
    array[++top] = c;
}

int checking(char expression[], int length )
{
     for( int i = 0 ; i < length ; i++ )
    {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            push(expression[i]);
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if(top == -1)
                return -1;
            else if((array[top] =='(' && expression[i] == ')') || (array[top] == '{' && expression[i] == '}') || (array[top] == '[' && expression[i] == ']'))
                pop();
            else
                return -1;
        }
    }
}

void pop()
{
    top --;
}
