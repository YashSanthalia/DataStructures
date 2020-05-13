#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void Insert(struct Node**, int x);
void Print(struct Node*);
int main()
{
    struct Node* head = NULL;
    int n, x;
    printf("How many numbers u wanna enter?\n");
    scanf("%d", &n);
    for( int i = 0 ; i < n ; i++ )
    {
        printf("Enter the number : ");
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
}

void Insert(struct Node **head, int x)
{
    struct Node* temp = ( struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = *head;
    *head = temp;
}

void Print(struct Node* head)
{
    printf("List is : ");
    while( head != NULL )
    {
        printf("%d\t", head -> data);
        head = head -> next;
    }
    printf("\n");
}
