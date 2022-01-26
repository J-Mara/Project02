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

int main(int argc, char *argv[]){
  if (argc != 5) {
    printf("usage: make run ARGS=\"inputDir outputDir numProcs encode_decode\"\n");
    return -1;
  }
  int upDown = strtol(argv[4], NULL, 0);
  char* DirOutName = argv[2];
  char* DirName = argv[1];
  printf("input: %s\n", DirName);
  int forksOrig = strtol(argv[3], NULL, 0);
  
  if ((forksOrig < 1) || (forksOrig > 128)) {
    printf("number of proesses is unreasonable!\n");
    exit(-1);
  }
  int forks = forksOrig;
  int i = -1;
  int ID = -1;
  while ((ID != 0) && (forks > 1)) {
    ID = fork();  // return 0 for child, pid for parent.
    i++;
    if ( (ID != 0) && (forks == 2) ) { // at last round increase i for parent.
      i++;
    }
    // printf("forking %d\n", i);
    forks--;
  }
  DIR * d;
  d = opendir(DirName);
  int result = 0;
  struct dirent *entry;
  entry = readdir( d );
  printf("forked %d\n", i);
  struct stat s;
  //printf("Regular files: \n");
  int counter = -1;
  if(d){
    while ((entry = readdir(d)) != NULL){
      counter++;
      //printf("upping counter");
      if(entry->d_type == DT_REG && (counter%forksOrig == i)){
        stat(entry->d_name, &s);
	result += s.st_size;
	//printf("%s\n", entry->d_name);
	char *t;
	t = malloc(sizeof(DirName) + sizeof('/') + sizeof(entry->d_name));
	strcpy(t, DirName);
	strcat(t, "/");
	strcat(t, entry->d_name);
	//printf("here is the path: %s\n", t);
	struct stat s;
	stat(t, &s);
	char *m;
	m = malloc(s.st_size);
	char *text = getCont(t,m);
	//printf("here is the contents:\n%s\n", text);
	//printf("Shift attempt:\n%s\n", shiftUpRead(text));
	char *t2 = malloc(sizeof(DirOutName) + sizeof('/') + sizeof(entry->d_name));
	strcpy(t2, DirOutName);
	strcat(t2, "/");
	strcat(t2, entry->d_name);
	FILE *fp;
	fp = fopen(t2, "w");
	if(upDown == 0){
	  fputs(shiftUpRead(text), fp);
	}else{
	  fputs(shiftDownRead(text), fp);
	}
	free(t2);
	free(t);
      }
    }
  }
  closedir(d);
}
