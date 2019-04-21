#include <pthread>

// global that repsents the number of readers
int reader_num=0;

// shared resource
int res=0;

// condition var
pthread_cond_t c_writer = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_reader = PTHREAD_COND_INITIALIZER;

// the mutex to operate on shared res
pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;

// reader: has priority over writer
void* reader(void)
{
  int i;

  reader_num++;

  // 1, lock mutex
  pthread_mutex_lock(&mtx);

    printf("Reader: reader number= %d\n",reader_num);

    i=res;

    reader_num--;

    printf("Reader: res= %d\n",res);

  pthread_mutex_unlock(&mtx);

  if(i==0)
    pthread_cond_signal(&c_writer,&mtx);
}

void* writer(void)
{
  pthread_mutex_lock(&mtx);

    while(reader_num>0)
    {
      pthread_cond_wait(&c_writer,&mtx);
    }

    printf("Writer: reader number= %d\n",reader_num);
    res++;
    printf("Writer: writes res = %d\n",res);
  
  pthread_mutex_unlock(&mtx);
}

int main()
{
  // pthread_mutex_init(&mtx,NULL);
}