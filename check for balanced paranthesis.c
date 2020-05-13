#include<stdio.h>
#include<stdlib.h>

void reverse(char closing[], int length);
int compare( char opening[], char closing[], int length );


int main()
{
    char string[100], opening[100], closing[100];
    int o = 0, c = 0;
    printf("Enter a string");
    gets(string);
    int length = strlen(string);
    for(int i = 0 ; i < length ; i++)
    {
        if(string[i] == '(' || string[i] == '{' || string[i] == '[')
        {
            opening[o] = string[i];
            o++;
        }
        else if(string[i] == ')' || string[i] == '}'  || string[i] == ']')
        {
            closing[c] = string[i];
            c++;
        }
    }
    if(o != c)
    {
        printf("NOT BALANCED");
        return 0;
    }
    reverse(closing, c);
    int result = compare(opening, closing, o);
    if(result == -1 )
        printf("NOT BALANCED");
    else
        printf("BALANCED");
}

void reverse(char closing[], int length)
{
    int i = 0, j = length - 1;
    char temp;
    while(i < j)
    {
        temp = closing[i];
        closing[i] = closing[j];
        closing[j] = temp;
        i++;
        j--;
    }
}

int compare( char opening[], char closing[], int length )
{
    for( int i = 0 ; i < length ; i++ )
    {
        if( (opening[i] == '(' && closing[i] == ')') || ( opening[i] == '{' && closing[i] == '}' ) || (opening[i] == '[' && closing[i] == ']'))
            continue;
        else
            return -1;
    }
    return 1;
}
