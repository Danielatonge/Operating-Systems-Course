#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int     io[2], infobytes;
    char    string[] = "Innopolis University";
    char    readbuffer[60];

    if (pipe(io) < 0)
    exit(1);

    /* Send "string" through the output side of pipe */
    write(io[1], string, (strlen(string)+1));
    
    /* Read in a string from the pipe */
    infobytes = read(io[0], readbuffer, sizeof(readbuffer));
    printf("Operation successful. Received string: %s", readbuffer);
    printf("\n");

    return 0;
}
