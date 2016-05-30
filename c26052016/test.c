#include <stdio.h>

main() {
  int i = -1;
  if (fork()) {
    i = 0;
    int j = 10000;
    while (j--) {
      printf("parent");
    }
  }
  else {
    i = 1;
    int j = 10000;
    while (j--)
      printf("child");
  }
  int k = 10000;
  while (k--) {
    if (i)
      printf("endchild");
    else
      printf("endparent");
  }
}

