#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

void to_rwx(char * permissions, char * output) {
  int i;
  strcat(output,"-");
  for (i=0; i<3; i++){
    char cur = *permissions;
    if (cur == '1') {
      strcat(output,"--x");
    }
    if (cur == '2') {
      strcat(output,"-w-");
    }
    if (cur == '3') {
      strcat(output,"-wx");
    }
    if (cur == '4') {
      strcat(output,"r--");
    }
    if (cur == '5') {
      strcat(output,"r-x");
    }
    if (cur == '6') {
      strcat(output,"rw-");
    }
    if (cur == '7') {
      strcat(output,"rwx");
    }
    permissions++;
  }
}

void print_stats(char * filename){
  struct stat test;
  stat(filename,&test);
  printf("Showing stats of <%s>\n========================\n",filename);
  printf("Size: %ld\n",test.st_size);

  char buffboi[50];
  int byte = test.st_size;
  int kb = byte / 1000;
  int mb = kb / 1000;
  int gb = mb / 1000;
  sprintf(buffboi,"In bytes: %d \nIn KB: %d \nIn MB: %d \nIn GB: %d",byte,kb,mb,gb);
  printf("%s\n",buffboi);

  printf("Permission: %u\n",test.st_mode);

  char rwx[3];
  char output[10];
  sprintf(rwx,"%o",test.st_mode&0b111111111);
  to_rwx(rwx,output);
  printf("Access time: %s",ctime(&test.st_atime));
  printf("Printing permission in ls -l format:\n");
  printf("%s\n\n",output);
}

int main() {
  print_stats("testfile.txt");
  print_stats("table.jpg");
  print_stats("video.mp4");
  return 0;
}
