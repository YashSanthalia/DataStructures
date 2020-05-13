
#include<stdio.h>
void removeElement(int array[], int sizeOfArray);


#define MAX_SIZE 20

int main()
{
    int array[MAX_SIZE], sizeOfArray;
    sizeOfArray = inputSizeOfArray();
    inputArray(array, sizeOfArray);
    displayArray(array, sizeOfArray);
    insertElement(array, sizeOfArray);
    displayArray(array, sizeOfArray + 1);
    removeElement(array, sizeOfArray);
    displayArray(array, sizeOfArray -1 );
}

int inputSizeOfArray()
{
    int sizeOfArray;
    printf("Enter the size of array : ");
    scanf("%d", &sizeOfArray);
    return sizeOfArray;
}

void inputArray(int array[], int sizeOfArray)
{
    printf("Enter %d elements : \n", sizeOfArray);
    for( int i = 0 ; i < sizeOfArray ; i++ )
        scanf("%d", &array[i]);
}

void displayArray(int array[], int sizeOfArray )
{
    printf("Inputed Array : \n");
     for( int i = 0 ; i < sizeOfArray ; i++ )
        printf("%d\t", array[i]);
}

void insertElement(int array[], int sizeOfArray )
{
    int indexOfInsertion, elementToInsert;
    printf("Enter the index at which insertion has to be done :\n");
    scanf("%d", &indexOfInsertion );
    printf("Enter the element to insert :\n");
    scanf("%d", &elementToInsert );
    insertion(array, sizeOfArray, indexOfInsertion, elementToInsert);
}

void removeElement(int array[], int sizeOfArray)
{
    int indexOfRemove, elementToRemove;
    printf("Enter the index at which deletion has to be done :\n");
    scanf("%d", &indexOfRemove );
    printf("Enter the element to remove :\n");
    scanf("%d", &elementToRemove );
    deletion(array, sizeOfArray, indexOfRemove, elementToRemove);
}

void insertion( int array[], int sizeOfArray, int indexOfInsertion, int elementToInsert )
{
    for( int i = sizeOfArray ; i > indexOfInsertion ; i--)
        array[i] = array[i - 1];
    array[indexOfInsertion] = elementToInsert;
}

void deletion( int array[], int sizeOfArray, int indexOfRemove, int elementToRemove )
{
     for( int i = indexOfRemove ; i < sizeOfArray - 1 ; i++ )
        array[i] = array[i + 1];
}

