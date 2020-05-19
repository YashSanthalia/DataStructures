#include <stdio.h>
#define MAX 100

int main(void) {
    int array[MAX], n;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    fflush(stdin);
	inputArray(array, n);
	//selectionsort(array, n);
    //bubblesort(array, n);
    //insertionsort(array, n);
    quicksort(array, 0, n - 1 );
	for( int i = 0 ; i < n ; i++)
	    printf("%d\t", array[i]);
	return 0;
}

void inputArray( int array[], int n ){
    printf("Enter the elements\n");
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d", &array[i]);
        fflush(stdin);
    }
}

void selectionsort( int array[], int n){
    for( int i = 0 ; i < n ; i++ ){
        int index = i;
        int min = array[i];
        for( int j = i + 1 ; j < n ; j++ ){
            if( min > array[j]){
                min = array[j];
                index = j;
            }
        }
            array[index] = array[i];
            array[i] = min;
    }
}

void bubblesort(int array[], int n){
    for(int i = 0 ; i < n - 1 ; i++ ){
        for( int j = 0 ; j < n - i - 1 ; j++ ){
            if( array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void insertionsort(int a[], int n){
    int b[n], j;
    b[0] = a[0];
    for( int i = 1 ; i < n ; i++ ){
        for( j = i - 1 ; j >= 0 && a[i] < b[j] ; j-- )
            b[j + 1] = b[j];
        b[j + 1] = a[i];
    }
    for( int i = 0 ; i < n ; i++ ){
        a[i] = b[i];
    }
}

void quicksort( int array[], int start, int end ){
    if( start < end ){
    int pIndex = partition(array, start, end);
    quicksort(array, start, pIndex - 1);
    quicksort(array, pIndex + 1, end);
    }
}

int partition(int array[], int start , int end){
    int pivot = array[end];
    int pIndex = start;
    for( int i = start ; i < end ; i++ ){
        if( array[i] < pivot){
            int temp = array[i];
            array[i] = array[pIndex];
            array[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = array[pIndex];
    array[pIndex] = array[end];
    array[end] = temp;

    return pIndex;
}
