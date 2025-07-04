#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
sem_t countsem;
void* my_function(void* arg){
    int threadids=*(int*)arg;
    sem_wait(&countsem);
    printf("Person entering:%d\n",threadids);
    sleep(2);
    printf("Person leaving:%d\n",threadids);
    sem_post(&countsem);
    return NULL;
}

int main()
{
    pthread_t person[100];
    int person_ids[]={1,2,3,4,5,6,7,8,9,10};
    sem_init(&countsem, 0,2);
    for(int i=0;i<10;i++){
        pthread_create(&person[i],NULL,my_function,(void*)&person_ids[i]);
    }
    for(int i=0;i<10;i++){
        pthread_join(person[i],NULL);
    }
    sem_destroy(&countsem);
    return 0;
}


/*
OUTPUT:
Person entering:1
Person entering:3
Person leaving:3
Person leaving:1
Person entering:4
Person entering:5
Person leaving:5
Person leaving:4
Person entering:7
Person entering:6
Person leaving:7
Person leaving:6
Person entering:2
Person entering:8
Person leaving:8
Person leaving:2
Person entering:10
Person entering:9
Person leaving:10
Person leaving:9
*/
