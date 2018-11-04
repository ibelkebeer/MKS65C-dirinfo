#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

int main(){
  DIR* d;
  d = opendir("dir");
  struct dirent* entry;
  int i = 0;
  while((entry = readdir(d))){
    i++;
  }
  closedir(d);
  struct dirent* entries[i + 1];
  entries[i] = 0;
  d = opendir("dir");
  i = 0;
  while((entry = readdir(d))){
    entries[i] = entry;
    i++;
  }
  printf("\nStatistics for directory: %s\n", entries[0] -> d_name);
  printf("Total directory size: %d Bytes\n", entries[0] -> d_reclen);
  printf("\nDirectories:\n");
  i = 0;
  while(entries[i]){
    if(entries[i] -> d_type == 4){
      printf("%s\n", entries[i] -> d_name);
    }
    i++;
  }
  printf("\nRegular Files:\n");
  i = 0;
  while(entries[i]){
    if(entries[i] -> d_type != 4){
      printf("%s\n", entries[i] -> d_name);
    }
    i++;
  }
  printf("\n");
  closedir(d);
  return 0;
}
