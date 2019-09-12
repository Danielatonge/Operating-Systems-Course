#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
  for(int i = 0; i < N; i++) {
    fork();
    sleep(5);
  }
  return 0;
}
