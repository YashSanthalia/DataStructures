#include <stdio.h>
#define MAX 100

int end = -1;

int main(void) {
	int array[MAX], n;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    fflush(stdin);
	inputArray(array, n);
	heapcreate(array, end);
	int max = extractmax(array, end);
    heapIncreaseKey(array, 3, 44);
    insertInHeap(array, 40, ++end );
	return 0;
}

void inputArray( int array[], int n ){
    printf("Enter the elements\n");
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d", &array[i]);
        fflush(stdin);
        end++;
    }
}

void heapcreate( int array[], int n ){
    for( int i = n / 2 - 1 ; i >= 0 ; i-- ){
        maxHeapify(array, i, end);
    }
}

void maxHeapify( int array[], int i, int n ){
    if( i >= n / 2)
        return;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if( l < n && array[l] > array[i] )
        largest = l;
    if( r < n && array[largest] < array[r] )
        largest = r;
    if( largest != i ){
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
         if( largest >= n / 2)
        return;
        maxHeapify(array, largest, n);
    }
}

int extractmax(int array[], int n){
    int max = array[0];
    array[0] = array[n];
    end--;
    maxHeapify(array, 0, end); 
    return max;
}

void heapIncreaseKey(int array[], int i, int key ){
    array[i] = key;
    while( i > 0 && array[(i - 1) / 2] < array[i] ){
        int temp = array[i];
        array[i] = array[(i - 1) / 2];
        array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void insertInHeap( int array[], int key, int n){
    array[n] = key;
    int i = n;
    while( i > 0 && array[i] > array[(i - 1) / 2]){
        int temp = array[i];
        array[i] = array[(i -  1) / 2];
        array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}