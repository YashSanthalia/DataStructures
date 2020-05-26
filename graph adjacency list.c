//GRAPHS

#include <stdio.h>
#include<stdlib.h>

char vertices[8];

struct BstNode{
    int vertex;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* list[8];

struct BstNode* createBstNode(int j);

int main(void) {
    for(int i = 0 ; i < 8 ; i++)
        list[i] = NULL;
    inputVertices();
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0 ,3);
    addEdge(1, 0);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 0);
    addEdge(2, 6);
    addEdge(3, 0);
    addEdge(3, 7);
    addEdge(4, 1);
    addEdge(4, 7);
    addEdge(5, 1);
    addEdge(5, 7);
    addEdge(6, 2);
    addEdge(6, 7);
    addEdge(7, 3);
    addEdge(7, 6);
    addEdge(7, 4);
    addEdge(7, 5);
    print();
	return 0;
}

void inputVertices(){
    for( int i = 0 ; i < 8 ; i++ ){
        fflush(stdin);
        scanf("%c", &vertices[i]);
    }
}


void addEdge( int i, int j){
    insert(&list[i], j);
}

void insert( struct BstNode** root, int j){
    if( *root == NULL ){
        *root =  createBstNode(j);
        return;
    }
    if( (*root) -> vertex > j)
        insert( &(*root) -> left, j);
    else
        insert( &(*root) -> right, j);
}

struct BstNode* createBstNode(int j){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> vertex = j;
    return newNode;
}

void print(){
    for(int i = 0 ; i < 8 ; i++ ){
        inorder(list[i]);
        printf("\n");
    }
}

void inorder(struct BstNode* root){
    if( root == NULL )
        return;
    inorder(root -> left);
    printf("%c\t", vertices[root -> vertex]);
    inorder(root -> right);
}
