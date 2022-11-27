#include <stdio.h>


int main()
{
    while(1)
    {
        char command[1000];
        printf("shell>");
        scanf("%s",command);
        printf("%s",command);
    }
}