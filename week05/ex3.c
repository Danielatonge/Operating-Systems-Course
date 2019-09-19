#include <stdio.h>
#include <pthread.h>
#define SIZE 10

void *producer();
void *consumer();

int index=0;
char *BUFFER;

pthread_cond_t signal_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t signal_not_empty = PTHREAD_COND_INITIALIZER;
pthread_mutex_t token = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    pthread_t ptid, ctid;

    BUFFER = (char *) malloc(sizeof(char) * SIZE);

    pthread_create(&ptid,NULL,producer,NULL);
    pthread_create(&ctid,NULL,consumer,NULL);

    pthread_join(ptid,NULL);
    pthread_join(ctid,NULL);

    exit(0);
}

void *producer()
{
    while(1)
    {
        pthread_mutex_lock(&token);
        if(index==SIZE)
        {
            pthread_cond_wait(&signal_not_full,&token);
        }
        BUFFER[index++]='@';
        printf("Produce : %d \n",index);
        pthread_mutex_unlock(&token);
        pthread_cond_signal(&signal_not_empty);
        //sleep(1);
    }
}

void *consumer()
{
    while(1)
    {
        pthread_mutex_lock(&token);
        if(index==-1)
        {
            pthread_cond_wait(&signal_not_empty,&token);
        }
        printf("Consume : %d \n",index--);
        pthread_mutex_unlock(&token);
        pthread_cond_signal(&signal_not_full);
        //sleep(2);
    }
}
