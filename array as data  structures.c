#include<stdio.h>
#define MAX_SIZE 5
int main()
{
    int end = -1;
    printf("\t\t\t\t\tAn Array\n");
    int *array = (int*)malloc(MAX_SIZE * sizeof(int));
    displayMenu(array, end);
}

void displayMenu(int array[], int end)
{
    while(1)
    {
        int choose;
        printf("Choose what u want to do in that array: \n");
        printf("1.Display Array\n");
        printf("2. ADDING ELEMENT\n");
        printf("3. REMOVING ELEMENT\n");
        printf("4. INSERTING ELEMENT\n");
        printf("5. EXIT\n");
        printf("PRESS 1 or  2 or  3 or 4 or 5\n");
        scanf("%d", &choose);
        toDo(array, choose, end);
    }
}

void toDo(int array[], int choose, int end)
{
    switch choose
    {
    case 1:
        displayArray(array, end);
        break;
    case 2 :
        addingElement(array, end);
        break;
    case 3 :
        removingElement(array, end);
        break;
    case 4 :
        insertingElement(array, end);
        break;
    case 5 :
        exit(0);
    default :
        displaymenu();
    }
}

void displayArray(int array[], int end)
{
    printf("Array : \n");
    if( end == -1 )
        printf("Empty Array\n");
    for( int i = 0; i <= end ; i++ )
        printf("%d\t", array[i]);
}

void addingElement(int array[], int end )
{
    printf("Enter the element u want to add : \n");
    if( end >= MAX_SIZE && array[end] = -1 )
        array = realloc(array, (end + 1) * sizeof(int));
    scanf("%d", &array[end + 1]);
}

void removingElement(int array[], int end )
{
    int indexToRemove;
    printf("Enter the index u want to remove :\n");
    scanf("%d", &indexToRemove);
    for( i = indexToRemove ; i < end ; i++ )
        array[i] = array[i + 1];
    if(end >= MAX_SIZE)
        array[end] = -100;
    end = end - 1;
}

