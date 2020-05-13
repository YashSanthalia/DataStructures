#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct BstNode{
    char c;
    struct BstNode* left;
    struct BstNode* right;
};

void insert( struct BstNode** root, char c );
struct BstNode* getNewNode(char c);
void lot(struct BstNode* root);
void enqueue(struct BstNode* root);
void dequeue();

struct BstNode* queue[MAX];
int front = -1;
int end = -1;

int main()
{
    struct BstNode* root = NULL;
    insert(&root, 'F');
    insert(&root, 'D');
    insert(&root, 'J');
    insert(&root, 'B');
    insert(&root, 'E');
    insert(&root, 'G');
    insert(&root, 'K');
    lot(root);
}

void insert( struct BstNode** root, char c )
{
    if( *root == NULL )
    {
        *root = getNewNode(c);
        return;
    }
    if ( (int)c <= (int)(*root) -> c )
        insert( &(*root) -> left, c);
    else
        insert( &(*root) -> right, c);
}

struct BstNode* getNewNode(char c)
{
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof( struct BstNode ));
    newNode -> c = c;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void lot(struct BstNode* root)
{
    if( root == NULL )
        return;
    enqueue(root);
    while( end != -1 )
    {
        dequeue();
    }
}

void enqueue(struct BstNode* root)
{
    if( front == -1 )
    {
        front = 0;
        end = 0;
    }
    else if( (end + 1) % MAX == front )
        return;
    else
        end = (end + 1)% MAX;
    queue[end] = root;
}

void dequeue()
{
    printf("%c\t", queue[front] -> c );
    if( queue[front] -> left != NULL )
        enqueue( queue[front] -> left );
    if( queue[front] -> right != NULL )
        enqueue( queue[front] -> right );
    if( front == end )
    {
        front = -1 ;
        end = -1;
        return;
    }
    front++;
}
