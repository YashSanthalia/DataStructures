#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int data, int n);
void Print();
void Reverse();

int main()
{
    head = NULL;
    Insert(1, 1);
    Insert(2, 2);
    Insert(3, 3);
    Insert(4, 4);
    Print();
    Reverse();
    Print();
}

void Insert(int data, int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if(n == 1 )
    {
        temp -> next = head;
        head = temp;
        return;
    }
    struct Node* temp1 = head;
    for( int i = 0 ; i < n - 2 ; i++ )
    {
        temp1 = temp1 -> next;
    }
    temp -> next = temp1 -> next;
    temp1 -> next = temp;
}

void Print()
{
    struct Node* temp = head;
    printf("List is : ");
    while( temp != NULL )
    {
        printf("%d\t", temp -> data );
        temp = temp -> next;
    }
    printf("\n");
}

void Reverse()
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while( current != NULL )
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
