#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("fail to creat childprocess!\n");
    }
    else if (pid==0){
        printf("this is the child process!and the pid: %d\n",getpid());
        execlp("ls","ls", "-l",NULL);
        exit(0);
    }
    else
    {
        while(
                waitpid(pid,NULL,WNOHANG)==0          //clean the log of childprocess

             ){
       printf("this the parent process! and the pid: %d\n",getpid());
       
       }
       
    }
    return 0;
}

