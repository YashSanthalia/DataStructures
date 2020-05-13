#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void Insert(struct Node** , int data);
void Print(struct Node*);
void Delete(struct Node**, int n);

int main()
{
    struct Node* head;
    head = NULL;
    Insert(&head, 2);
    Insert(&head, 3);
    Insert(&head, 4);
    Insert(&head, 5);
    Print(head);
    Delete(&head, 3);
    Print(head);
    Delete(&head, 1);
    Print(head);
}

void Insert(struct Node** head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    struct Node* temp1 = *head;
    if(temp1 == NULL)
    {
        *head = temp;
        return;
    }
    while( temp1 -> next != NULL )
        temp1 = temp1 -> next;
    temp1 -> next = temp;
}

void Print(struct Node* head)
{
    printf("List is : ");
    while(head != NULL)
    {
        printf("%d\t", head -> data);
        head = head -> next;
    }
    printf("\n");
}

void Delete(struct Node** head, int n)
{
    struct Node* temp = *head;
    if( n == 1)
    {
        *head = temp -> next;
        free(temp);
        return;
    }
    for(int i = 0 ; i < n - 2 ; i++ )
        temp = temp -> next;
    struct Node* temp1 = temp -> next;
    temp -> next = temp1 -> next;
    free(temp1);
}

