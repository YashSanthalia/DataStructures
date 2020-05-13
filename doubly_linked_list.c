#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head;

void insertAtHead(int data);
void insertAtTail(int data);
void print();
void printReverse();
void delete(int n);

int main()
{
    insertAtHead(1);
    insertAtHead(3);
    insertAtTail(5);
    insertAtTail(6);
    print();
    printReverse();
    delete(4);
    print();
    printReverse();
}

struct Node* getNewNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

void insertAtHead( int data )
{
    struct Node* newNode = getNewNode(data);
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(int data)
{
    struct Node* newNode = getNewNode(data);
    if(head == NULL )
    {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while( temp -> next != NULL )
        temp = temp -> next;
    temp -> next = newNode;
    newNode -> prev = temp;
}

void print()
{
    struct Node* temp = head;
    printf("List is : ");
    while(temp != NULL )
    {
        printf("%d\t", temp -> data );
        temp = temp -> next;
    }
    printf("\n");
}

void printReverse()
{
    struct Node* temp = head;
    if(temp == NULL)
        return;
    printf("Reverse List is : ");
    while(temp -> next != NULL)
        temp = temp -> next;
    while( temp != NULL )
    {
        printf("%d\t", temp -> data);
        temp = temp -> prev;
    }
    printf("\n");
}

void delete(int n)
{
    if(n == 1)
    {
        head = head -> next;
        free(head -> prev);
        head -> prev = NULL;
        return;
    }
    struct Node* temp = head;
    for( int i = 0 ; i < n - 2 ; i++ )
        temp = temp -> next;
    if( temp -> next -> next != NULL )
    {
        struct Node* temp1 = temp -> next -> next -> prev;
        temp -> next -> next -> prev = temp;
        temp -> next = temp -> next -> next;
        free(temp1);
    }
    else
    {
        free(temp -> next);
        temp -> next = NULL;
    }
}
