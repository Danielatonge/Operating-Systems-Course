#include <stdio.h>
#include <unistd.h>
/* Program 1
int main(void) {
  printf("Hello");
  fork();
  printf("\n");
  return 0;
}
*/

// Program 2
int main(void) {
  printf("Hello\n");
  fork();
  printf("\n");
  return 0;
}
