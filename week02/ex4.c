#include <stdio.h>

void swap_function(int *, int *);


int main() {
  int ifirst;
  int isecond;
  puts("Enter 2 integers.");
  printf("First Integer: ");
  scanf("%d", &ifirst);
  printf("Second Integer: ");
  scanf("%d", &isecond);
  puts("");
  
  puts("Before Swap");
  printf("First: %d\n", ifirst);
  printf("Second: %d\n", isecond);
  puts("");
  swap_function(&ifirst, &isecond);
  puts("After Swap");

  printf("First: %d\n", ifirst);
  printf("Second: %d\n", isecond);

  return 0;
}


void swap_function(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}
