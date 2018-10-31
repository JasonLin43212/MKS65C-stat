#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

void print_bit(char c){
  int i;
  for (i=0; i<8; i++){
    printf("%d",c&1);
    c >>= 1;
  }
  printf("\n");
}

int main() {

  struct stat test;

  //stat("testfile.txt",&test);
  stat("table.jpg",&test);
  printf("Showing stats of <table.jpg>\n========================\n");
  printf("Size: %ld\n",test.st_size);

  char buffboi[50];
  int byte = test.st_size;
  int kb = byte / 1000;
  int mb = kb / 1000;
  int gb = mb / 1000;
  sprintf(buffboi,"In bytes: %d \nIn KB: %d \nIn MB: %d \nIn GB: %d",byte,kb,mb,gb);
  printf("%s\n",buffboi);

  printf("Permission: %u\n",test.st_mode);
  /*
  char * permission = &test.st_mode;
  printf("\n%p\n",permission);
  print_bit(*permission);
  permission += 1;
  printf("\n%p\n",permission);
  print_bit(*permission);
  permission += 1;
  printf("\n%p\n",permission);
  print_bit(*permission);
  permission += 1;
  printf("\n%p\n",permission);
  print_bit(*permission);
  permission += 1;
  printf("\n%p\n",permission);
  print_bit(*permission);
  
  int * permission = &test.st_mode;
  permission += 2;
  print_bit(*permission);
  permission++;
  printf("\n");
  print_bit(*permission);
  */
  printf("Access time: %s\n",ctime(&test.st_atime));

  return 0;
}
