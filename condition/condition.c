#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<pthread.h>

pthread_t id1,id2;
pthread_cond_t cond;
pthread_mutex_t mutex;

static int share_nub=4;
static void pthread_1(void);
static void pthread_2(void);


int main()
{
    int ret;
    /* init mutex and cond */
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    /* connect the cond and mutex */
    pthread_cond_init(&cond,&mutex);
    

    /* create thread1 and thread2 */
    if(ret=pthread_create(&id1,NULL,&pthread_1,NULL)){
        printf("thread_1 successfully create !\n");
    }if(ret=pthread_create(&id2,NULL,&pthread_2,NULL)){
        printf("thread_2 successfully create !\n");
    }
    /* free the resource of thread */
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);

    /* clear cond and mutex */
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}


static void pthread_1(void){
    pthread_mutex_lock(&mutex);
    share_nub=0;
    printf(" thread1 lock ! and the mutex = %d .\n ",&share_nub);
    sleep(1);
    /* wait the singal to wake the cond and relock the mutex; */
    pthread_cond_wait(&cond,&mutex);
    share_nub=100;
    printf("successfully waken the cond and relock the mutex :%d\n",share_nub);
    sleep(1);
    pthread_exit(0);

}
static void pthread_2(void){
    pthread_mutex_lock(&mutex);
    share_nub=10;
    printf("thread2 lock ! and the share_nub =:%d\n",share_nub);
    pthread_mutex_unlock(&mutex);
    /* free cond */
    pthread_cond_signal(&cond);
    pthread_exit(0);
}

