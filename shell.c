#include <stdio.h>
#include <string.h>

int main()
{
    while(1)
    {
        char command[1000];
        printf("shell>");
        scanf("%s",command);
        if(strcmp("DIR",command))
        {
            printf("DIR\n");
        }
        else if(strcmp("COPY",command))
        {
            
            printf("COPY\n");
        }
        else
        {
            printf("no command");
        }
        printf("%s\n",command);
    }
}