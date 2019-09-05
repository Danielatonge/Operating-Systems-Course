#include <stdio.h>

void bubble_sort(int *, int);
void print_array(int *, int);

int main() {
  int iarray[10] = {12, 3, 0, 5, 3, 6, 9, 1, 7, 10};
  printf("Before sorting: ");
  print_array(iarray, 10);
  bubble_sort(iarray, 10);
  printf("\n\nAfter sorting: ");
  print_array(iarray, 10);

  return 0;
}


void bubble_sort(int *array, int n) {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n - i - 1; j++) {
      if ( array[j] > array[j+1]) {
        int temp = array[j+1];
        array[j+1] = array[j];
        array[j] = temp;
      }
    }
  }
}

void print_array(int *array, int n) {
  printf("\n[ ");
  for (size_t i = 0; i < n; i++) {
    printf("%d ", *(array+i));
  }
  printf("]");
}
