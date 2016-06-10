#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX 20

main(int argc, char **argv) {
  int files[MAX];
  int i;
  for (i = 2; i < argc; ++i)
    files[i-2] = open(argv[i], O_RDONLY);
  int occurences[MAX] = { 0 };
  char c;
  for (i = 0; i < argc - 2; ++i) {
    while (read(files[i], &c, 1))
      occurences[i] += (c == argv[1][0]);
    printf("%i\n", occurences[i]);
  }
  for (i = 0; i < argc - 2; ++i) 
    close(files[i]);
}
