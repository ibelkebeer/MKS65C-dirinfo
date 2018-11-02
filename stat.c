#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>

int main(){
  DIR* d;
  d = opendir("dir");
  struct dirent* entry;
  int i = 0;
  while(entry = readdir(d) && entry -> d_type == 4){
    printf("%s\n", entry -> d_name);
    i++;
  }
  //char[256] dirs[i];
  i = 0;
  printf("_______________________");
  if(entry){
   printf("%s\n", entry -> d_name);
   i++;
  }
  while(entry = readdir(d)){
   printf("%s\n", entry -> d_name);
   i++;
  }
  closedir(d);
  //d = opendir("dir");
  //char
  return 0;
}
