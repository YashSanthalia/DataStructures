#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

void insert( struct BstNode** root, int data);
int max(struct BstNode* root);
int min(struct BstNode* root);
struct BstNode* getNewNode();

int main()
{
    struct BstNode* root = NULL;
    insert(&root, 12);
    insert(&root, 34);
    insert(&root, 56);
    insert(&root, 4);
    insert(&root, 45);
    insert(&root, 2);
    insert(&root, 89);
    printf("MAX ELEMENT = %d\n", max(root));
    printf("MIN ELEMENT = %d", min(root));
}

void insert( struct BstNode** root, int data )
{
    if( *root == NULL )
    {
        *root = getNewNode(data);
        return;
    }
    if( data <= (*root) -> data )
        insert(&(*root) -> left, data );
    else
        insert(&(*root) -> right, data );
}

int max( struct BstNode* root )
{
    if( root -> right == NULL )
        return root -> data;
    max( root -> right );
}

int min( struct BstNode* root )
{
    if(root -> left == NULL )
        return root -> data;
    min( root -> left );
}

struct BstNode* getNewNode(int data)
{
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
