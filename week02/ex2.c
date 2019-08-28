#include <stdio.h>
#include <string.h>

#define n 50

int main() {
  char buffer[n];
  printf("Enter a string: ");
  fgets(buffer, n, stdin);
  printf("Original String: %s", buffer);

  printf("Result: ");
  for (int i = strlen(buffer) - 1; i >= 0; i--) {
    printf("%c", buffer[i]);
  }

  printf("\n");
  return 0;
}
