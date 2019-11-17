#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int main(){
  DIR * dir = opendir("./");
  if(errno){
    printf("%d: %s\n", errno, strerror(errno));
  }
  printf("Statistics for directory: .\n");
  struct dirent * file = readdir(dir);
  if(errno){
    printf("%d: %s\n", errno, strerror(errno));
  }
  struct stat buff;
  int size = 0;
  while (file != NULL){
    stat(file->d_name, &buff);
    size += buff.st_size;
    file = readdir(dir);
  }
  printf("Total Directory Size: %d Bytes\n", size);
  rewinddir(dir);
  file = readdir(dir);
  printf("Directories: \n");
  while (file != NULL){
    if (file->d_type == DT_DIR){
      printf("\t%s\n", file->d_name);
    }
    file = readdir(dir);
  }
  rewinddir(dir);
  file = readdir(dir);
  printf("Regular Files: \n");
  while (file != NULL){
    if (file->d_type == DT_REG){
      printf("\t%s\n", file->d_name);
    }
    file = readdir(dir);
  }
  return 0;
}
