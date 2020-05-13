#include<stdio.h>
#include<string.h>
#define MAX 10
#define MAX_SIZE 100

char* parseString( char string[] );
int chIsOperatorOrBracket(char ch);

int parsedStringWithoutDelimiter[MAX_SIZE];
int top1 = -1;

char parsedString[MAX_SIZE];
int top2 = -1;

int* splitString(char string[], char delimeter)
{
    char a[MAX];
    a[0] = '\0';
    int length = strlen(string);
    for( int i = 0 ; i < length ; i++ )
    {
        char ch = string[i];
        if(string[i] == '+')
        {
            int p = string[i];
            push1(p);
        }
        else if(string[i] == '-')
        {
            int p = string[i];
            push1(p);
        }
        else if(string[i] == '*')
        {
            int p = string[i];
            push1(p);
        }
        else if(string[i] == '/')
        {
            int p = string[i];
            push1(p);
        }
        else if(string[i] != delimeter)
        {
            strncat(a, &ch, 1);
        }
        else
        {
            if( a[0] != '\0')
            {
                push1(atoi(a));
                a[0] = '\0';
            }
        }
    }
        if(a[0] != '\0')
            push1(atoi(a));
    parsedStringWithoutDelimiter[++top1] = -111;
    return parsedStringWithoutDelimiter;
}

//void push1(int a)
//{
 //   parsedStringWithoutDelimiter[++top1] = a;
//}

//int main()
//{
 //   char string[] = "67+68";
   // char *p = parseString(string);
    //for( int  i = 0 ; i <= top2 ; i++ )
    //printf("%c\t", p[i]);
//}

char* parseString( char string[] )
{
    char a[MAX];
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
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == ')' || ch == '(')
        return 1;
    return 0;
}
