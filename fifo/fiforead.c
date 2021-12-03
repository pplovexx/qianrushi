#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    int read_fd;
    int size;
    char buf[256];
    while((read_fd=open("lucy",O_RDONLY))==-1)
    {
        sleep(1);
    }
   while(1){
        size=read(read_fd,buf,sizeof(buf));
        if(size>0){
            buf[size]='\0';
            printf("lucy:%s",buf);
            
       }  
    }
    close(read_fd);
    return 0;
}
