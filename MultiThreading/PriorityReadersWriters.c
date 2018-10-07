#include <pthread.h>
#include <stdio.h>

#define NUM_READERS 5
#define NUM_WRITERS 5

#define NUM_X_TIME 10

// shared resource
int res=0;

// a flag shows that a writer is writting
int wrting_flg=0;
// a flag shows that a reader is reading
int reading_flg=0;

// Number of reader waitting
int waitting_reader_num=0;

// condition var
pthread_cond_t c_writer = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_reader = PTHREAD_COND_INITIALIZER;

// the mutex to operate on shared res
pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;

// reader: has priority over writer
void* reader(void* ReaderID)
{
  int i;
  int reader_id= *((int*)ReaderID);
  int local_reader_num=0;

  for(int j=0;j<NUM_X_TIME;j++)
  {
    // reader locks
    pthread_mutex_lock(&mtx);

      // may wait for write process
      waitting_reader_num++;

      while(wrting_flg==1)
      {
        pthread_cond_wait(&c_reader,&mtx);
      }
      //  no more watting
      waitting_reader_num--;
      local_reader_num=++reading_flg;

    pthread_mutex_unlock(&mtx);
    
    // Note :
    //  In this area, reading_flg makes sure that no writting will happen
    //  But, the number of readers may change by other readers

    // reading process
    i=res;
    printf("Reader= %d: reader number= %d, res= %d \n",reader_id,local_reader_num,i);

    // reader exiting
    pthread_mutex_lock(&mtx);

      // reset flag
      reading_flg--;
      // notify writers
      if(reading_flg==0) // waitting_reader_num==0 will always be true here
        pthread_cond_signal(&c_writer);
      else
      {
        pthread_cond_broadcast(&c_reader);
      }
    pthread_mutex_unlock(&mtx);

  }
  pthread_exit(0);
}

void* writer(void* args)
{
  int tid=*((int*)args);
  int local_reader_num;

  for(int j=0;j<NUM_X_TIME;j++)
  {
    pthread_mutex_lock(&mtx);

      while(reading_flg!=0)
      {
        pthread_cond_wait(&c_writer,&mtx);
      }

      // mark a writing flag
      wrting_flg=1;
    
    pthread_mutex_unlock(&mtx);

    local_reader_num=reading_flg;
    res++;
    // do the writing
    printf("Writer=%d: reader number= %d, res= %d\n",tid,local_reader_num,res);

    pthread_mutex_lock(&mtx);

      // reset thr flag
      wrting_flg=0;

      // notify waiting readers
      if(waitting_reader_num>0)
        pthread_cond_broadcast(&c_reader);
      else
        pthread_cond_signal(&c_writer);

    pthread_mutex_unlock(&mtx);
  }
  pthread_exit(0);
}

int main()
{
  // pthread_mutex_init(&mtx,NULL);
  int i;
  int readers[NUM_READERS];
  int writers[NUM_READERS];

  pthread_t reader_thread_id[NUM_READERS];
  pthread_t writer_thread_id[NUM_WRITERS];

  for(i=0;i<NUM_READERS;i++)
  {
    readers[i]=i;
    pthread_create(&reader_thread_id[i],NULL,reader,&readers[i]);
  }

  for(i=0;i<NUM_WRITERS;i++)
  {
    writers[i]=i;
    pthread_create(&writer_thread_id[i],NULL,writer,&writers[i]);
  }

  for(i=0;i<NUM_READERS;i++)
  {
    pthread_join(reader_thread_id[i],NULL);
  }
  for(i=0;i<NUM_WRITERS;i++)
  {
    pthread_join(writer_thread_id[i],NULL);
  }
}