#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main() {

  struct stat test;

  stat("testfile.txt",&test);

  printf("Showing stats of <testfile.txt>\n");
  printf("Size: %ld\n",test.st_size);
  printf("Permissions: %ud\n",test.st_mode);
  printf("Access time: %s\n",ctime(&test.st_atime));

  return 0;
}
