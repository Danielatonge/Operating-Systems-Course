#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<signal.h>

int main()
{
	int pid, pid1, status;
  int io[2];
  char read_var[6];
  pipe(io);

	pid = fork();
	if (pid == 0) {
    printf("First child running\n");
		sleep(1);
    close(io[1]);
    read(io[0], read_var, 6);
    read_var[5] = '\0';
    printf("Received 2nd child pid: %d\n", atoi(read_var));
    printf("SIGSTOP about to get applied\n");
    kill(atoi(read_var), SIGSTOP);
	}	else {

		pid1 = fork();
		if (pid1 == 0) {
      printf("Second child running\n");
			sleep(3);
		} else {
      /*parent process*/
      char string[5];
      snprintf(string, 5, "%d" , pid1);
      close(io[0]);
      write(io[1], string, sizeof(int));
      printf("Waiting....(For state changes in second child)\n");
      waitpid(pid1, &status, WUNTRACED);
    }
	}

	return 0;
}
