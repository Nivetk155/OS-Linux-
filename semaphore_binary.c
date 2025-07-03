#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
sem_t bsem;
void* my_function(void* arg){
    int id=*(int*)arg;
    sem_wait(&bsem);
    printf("thread id:%d entered...\n",id);
    fflush(stdout); 
    sleep(5);
    printf("thread id:%d leaving...\n",id);
    fflush(stdout); 
    sem_post(&bsem);
    return 0;
}

int main(){
    pthread_t t1,t2;
    int id1=1,id2=2;
    sem_init(&bsem,0,1);
    pthread_create(&t1,NULL,my_function,(void*)&id1);
    pthread_create(&t2,NULL,my_function,(void*)&id2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&bsem);
    return 0;    
}

/*
OUTPUT:
thread id:1 entered...
thread id:1 leaving...
thread id:2  entered...
thread id:2 leaving...
*/
