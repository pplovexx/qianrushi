#include <stdio.h>
#include <unistd.h>          //POSIX definion for package
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
    int fd;
    int size;
    char buffer[100]="This is the second sentence";
    fd=open("tmp",O_RDWR);
    size=read(fd,buffer,sizeof(buffer));
    lseek(fd,size,SEEK_SET);
    write(fd,buffer,sizeof(buffer));
    close(fd);
    fd=open("tmp",O_RDWR);
    lseek(fd,0,SEEK_SET);
    read(fd,buffer,sizeof(buffer));
    close(fd);
    printf("%s",&buffer);
    return 0;

}


