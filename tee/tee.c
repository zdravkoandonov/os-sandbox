#include <stdio.h>
#include <fcntl.h>

main(int argc, char* argv[]) {
  int i;
  int files[20];
  for (i = 1; i < argc; ++i) {
    files[i-1] = open(argv[i], O_WRONLY|O_CREAT|O_TRUNC, 0644);
  }
  char buffer[100];
  int readBytes;
  while (readBytes = read(0, buffer, 100)) {
    for (i = 0; i < argc - 1; ++i) {
      write(files[i], buffer, readBytes);
    }
    write(1, buffer, readBytes);
  }

  for (i = 0; i < argc - 1; ++i) 
    close(files[i]);
  
}
