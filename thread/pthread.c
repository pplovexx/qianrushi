#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
/* this is the thread fuction */
void thread(void){
    printf("this is the subthread!\n");
    pthread_exit(0);

}
int main()
{
    pthread_t id;
    pthread_create(&id,NULL,(void*)thread,NULL);
    pthread_join(id,NULL);
    printf("this is the main thread!\n");
    return 0;
}

