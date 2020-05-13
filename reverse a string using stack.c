#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20

char a[] = "yashashu";
char b[MAX];

int top = -1;

int main()
{
   // push(strlen(a));
    //getandpop(strlen(a));
    reverse();
    print();
}

void push( int length )
{
    for( int i = 0 ; i < length ; i++ )
    {
        b[++top] = a[i];
    }
}

void getandpop( int length )
{
    for( int i = 0 ; i < length ; i++ )
    {
        a[i] = b[top];
        top--;
    }
}

void print()
{
    printf("%s", a);
}

void reverse()
{
    char temp;
    int i = 0;
    int j = strlen(a) - 1  ;
    while( i < j )
    {
        temp =  a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}
