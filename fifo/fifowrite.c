#include <stdio.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
    int  write_fd;
    char buf[256];




    mkfifo("lucy",S_IWUSR);
    
    write_fd=open("lucy",O_WRONLY);
    while(1){
        printf("lucy: ");
        fgets(buf,sizeof(buf),stdin);
        
        write(write_fd,buf,sizeof(buf));
       }
    close(write_fd);
    return 0;
}

