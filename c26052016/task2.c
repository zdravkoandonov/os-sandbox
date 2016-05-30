#include <stdio.h>

main() {
  int i = 0;
  if (fork()) {
    wait();
    i++;
    printf("i=%d\n", i);
  }
  else {
    ++i;
    printf("i=%d\n", i);
  }
  i--;
  printf("i=%d\n", i);
}
