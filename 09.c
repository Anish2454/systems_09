#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void printSize(char* path){
  DIR * d = opendir(path);
  struct dirent* entry = readdir(d);
  int total = 0;
  while(entry){
    if(entry -> d_type == DT_REG){
      struct stat data;
      stat(entry -> d_name, &data);
      size_t size = data.st_size;
      total += size;
    }
    entry = readdir(d);
  }
  printf("\nTotal Size: %d Bytes\n", total);
  closedir(d);
}

void printDirectories(char* path){
  DIR * d = opendir(path);
  printf("\nDirectories: \n");
  struct dirent* entry = readdir(d);
  while(entry){
    if(entry -> d_type == DT_DIR){
      printf("\t%s\n", entry -> d_name);
    }
    entry = readdir(d);
  }
  closedir(d);
}

void printFiles(char* path){
  DIR * d = opendir(path);
  printf("\nRegular Files: \n");
  struct dirent* entry = readdir(d);
  while(entry){
    if(entry -> d_type == DT_REG){
      printf("\t%s\n", entry -> d_name);
    }
    entry = readdir(d);
  }
  closedir(d);
}

int main(){
  char* path = ".";
  printSize(path);
  printDirectories(path);
  printFiles(path);
  printf("\n");
}
