#include <stdio.h>
#define N 20

int main()
{
    char rand_string[N];
    FILE *in = fopen("/dev/random", "r");
    FILE *out = fopen("ex1.txt", "w+");
    fread(rand_string, N, 1, in);

    for (int i = 0; i < 20; ++i) {
      fprintf(out, "%c", rand_string[i]);
    }

    fclose(in);
    fclose(out);
    return 0;
}
