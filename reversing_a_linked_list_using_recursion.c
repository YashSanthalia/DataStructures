#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int data);
void print(struct Node*);
void reverse( struct Node* p );

int main()
{
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    print(head);
    reverse(head);
    print(head);
}

void insert(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = head;
    head =temp;
}

void print(struct Node *head)
{
    printf("List is : ");
    while( head != NULL )
    {
        printf("%d\t", head -> data );
        head = head -> next;
    }
    printf("\n");
}

void reverse( struct Node* p )
{
    if( p -> next == NULL )
        {head = p;
        return;}
    reverse( p-> next);
    p -> next -> next = p;
    p -> next = NULL;
}
