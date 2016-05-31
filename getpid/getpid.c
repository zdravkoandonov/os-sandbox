#include <stdio.h>

main() {
  printf("Current proccess id is %i\n", getpid());
  printf("Parent process id is %i\n", getppid());

  execlp("ps", "ps", NULL);
  
}
