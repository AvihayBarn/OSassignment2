#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dirnet.h>

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



void Dir()
{
    struct dirent *currDirContent;
    DIR *currDir = opendir ("./");

    while ((currDirContent = readdir(currDir)) != NULL) {
            printf ("[%s]\n", currDirContent->d_name);
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
            Dir();
        }
        else if(IsEqual("COPY",command))
        {
            
            printf("COPY\n");
        }
        else
        {
            printf("no command\n");
        }
        printf("%s\n",command);
    }
}