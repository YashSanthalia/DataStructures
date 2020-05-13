#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int data);
void PrintForward(struct Node*);
void PrintReversed(struct Node*);

int main()
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    printf("List : ");
    PrintForward(head);
    printf("\n");
    printf("Reversed List : ");
    PrintReversed(head);
}

void Insert(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if (head == NULL )
    {
       head = temp;
       return;
    }
    struct Node* temp1 = head;
    while( temp1 -> next != NULL )
        temp1 = temp1 -> next;
    temp1 -> next = temp;
}

void PrintForward( struct Node* temp )
{
    if( temp == NULL )
        return;
    printf("%d\t", temp -> data );
    PrintForward( temp -> next );
}

void PrintReversed( struct Node* temp )
{
    if( temp == NULL )
        return;
    int x = temp -> data;
    PrintReversed( temp -> next );
    printf("%d\t", x );
}
