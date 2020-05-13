#include<stdio.h>
#include<stdlib.h>

struct bst{
    int data;
    struct bst* left;
    struct bst* right;
};

void insert( struct bst** root, int data );
struct bst* getNewNode( int data );
struct bst* delete(struct bst* root, int data);
struct bst* findMin( struct bst* root );
int search( struct bst* root, int data );

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
    delete(root, 12);
    printf("%d\n", search(root, 12));
    delete(root, 32);
    printf("%d\n", search(root, 32));
    printf("%d\n", search(root, 2));
    printf("%d\n", search(root, 212));


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

struct bst* delete(struct bst* root, int data)
{
    if( root == NULL )
        return;
    if( data < root -> data )
        root -> left = delete( root -> left, data );
    else if( data > root -> data )
        root -> right = delete( root -> right, data );
    else
    {
        if( root -> left == NULL && root -> right == NULL )
        {
            free( root );
            root = NULL;
        }
        else if( root -> right == NULL)
        {
            struct bst* temp = root;
            root = root -> left;
            free(temp);
        }
        else if( root -> left == NULL )
        {

            struct bst* temp = root;
            root = root -> right;
            free(temp);
        }
        else
        {
            struct bst* temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = delete( root -> right, temp -> data );
        }
    }
    return root;
}

struct bst* findMin( struct bst* root )
{
    if( root -> left == NULL )
        return root;
    findMin( root -> left );
}

int search( struct bst* root, int data )
{
    if( root == NULL )
        return 0;
    if( root -> data == data )
        return 1;
    if( data <= root -> data )
        search( root -> left, data );
    else
        search( root -> right, data );
}
