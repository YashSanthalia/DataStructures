#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

void insert( struct BstNode** root, int data );
int findHeight( struct BstNode* root );
struct BstNode* getNewNode( int data );
int max( int lh, int rh);

int main()
{
    int height;
    struct BstNode* root = NULL;
    insert(&root, 12);
    insert(&root, 13);
    insert(&root, 34);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 89);
    insert(&root, 90);
    height = findHeight(root);
    printf("HEIGHT OF TREE : %d", height);
}

void insert( struct BstNode** root, int data )
{
    if( (*root) == NULL )
    {
        *root = getNewNode(data);
        return;
    }
    if( data <= (*root) -> data )
        insert(&(*root) -> left, data );
    else
        insert(&(*root) -> right, data );
}

struct BstNode* getNewNode( int data )
{
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

int findHeight( struct BstNode* root )
{
    if( root == NULL )
        return -1;
    int leftHeight = findHeight( root -> left );
    int rightHeight = findHeight( root -> right );
    return max( leftHeight, rightHeight) + 1;
}

int max( int lh, int rh)
{
    if( lh > rh )
        return lh;
    else
        return rh;
}
