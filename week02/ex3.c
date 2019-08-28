#include <stdio.h>
#include <stdlib.h>

void triangletwo(int n);
void trianglethree(int n);
void trianglefour(int n);
void triangleone(int n);

int main(int argc, char *argv[]) {
  if(argc == 2) {
    int n = atoi(argv[1]);
    int choice;
    printf("1. Variant One\n");
    printf("2. Variant Two\n");
    printf("3. Variant Three\n");
    printf("4. Variant Four\n");
    printf("Choose variant of triange to print: ");
    scanf("%d", &choice);

    if(choice == 1) {
      triangleone(n);
    } else if(choice == 2) {
      triangletwo(n);
    } else if(choice == 3) {
      trianglethree(n);
    } else if(choice == 4) {
      trianglefour(n);
    } else {
      printf("Not valid option\nSorry, try next time");
    }
  } else {
    puts("Incorrect program arguments");
  }

  return 0;
}

void triangleone(int n) {
  for (int i = 0; i < n; i++) {

    for (int j = n - i ; j >= 0 ; j--) {
      printf(" ");
    }

    for (int j = 1; j <= (2*i + 1) ; j++) {
        printf("*");
    }
    printf("\n");
  }
}


void triangletwo(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i ; j++) {
        printf("*");
    }
    printf("\n");
  }
}

void trianglethree(int n) {
  for (int i = 0; i < n; i++) {
    if (i <= n/2) {
      for (int j = 0; j <= i ; j++) {
          printf("*");
      }
    } else {
      for (int j = n-i-1 ; j >= 0; j--) {
          printf("*");
      }
    }
    printf("\n");
  }
}

void trianglefour(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n ; j++) {
        printf("*");
    }
    printf("\n");
  }
}
