#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>

int main(){
  DIR * d;
  d = opendir("testDirIn");
  int result = 0;
  struct dirent *entry;
  entry = readdir( d );
  struct stat s;
  printf("Regular files: \n");
  d = opendir( "testDirIn" );
  entry = readdir( d );
  if(d){
    while ((entry = readdir(d)) != NULL){
      if(entry->d_type == DT_REG){
        stat(entry->d_name, &s);
	result += s.st_size;
	printf("%s\n", entry->d_name);	
      }
    }
  }
  closedir(d);
}
