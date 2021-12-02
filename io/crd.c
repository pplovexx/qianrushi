#include <stdio.h>
#include<stdlib.h>
struct record{
    char name[10];
    int age;
};

int main()
{
    struct record array[2]={{"Ken",24},{"Knuth",28}};
    struct record array1[2];
    FILE *fp=fopen("tmp","w+");
    fwrite(array,sizeof(struct record),2,fp);                       
    fflush(fp);
    fread(array1,sizeof(struct record),2,fp);
    printf("%s",&array1[0].name);
    fclose(fp);
    return 0;
}

