#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool IsEqual(char string1[] , char string2[])
{
    if(!strcmp(string1,string2))
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    while(1)
    {
        char command[1000];
        printf("shell>");
        scanf("%s",command);
        if(IsEqual("DIR",command))
        {
            printf("DIR\n");
        }
        else if(IsEqual("COPY",command))
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