#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define N 5

pthread_t thread_id[N];

void * print_self(void * i) {
   printf("Thread number %d - I was created in iteration %d !\n", (int) pthread_self(), (int)i);
}

int main(int argc, char * argv[]) {
  int ireturn;
  for (size_t i = 0; i < N; i++) {
    /* Create independent threads each of which will execute function */
    ireturn = pthread_create(&thread_id[i], NULL, print_self, (void *)i);
    if (ireturn) {
      printf("\n ERROR: return code from pthread_create is %d \n", ireturn);
      exit(1);
    }
    printf("\n I am thread %d. Created new thread (%d) in iteration %zu\n", (int) pthread_self(), (int) thread_id[i], i);
  }

  for (size_t i = 0; i < N; i++) {
    pthread_join(thread_id[i], NULL);
  }
  // printf("\n");
  // for (size_t i = 0; i < N; i++) {
  //   printf("%d ", (int)thread_id[i]);
  // }
    exit(0);
}
