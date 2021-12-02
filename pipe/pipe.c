#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    int file;
    int fd[2];
    pid_t pid;
    if (pipe(fd)<0)
    {
        printf("failed to create pipe!\n");
        exit(1);
    }
     /* /this is the child processs! */
    else if(pid=fork()==0)      
    {
        char buffer[100]="this li shixuan";
        close(fd[0]);
        write(fd[1],buffer,sizeof(buffer));
        close(fd[1]);
        _exit(0);
    }
    /* this is the  parent processs */
    else {
        char buffer[100];
        close(fd[1]);
        wait(pid,NULL,0);
        read(fd[0],buffer,sizeof(buffer));
        printf("the content are writed by child process is :%s\n",&buffer);
        close(fd[0]);
    }
    return 0;
}

