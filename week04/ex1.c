#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  pid_t n = fork();
  if (n > 0) {
    printf("Hello from parent [PID - %d]\n", getpid());
  } else if (n == 0) {
    printf("Hello from child [PID - %d]\n", getpid());
  } else {
    printf("Error: No child process was created");
  }
  return 0;
}
