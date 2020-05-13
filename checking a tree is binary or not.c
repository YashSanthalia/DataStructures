#include<stdio.h>
#include<stdlib.h>

struct BtN{
    int data;
    struct BtN* left;
    struct BtN* right;
};

void insert( struct BtN** root, int data );
struct BtN* getNewNode( int data );
void checkingBst( struct BtN* root );

int main()
{
    struct BtN* root = NULL;
    insert(&root, 23);
    insert(&root, 45);
    insert(&root, 2);
    insert(&root, 78);
    insert(&root, 43);
    checkingBst(root);
}

void insert( struct BtN** root, int data )
{
    if( *root == NULL )
    {
        *root = getNewNode(data);
        return;
    }
    if( data >= (*root) -> data )
        insert(&(*root) -> left, data );
    else
        insert(&(*root) -> right, data );
}

struct BtN* getNewNode( int data )
{
    struct BtN* newNode = ( struct BtN* )malloc( sizeof(struct BtN));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void checkingBst( struct BtN* root )
{
    if( root == NULL )
        return;
    if( root -> left != NULL )
    {
        if( root -> data >= root -> left -> data )
            checkingBst( root -> left );
        else
        {
            printf(" Not a bst ");
            return;
        }
    }
    if( root -> right != NULL )
    {
        if( root -> data < root -> right -> data )
            checkingBst( root -> right );
        else
        {
            printf(" Not a bst");
            return;
        }
    }
}
