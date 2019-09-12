//run code with : gcc -std=c11 -Wall ex3.c -lreadline -o ex3 && ./ex3

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <unistd.h>


int main() {
  char *input;
  int status = 0;

  input = readline("hardriiveshell> ");

  if ((status = system(input)) < 0) {
    perror("\nChild process could not be created");
    exit(1);
  } else if (status == 127){
    perror("\nShell could not be executed in child process");
    exit(1);
  }

  free(input);

  return 0;
}
