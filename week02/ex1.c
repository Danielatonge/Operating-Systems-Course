#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

  int ivar;
  float fvar;
  double dvar;

  ivar = INT_MAX;
  fvar = FLT_MAX;
  dvar = DBL_MAX;

  printf("Size of an INTEGER: %zu \t Largest value: %d\n", sizeof(ivar), ivar);
  printf("Size of a FLOAT: %zu \t Largest value: %g\n", sizeof(fvar), fvar);
  printf("Size of an DOUBLE: %zu \t Largest value: %g\n", sizeof(dvar), dvar);

  return 0;
}
