#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {
char *data;
int bytes = 1024 * 1024;

struct rusage buf;

  for(int i=0; i<10; i++){
    data = (char *) malloc( 10 * bytes);
    memset(data, 0, 10 * bytes);

    getrusage(RUSAGE_SELF, &buf);
    printf("user CPU time used: %ld\n", buf.ru_utime.tv_sec);
    printf("system CPU time used: %ld\n", buf.ru_stime.tv_sec);
    printf("maximum resident set size: %ld\n", buf.ru_maxrss);
    printf("integral shared memory size: %ld\n", buf.ru_ixrss);
    printf("integral unshared data size: %ld\n", buf.ru_idrss);
    printf("integral unshared stack size: %ld\n", buf.ru_isrss);
    printf("page reclaims (soft page faults): %ld\n", buf.ru_minflt);
    printf("page faults (hard page faults): %ld\n", buf.ru_majflt);
    printf("swaps: %ld\n", buf.ru_nswap);
    printf("block input operations: %ld\n", buf.ru_inblock);
    printf("block output operations: %ld\n", buf.ru_oublock);
    printf("IPC messages sent: %ld\n", buf.ru_msgsnd);
    printf("IPC messages received: %ld\n", buf.ru_msgrcv);
    printf("signals received: %ld\n", buf.ru_nsignals);
    printf("voluntary context switches: %ld\n", buf.ru_nvcsw);
    printf("involuntary context switches: %ld\n", buf.ru_nivcsw);
    printf("\n\n");

    sleep(1);
  }

free(data);
return 0;
}
