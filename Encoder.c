#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main(){
  int opfile = open("testfile.txt", O_RDONLY, 0);
  if(opfile == -1){
    printf("there has been an error: %s\n", strerror(errno));
    return -1;
  }else{
    char res[500];
    char *p = &res[0];
    read(opfile, p, 500);
    printf("contents of the file:\n%s\n", res);
  }
}
