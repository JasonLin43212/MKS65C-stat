#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

  struct stat test;

  stat("testfile.txt",&test);

  printf("Showing stats of <testfile.txt>");
  printf("Size: %d",test.st_size);
  printf("Permissions: %ld",test.st_mode);
  printf("Access time: %ld",test.st_atime);
  

  return 0;
}
