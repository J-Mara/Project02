#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>

char *getCont(char* filename, char* m){
  int opfile = open(filename, O_RDONLY, 0);
  if(opfile == -1){
    printf("there has been an error: %s\n", strerror(errno));
    return("fail");
  }else{
    struct stat s;
    stat(filename, &s);
    int len = s.st_size;
    char res[len];
    char *p = res;
    p = m;
    read(opfile, p, len);
    close(opfile);
    //printf("contents of the file:\n%s\n", p);
    return p;
  }
}

int main(){
  struct stat s;
  stat("testfile.txt", &s);
  char *t;
  t = malloc(s.st_size);
  printf("here is the contents:\n%s\n", getCont("testfile.txt", t));
}
