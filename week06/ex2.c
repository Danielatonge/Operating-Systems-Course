#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int     io[2], infobytes;
    pid_t   childpid;
    char    string[] = "Innopolis University\n";
    char    readbuffer[60];

    if (pipe(io) < 0)
    exit(1);

    if((childpid = fork()) == -1) {
            perror("fork");
            exit(1);
    }

    if(childpid == 0) {
      /* Child process closes up output side of pipe */
      close(io[1]);

      /* Read in a string from the pipe */
      infobytes = read(io[0], readbuffer, sizeof(readbuffer));
      printf("Received string: %s", readbuffer);

    } else {
      /* Parent process closes up input side of pipe */
      close(io[0]);

      /* Send "string" through the output side of pipe */
      write(io[1], string, (strlen(string)+1));
    }

    return 0;
}
