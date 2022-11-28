#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>

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

    while ((currDirContent = readdir(currDir)) != NULL)
    {

        if(currDirContent->d_name[0] == '.') continue;

        printf ("%s\n", currDirContent->d_name);
        
    } 
    
    closedir(currDir);

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
    }
}