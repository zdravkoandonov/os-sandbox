#include <stdio.h>
#include <stdlib.h>

main() {
  printf("%i\n%i\n", getpid(), getppid());

  int result = fork();
  int status;
  if (result) {
    printf("wait returned: %i\n", wait(&status));
    printf("wait status: %i\n", WEXITSTATUS(status));
  }

  printf("fork: %i\n", result);

  printf("%i\n%i\n", getpid(), getppid());

  if (!result)
    exit(12);
}
