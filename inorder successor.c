#include<stdio.h>
#include<stdlib.h>

struct bst{
    int data;
    struct bst* left;
    struct bst* right;
};

void insert( struct bst** root, int data );
struct bst* getNewNode( int data );
struct bst* findMin( struct bst* root );
struct bst* search( struct bst* root, int data );
void getSuccessor( struct bst* root, int data );
struct bst* findMin( struct bst* root );


int main()
{
    struct bst* root = NULL;
    insert(&root, 21);
    insert(&root, 32);
    insert(&root, 45);
    insert(&root, 12);
    insert(&root, 212);
    insert(&root, 31);
    insert(&root, 2);
    insert(&root, 13);
    insert(&root, 34);
    getSuccessor(root, 13);
}

void insert( struct bst** root, int data )
{
    if( *root == NULL )
    {
        *root = getNewNode( data );
        return;
    }
    if( data <= (*root) -> data )
        insert( &(*root) -> left, data );
    else
        insert( &(*root) -> right, data );
}

struct bst* getNewNode( int data )
{
    struct bst* newNode = (struct bst*)malloc(sizeof(struct bst));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void getSuccessor( struct bst* root, int data )
{
    if( root == NULL )
        return;
    struct bst* current = search( root, data );
    struct bst* successor = NULL;
    if( current -> right != NULL )
        successor = findMin( current -> right );
    else
    {
        struct bst* ancestor = root;
        while( current != ancestor )
        {
            if( current -> data < ancestor -> data )
            {
                successor = ancestor;
                ancestor = ancestor -> left;
            }
            else
                ancestor = ancestor -> right;
        }
    }
    printf("SUCCESSOR = %d", successor -> data );
}

struct bst* search( struct bst* root, int data )
{
    if( root -> data == data )
        return root;
    if( data <= root -> data )
        search( root -> left, data );
    else
        search( root -> right, data );
}

struct bst* findMin( struct bst* root )
{
    if( root -> left == NULL )
        return root;
    findMin( root -> left );
}
