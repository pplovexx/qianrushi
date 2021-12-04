#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
/* declare mutial exclude varible */
    pthread_mutex_t n;
    pthread_t id;
/* this is the subthread! */

void thread(void){
    int re;
    pthread_mutex_lock(&n) ;
    printf("subthread: lock!\n");
    pthread_mutex_unlock(&n);
    while(1){
    if((re=pthread_mutex_trylock(&n))==0){
        printf("subthread: trylock!\n");
        
    }
    else{
        printf("failed to trylock !\n");
    }
   }
    pthread_exit(0);
}
int main()
{
    pthread_mutex_init(&n,NULL);
    pthread_mutex_lock(&n);
    printf("Main lock!\n");
    pthread_create(&id,NULL,(void*)thread,NULL);
    sleep(1);
    printf("Main unlock\n");
    pthread_mutex_unlock(&n) ;
    pthread_join(id,NULL);
    pthread_mutex_destroy(&n);
    return 0;
}

