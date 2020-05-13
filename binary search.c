#include<stdio.h>
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10}, key;
    printf("Enter the element to search");
    scanf("%d", &key);
    int lo = 0, hi = 9;
    int mid;
    while( lo <= hi )
    {
        mid = (hi + lo)/2;
        if( key == a[mid] )
            {printf("Element is found at %d position", mid );
            break;}
        else if( key > a[mid] )
            lo = mid + 1;
        else
            hi = mid - 1;
    }

}
