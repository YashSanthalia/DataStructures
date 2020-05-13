#include<stdio.h>
#define MAX_SIZE 100

enum boolean
{
    true, false
};

int a[MAX_SIZE];
int top = -1;

enum boolean isEmpty();

int main()
{
    push(1); print();
    push(2); print();
    push(3); print();
    pop(); print();
    int topelement = getTop();
    printf("Top element = %d\n", topelement );
    pop(); print();
    pop(); print();
    enum boolean x = isEmpty();
    if(x == 1)
        printf("Stack is not empty");
    else
        printf("Stack is empty");
}

void push(int x)
{
    if( top == MAX_SIZE - 1 )
    {
        printf("ERROR : Stack Overflow");
        return;
    }
    a[++top] = x;
}

void pop()
{
    if( top == -1 )
    {
        printf("ERROR : No element to pop");
        return;
    }
    top--;
}

int getTop()
{
    if( top == -1 )
    {
        printf("Error : There is no element in stack");
        return 0;
    }
    return a[top];
}

enum boolean isEmpty()
{
    if( top == -1 )
        return true;
    return false;
}

void print()
{
    if(top == -1)
        {printf("Error : Empty Stack");
        return;}
    printf("STACK : ");
    for( int i = 0 ; i <= top ; i++ )
        printf("%d\t", a[i]);
    printf("\n");
}
