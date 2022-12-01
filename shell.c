#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <dirent.h>


int READ = 0;

int WRITE = 1;

char *args[1000][1000];

int args_count = 0;



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



void Copy(char *src , char *dest)
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



void ExecuteCommandS(char *arguments[1000][1000]) {

    int pd[2];

    int iterator = 0;

    int fd[2];

    int f_in = 0;

while(iterator <= args_count) {//go through and execute all the commands

      pid_t pid;

      int status;

      pipe(fd);

      pid = fork();

      if(pid != 0) {

          waitpid(pid, &status, 0);//wait for child to exit
          close(fd[WRITE]);//close the writing end

              if(WIFEXITED(status))
                {

                    if(WEXITSTATUS(status) == 0)
                    {
                        /*it worked*/

                    } else if(WEXITSTATUS(status) == 255) {

                        printf("The program %s does not exist \n", arguments[iterator][0]);

                    } else {

                        printf("ERROR: Error code: %d", WEXITSTATUS(status));

                    }
                }
                else
                {
                    printf("There was a problem that is not normal %d", status);
                }

                f_in = fd[READ];//set the pipe to the in

          if(iterator == args_count) {

              printf("\n \n");

          }

          //return 1;

        } else {

          dup2(f_in, 0);

          if(iterator != args_count) {//its not the main value

              dup2(fd[WRITE], 1);//write to pipe

          }

          close(fd[READ]);

              exit(execvp(arguments[iterator][0], arguments[iterator]));

            
        }

    iterator++;

    }//end while

    

}







int main()
{
    char command[1024];
    char *pipe_finder;

    while(1)
    {
        fflush(stdin);
        fflush(stdout);

        printf("shell>");


        *command = 0;


        fgets(command,sizeof command, stdin);
        fflush(stdout);
        
        char  *token = strtok(command, " \n\t");

          if (strcmp(token, "exit") == 0) { 
               return 0;         

          }

         if (strcmp(token, " ") == 0) { 
               continue;       

          }

         pipe_finder = token;

         memset(args, 0, sizeof(args[0][0]) * 1000 * 1000);

         args_count = 0;

          int count = 0;

          while(pipe_finder != NULL) 
          {

             if(strcmp(pipe_finder, "|") != 0)
              {


                 args[args_count][count] = pipe_finder;

                 count++;

                 pipe_finder = strtok(NULL, " \n\t");

             } 

             else
              {
                //pipe was found, up the argument counter and set count to 0

                args[args_count][count] = NULL;

                args_count++;

                 count = 0;

                 pipe_finder = strtok(NULL, " \n\t");

             }

         }

         args[args_count][count] = NULL;

     ExecuteCommandS(args);

        
    }


    return 0;

}