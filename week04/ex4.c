//run code with: gcc -std=c11 -Wall ex4.c -lreadline -o ex4 && ./ex4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <sys/wait.h>
#include <unistd.h>

//int execvp(const char *file, char *const argv[])
//int argc, char *argv[]

char **get_input(char *input);


int main() {
  char **command;
  char *input;
  pid_t child_pid;
  int stat_loc;

  while (1) {
    input = readline("hardriiveshell> ");
    command = get_input(input);

    child_pid = fork();
    if (child_pid < 0) {
      perror("Fork failed");
      exit(1);
    }
    if (child_pid == 0) {
      if (execvp(command[0], command) < 0) {
        perror(command[0]);
        exit(1);
      }

    } else {
      waitpid(child_pid, &stat_loc, WUNTRACED);
    }

    free(input);
    free(command);
  }

  return 0;
}

char **get_input(char *input) {
  char **command = (char **)malloc(8 * sizeof(char *));
  char *separator = " ";
  char *parsed;
  int index = 0;

  parsed = strtok(input, separator);
  if (command == NULL) {
    perror("malloc failed");
    exit(1);
  }
  while (parsed != NULL) {
    command[index] = parsed;
    index++;
    parsed = strtok(NULL, separator);
  }

  command[index] = NULL;
  return command;
}
