#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include "Encoder.h"

int main(){
  char* DirName = "testDirIn";
  DIR * d;
  d = opendir(DirName);
  int result = 0;
  struct dirent *entry;
  entry = readdir( d );
  struct stat s;
  printf("Regular files: \n");
  if(d){
    while ((entry = readdir(d)) != NULL){
      if(entry->d_type == DT_REG){
        stat(entry->d_name, &s);
	result += s.st_size;
	printf("%s\n", entry->d_name);
	char *t;
	t = malloc(sizeof(DirName) + sizeof('/') + sizeof(entry->d_name));
	//char *path[sizeof(DirName) + sizeof('/') + sizeof(entry->d_name)];
	strcpy(t, DirName);
	strcat(t, "/");
	strcat(t, entry->d_name);
	printf("here is the path: %s\n", t);
	struct stat s;
	stat(t, &s);
	char *m;
	m = malloc(s.st_size);
	char *text = getCont(t,m);
	printf("here is the contents:\n%s\n", text);
	printf("Shift attempt:\n%s\n", shiftUpRead(text));
	free(t);
      }
    }
  }
  closedir(d);
}
