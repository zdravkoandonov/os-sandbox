#include <stdio.h>

main() {
  if (!fork()) {
    execlp("ls", "ls", NULL);
  }
  wait();
  printf("ending");
}
