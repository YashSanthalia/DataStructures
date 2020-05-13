#include<stdio.h>
#define MAX 10

int array[MAX];
int front = -1;
int rear = -1;

void enqueue(int x);
void dequeue();
int isEmpty();
int isFull();
int getfront();
void print();

int main()
{
    enqueue(1); print();
    enqueue(2); print();
    enqueue(3); print();
    dequeue();  print();
    int frontElement = getfront();
    printf("FRONT ELEMENT = %d\n", frontElement);
    enqueue(4); print();
    dequeue();  print();
}

void enqueue(int x)
{
    if( isFull() )
    {
        printf("ALREADY FULL");
        return;
    }
    if( isEmpty() )
    {
        front = 0;
        rear = 0;
    }
    else
        rear = ( rear + 1 ) % MAX;
    array[rear] = x;
}

void dequeue()
{
    if( isEmpty() )
    {
        printf("No Element to dequeue");
        return;
    }
    if( front == rear )
    {
        front = -1;
        rear = -1;
        return;
    }
    front = ( front + 1 ) % MAX;
}

int isEmpty()
{
    if(rear == -1 && front == -1)
        return 1;
    return 0;
}

int isFull()
{
    if( (rear + 1) % MAX == front )
        return 1;
    return 0;
}

int getfront()
{
    if( front == -1 )
    {
        printf("empty queue");
        return 0;
    }
    return array[front];
}

void print()
{
    if( !isEmpty() )
    {
        printf("QUEUE : ");
        int i  = front;
        for( i ; i <= rear ; i++ )
            printf("%d\t", array[i] );
        printf("\n");
    }
}
