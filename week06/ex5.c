#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void hello(){
  signal(SIGTERM, hello);
  printf("Killing child process\n");
}

int main(){

  pid_t cpid;
  pid_t ppid;

  //set handler for SIGTERM to hello()
  signal(SIGTERM, hello);
  cpid = fork();

  if (cpid == 0){

    while(1) {
      printf("I'm alive\n");
      sleep(1);
    }

  } else {
    /*PARENT*/
    printf("cpid %d\n", cpid);
    sleep(10);
    //just wait for child to terminate

    //send SIGTERM signal to CHILD
    kill(cpid, SIGTERM);
    exit(0);
  }

}
