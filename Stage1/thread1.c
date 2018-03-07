#include<stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
 void *thread_function(void *arg) {
  int i;
  for ( i=0; i<20; i++) {
    printf("Thread says hi!\n");
    sleep(1);
  }
  return NULL;
}
int main(void) {
  pthread_t mythread;
  
  if ( pthread_create( &mythread, NULL, thread_function, NULL) ) {
    printf("error creating thread.");
    abort();
  }
  printf("%ld\n",mythread);  //区别fork()创建多进程，前面创建的对等线程只是去调用thread_function函数，并不执行后面的语句，这些语句只有主线程才执行，因此只输出一次ID
  if ( pthread_join ( mythread, NULL ) ) {
    printf("error joining thread.");
    abort();
  }
  return 0;
}
