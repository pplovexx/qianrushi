#include <stdio.h>
#include <unistd.h>          //POSIX definion for package
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main (){
    int fd;
    int size1;
    char buffer1[100]="this is first sentence!";
    char buffer2[100]="this is second sentence!";
    char buffer3[100];
    fd=open("tmp.txt",O_RDWR|O_CREAT);
    size1=write(fd,buffer1,sizeof(buffer1));
    lseek(fd,size1,SEEK_END);
    write(fd,buffer2,sizeof(buffer2));
    close(fd);
    fd=open("tmp.txt",O_RDWR);
    read(fd,buffer3,sizeof(buffer3));
    printf("%s",&buffer3);
    return 0;
}

