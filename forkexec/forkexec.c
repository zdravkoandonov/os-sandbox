#include <stdio.h>
#include <stdlib.h>

main() {
  printf("pid: %i\nppid: %i\n", getpid(), getppid());

  int forkret = fork();
  if (forkret) {
    printf("parentforkret: %i, pid: %i, ppid: %i\n", forkret, getpid(), getppid());
    int status;
    int pid = wait(&status);
    printf("child pid: %i\n", pid);
    if (WIFEXITED(status))
      printf("child return status: %i\n", WEXITSTATUS(status));
  }
  else {
    printf("%i\n", forkret);
    printf("%i\n", getpid());
    printf("%i\n", getppid());
    printf("childforkret: %i, pid: %i, ppid: %i", forkret, getpid(), getppid());
    execlp("grep", "grep", NULL);
  }

}
