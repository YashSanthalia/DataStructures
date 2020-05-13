#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front;
struct Node* rear;

void enqueue(int data);
void dequeue();
void print();
int isEmpty();
struct Node* createNode();

int main()
{
    enqueue(1); print();
    enqueue(2); print();
    enqueue(3); print();
    enqueue(4); print();
    dequeue(); print();
    dequeue(); print();
}

void enqueue(int data)
{
    struct Node* newNode = createNode();
    newNode -> data = data;
    newNode -> next = NULL;
    if(isEmpty())
    {
        rear = newNode;
        front = newNode;
        return;
    }
    rear -> next = newNode;
    rear = newNode;
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is Empty");
        return;
    }
    if( front == rear )
    {
        front = NULL;
        rear = NULL;
        return;
    }
    struct Node* temp = front;
    front = front -> next;
    free(temp);
}

int isEmpty()
{
    if( front == NULL )
        return 1;
    return 0;
}

void print()
{
    struct Node* temp = front;
    printf("QUEUE : ");
    while( temp != NULL )
    {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

struct Node* createNode()
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    return newNode;
}

