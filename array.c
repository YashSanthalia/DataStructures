#include<stdlib.h>
#include<stdio.h>
int main()
{
    int *array = (int*)malloc(5 * sizeof(int));
    int end = -1;
    for( int i = 0 ; i < 5 ; i++ )
        scanf("%d", &array[i]);
    array = realloc(array, 10 * sizeof(int));
    array[5] = 9;
    printf("%d", array[5]);

}
