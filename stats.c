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
  char buffboi[50];
  int byte = test.st_size;
  int kb = byte / 1000;
  int mb = kb / 1000;
  int gb = mb / 1000;
  sprintf(buffboi,"In bytes: %d \nIn KB: %d \nIn MB: %d \nIn GB: %d",byte,kb,mb,gb);
  printf("%s\n",buffboi);



  printf("Permissions: %ud \n",test.st_mode);
  printf("Access time: %s\n",ctime(&test.st_atime));

  return 0;
}
