#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#include"myFunctions.c"


void push( int data );
int pop();
struct Node* createNode(void);
void inputexpression( char exp[] );
int evaluationOfPostfix( char exp[], char delimeter );

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

int main()
{
    head = NULL;
    char exp[MAX];
    char delimeter;
    inputDelimeter(&delimeter);
    inputexpression(exp);
    int result = evaluationOfPostfix(exp, delimeter);
    printf("Result = %d", result);
}

void inputDelimeter(char *delimeter)
{
    printf("Enter the delimeter : ");
    scanf("%c", delimeter);
    fflush(stdin);
}

void inputexpression( char exp[] )
{
    printf("Enter an expression : ");
    gets(exp);
    fflush(stdin);
}

int evaluationOfPostfix( char exp[], char delimeter )
{
    int * token = splitString(exp, delimeter);
    int op1, op2, result;
    int i = 0;
    while( token[i] != -111 )
    {
        if( token[i] == 43 )
        {
            op2 = pop();
            op1 = pop();
            result = op1 + op2;
            push(result);
        }
        else if( token[i] == 45 )
        {
            op2 = pop();
            op1 = pop();
            result = op1 - op2;
            push(result);
        }
        else if( token[i] == 42 )
        {
            op2 = pop();
            op1 = pop();
            result = op1 * op2;
            push(result);
        }
        else if( token[i] == 47 )
        {
            op2 = pop();
            op1 = pop();
            result = op1 / op2;
            push(result);
        }
        else
        {
            push(token[i]);
        }
        i++;
    }
    int finalResult = pop();
    return finalResult;
}

void push( int data )
{
    struct Node* newNode = createNode();
    newNode -> data = data;
    newNode -> next = NULL;
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    newNode -> next = head;
    head = newNode;
}

int pop()
{
    if( head == NULL )
    {
        printf("Invalid Expression");
        return;
    }
    int operand = head -> data;
    struct Node* temp = head;
    head = head -> next;
    free(temp);
    return operand;
}

struct Node* createNode()
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    return newNode;
}
