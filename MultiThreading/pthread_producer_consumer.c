#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUF_SIZE 3

int buf[BUF_SIZE];
int add=0;
int rem=0;
int num=0;

pthread_mutex_t mtx=PHREAD_MUTEX_INITIALIZER;


void *producer(void *param)
{
  int i;
  for(i=1;i<=20;i++)
  {
    // try lock the mutex and modify shared resources
    pthread_mutex_lock(&mtx);

      if(num>BUF_SIZE) exit(1);

      // when buf is full, wait consumer send signal
      while(num==BUF_SIZE)
      {
        // wait need the mutex argument to know which mutex to unlock
        pthread_cond_wait(&c_prod,&mtx);
      }

      // operate shared buffer
      buffer[add]=i;
      add=(add+1)%BUF_SIZE;
      num++;

    // unlock
    pthread_mutex_unlock(&mtx);

    // wakeup consumer thread waiting when the buf is empty
    pthread_cond_signal(&c_cons);

    printf("producer inserted %d\n",i);fflush(stdout);
  }

  printf("Producer quiting\n");

  return 0;
}

void* consumer(void* param)
{
  int i;

  // note: consumer do this in a loop, so it can execute multiple times !
  while(1)
  {
    // try to lock
    pthread_mutex_lock(&mtx);

      if(num<0 || num>BUF_SIZE)
        exit(1);

      while(num==0)
      {
        pthread_cond_wait(&c_cons,&mtx);
      }  
      
      // opearte
      i=buffer[rem];
      rem=(rem+1)%BUF_SIZE;
      num--;

    pthread_mutex_unlock(&mtx);

    // notify
    pthread_cond_broadcast(&c_prod);

    printf("consusmer deleted %d\n",i);fflush(stdout);
  }

  printf("Consumer quiting\n");

  return 0;
}