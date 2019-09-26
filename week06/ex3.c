#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void signal_handler(int);

int main(void)
{
   signal(SIGINT, signal_handler);
   while (1)
        sleep(1);
   return 0;
}

void  signal_handler(int sig)
{
   char  c;
   signal(sig, SIG_IGN);
   printf("\nHey, You pressed Ctrl+C. Do you really want to quit? [y/n] ");
   c = getchar();
   if (c == 'y' || c == 'Y')
        exit(0);
   else
        signal(SIGINT, signal_handler);
   getchar();
}
