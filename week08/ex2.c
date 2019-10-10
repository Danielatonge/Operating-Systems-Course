#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
char *data;
int bytes = 1024 * 1024;

  for(int i=0; i<10; i++){
    data = (char *) malloc( 10 * bytes);
    memset(data, 0, 10 * bytes);
    sleep(1);
  }
  
free(data);
return 0;
}
