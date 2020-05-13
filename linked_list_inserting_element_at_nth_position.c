#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* Insert( struct Node* head, int data, int n );
void Print(struct Node*);
int main()
{
    struct Node* head;
    head = NULL;
    head = Insert(head, 5, 1);
    head = Insert(head, 3, 2);
    head = Insert(head, 4, 1);
    head = Insert(head, 6, 1);
    head = Insert(head, 2, 3);
    Print(head);
}

struct Node* Insert( struct Node* head, int data, int n )
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1 -> data = data;
    temp1 -> next = NULL;
    if( n == 1 )
    {
        temp1 -> next = head;
        head = temp1;
        return head;
    }
    struct Node* temp2 = head;
    for( int i = 0 ; i < n - 2 ; i++ )
        temp2 = temp2 -> next;
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    return head;
}

void Print(struct Node* head)
{
    printf("List is : ");
    while(head != NULL)
    {
        printf("%d\t", head -> data);
        head = head -> next;
    }
}
