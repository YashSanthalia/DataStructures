#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

struct Node* stack;

void insert(int data);
void print();
void reverse();

int main()
{
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    print();
    reverse();
    reverse();
}

void insert(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if( head == NULL )
    {
        head = temp;
        return;
    }
    struct Node* temp1 = head;
    while( temp1 -> next != NULL )
        temp1 = temp1 -> next;
    temp1 -> next = temp;
}

void print()
{
    struct Node* temp = head;
    printf("LIST : ");
    while(temp != NULL)
    {
        printf("%d\t", temp -> data );
        temp = temp -> next;
    }
    printf("\n");
}

void reverse()
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        push(temp);
    }
}

void push( struct Node* temp)
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = temp -> data;
    new -> next = NULL;
    if(stack == NULL)
    {
        stack = new;
        return;
    }
    new -> next = stack;
    stack = new;
}

void pop()
{
    struct Node* temp;
    temp = top;
    top = top -> next;
    free(temp);

}
