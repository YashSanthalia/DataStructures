#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

void insert(struct BstNode** root,  int data);
int search(struct BstNode* root, int data);
struct BstNode* getNewNode();

int main()
{
    struct BstNode* root = NULL;
    int found;
    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 8);
    insert(&root, 12);
    insert(&root, 25);
    insert(&root, 17);
    found = search(root, 10);
    if( found == 1 )
        printf("FOUND");
    else
        printf("NOT FOUND");
    found = search(root, 13);
     if( found == 1 )
        printf("FOUND");
    else
        printf("NOT FOUND");
    insert(&root, 13);
    found = search(root, 13);
    if( found == 1 )
        printf("FOUND");
    else
        printf("NOT FOUND");


}

void insert(struct BstNode** root,  int data)
{
    if( *root == NULL )
    {
        *root = getNewNode(data);
        return;
    }
    else if( data <= (*root) -> data )
        insert( &((*root) -> left), data );
    else
        insert( &((*root) -> right), data);

}

int search( struct BstNode* root, int data )
{
    if( root == NULL )
        return 0;
    if( data == root -> data)
        return 1;
    else if( data <= root -> data )
        search( root -> left , data );
    else
        search(root -> right , data );
}

struct BstNode* getNewNode(int data)
{
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
