#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX1 10


struct Node{
    char operator;
    struct Node* next;
};

struct Node1{
    int data;
    struct Node* next;
};

struct Node* head;
struct Node1* head1;

char postfix[MAX];
int top = -1;

char parsedString[MAX];
int top2 = -1;


struct Node1* createNode1();
int result();
void push1( int data );
int pop1();
int singleTokenIsOperator( char singleToken );
int evaluation(char exp[]);
void inputExpression(char exp[]);
int hasLowerPrecedence(char singleToken);
int singleTokenIsClosingBracket(char singleToken);
int topOfStackIsNotOpeningBracket(char singleToken);
int singleTokenIsOPeningBracketOrOperator(char singleToken);
struct Node* createNode();
void pushIntoPostfix( char singleToken);
char* parseString( char string[] );
int chIsOperatorOrBracket(char ch);


int main()
{
    char exp[MAX];
    inputExpression(exp);
    int result = evaluation(exp);
    printf("RESULT = %d", result);
}

void inputExpression(char exp[])
{
    printf("Enter an expression(numbers should not exceed 127) : ");
    gets(exp);
    fflush(stdin);
}

int evaluation(char exp[])
{
    char* token = parseString(exp);
    printf("Parsed String");
    for(int i = 0 ; token[i] != '$' ; i++ )
        printf("%c\t", token[i]);
    for( int i = 0 ; token[i] != '$' ; i++ )
    {
        char singleToken = token[i];
        while( singleTokenIsOperator(singleToken) && hasLowerPrecedence(singleToken))    //handling with + - * /
            pop();
        while( singleTokenIsClosingBracket(singleToken) && topOfStackIsNotOpeningBracket(singleToken) )        // handling ), ], }
            pop();
        if( singleTokenIsOPeningBracketOrOperator(singleToken) )
               push(singleToken);
        else if( !singleTokenIsClosingBracket(singleToken) )
            pushIntoPostfix(singleToken);
    }
    while(head != NULL)
        pop();
    printf("POSTFIX : \n");
    for( int i = 0 ; i <= top ; i++ )
        printf("%d\t", postfix[i]);
    return result();
}

int singleTokenIsOperator( char singleToken )
{
    if(singleToken == '+' || singleToken == '-' || singleToken == '/' || singleToken == '*')
        return 1;
    return 0;
}

int hasLowerPrecedence(char singleToken)
{
    if(head == NULL )
        return 0;
    char top = head -> operator;
    if( top == '*' || top == '/')
            return 1;
    else if( (singleToken == '+' || singleToken == '-') && topOfStackIsNotOpeningBracket(singleToken) )
            return 1;
    return 0;
}

int singleTokenIsClosingBracket(char singleToken)
{
    if( singleToken == ')' || singleToken == '}' || singleToken == ']' )
        return 1;
    return 0;
}

int topOfStackIsNotOpeningBracket(char singleToken)
{
    if(head == NULL )
    {
        printf("INVALID INFIX");
        return 0;
    }
    char topOfStack = head -> operator;
    if( topOfStack == '(' || topOfStack == '{' || topOfStack == '[' )
        return 0;
    return 1;
}

int singleTokenIsOPeningBracketOrOperator(char singleToken)
{
    if( singleTokenIsOperator(singleToken) || singleToken == '(' || singleToken == '{' || singleToken == '[')
        return 1;
    return 0;
}

void push( char singleToken)
{
    struct Node* newNode = createNode();
    newNode -> operator = singleToken;
    newNode -> next = NULL;
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    newNode -> next = head;
    head = newNode;
}

void pop()
{
    if( head -> operator != '(' &&  head -> operator != '{' && head -> operator != '[')
        postfix[++top] = head -> operator;
    struct Node* temp = head;
    head = head -> next;
    free(temp);
}

struct Node* createNode()
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    return newNode;
}

void pushIntoPostfix( char singleToken)
{
    postfix[++top] = singleToken;
}

char* parseString( char string[] )
{
    char a[MAX1];
    a[0] = '\0';
    int length = strlen(string);
    for( int i = 0 ; i < length ; i++ )
    {
        char ch = string[i];
        if( chIsOperatorOrBracket(ch) )
        {
            if(a[0] != '\0')
                push2(atoi(a));
            a[0] = '\0';
            push2(ch);
        }
        else
            strncat(a, &ch, 1);
    }
    if( a[0] != '\0')
        push2(atoi(a));
    parsedString[++top2] = '$';
    return parsedString;
}


void push2(char ch)
{
    parsedString[++top2] = ch;
}

int chIsOperatorOrBracket(char ch)
{
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' ||
                ch == ')' || ch == '(' || ch == '[' ||
                             ch == ']'  || ch == '{' || ch == '}') {
        return 1;
    }
    return 0;
}

int result()
{

    int op1, op2, result;
    for( int i = 0 ; i <= top ; i++ )
    {
        int token = postfix[i];
        if( token == 43 )
        {
            op2 = pop1();
            op1 = pop1();
            result = op1 + op2;
            push1(result);
        }
        else if( token == 45 )
        {
            op2 = pop1();
            op1 = pop1();
            result = op1 - op2;
            push1(result);
        }
        else if( token == 42 )
        {
            op2 = pop1();
            op1 = pop1();
            result = op1 * op2;
            push1(result);
        }
        else if( token == 47 )
        {
            op2 = pop1();
            op1 = pop1();
            result = op1 / op2;
            push1(result);
        }
        else
        {
            push1(token);
        }
    }
    int finalResult = pop1();
    return finalResult;
}

void push1( int data )
{
    struct Node1* newNode = createNode1();
    newNode -> data = data;
    newNode -> next = NULL;
    if( head1 == NULL )
    {
        head1 = newNode;
        return;
    }
    newNode -> next = head1;
    head1 = newNode;
}

int pop1()
{
    if( head1 == NULL )
    {
        printf("Invalid Expression");
        return;
    }
    int operand = head1 -> data;
    struct Node1* temp = head;
    head1 = head1 -> next;
    free(temp);
    return operand;
}

struct Node1* createNode1()
{
    struct Node1* newNode = (struct Node1*)malloc(sizeof(struct Node1));
    return newNode;
}
