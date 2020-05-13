#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    char c;
    struct BstNode* left;
    struct BstNode* right;
};

void insert( struct BstNode** root, char c );
struct BstNode* getNewNode(char c);
void preorder(struct BstNode* root);
//void search(struct BstNode* root, char c);


int main()
{
    struct BstNode* root = NULL;
    insert(&root, 'F');
    insert(&root, 'J');
    insert(&root, 'D');
    insert(&root, 'B');
    insert(&root, 'E');
    insert(&root, 'A');
    insert(&root, 'C');
    insert(&root, 'G');
    insert(&root, 'K');
    insert(&root, 'I');
    insert(&root, 'H');
    printf("PREORDER : ");
    preorder(root);
    printf("\nINORDER : ");
    inorder(root);
    printf("\nPOSTORDER : ");
    postorder(root);
}

void insert( struct BstNode** root, char c )
{
    if( *root == NULL )
    {
        *root = getNewNode(c);
        return;
    }
    if( (int)c <= (int)(*root) -> c )
        insert(&(*root) -> left, c );
    else
        insert(&(*root) -> right, c );
}

struct BstNode* getNewNode(char c)
{
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode -> c = c;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void search(struct BstNode* root, char c)
{
    if( root == NULL )
        return;
    if( c == root -> c )
    {
        printf("%c FOUND", c );
        return;
    }
    if( (int)c <= (int)root -> c )
        search( root -> left, c );
    else
        search( root -> right, c );
}

void preorder(struct BstNode* root)
{
    if( root == NULL )
        return;
    printf("%c\t", root -> c );
    preorder( root -> left );
    preorder( root -> right );
}

void inorder( struct BstNode* root )
{
    if( root == NULL )
        return;
    inorder( root -> left );
    printf("%c\t", root -> c);
    inorder( root -> right );
}

void postorder( struct BstNode* root )
{
    if( root == NULL )
        return;
    postorder( root -> left );
    postorder( root -> right );
    printf("%c\t", root -> c );
}
