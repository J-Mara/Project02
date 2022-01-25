#ifndef ENC_H
#define ENC_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ctype.h>

char *getCont(char* filename, char* m);

char *shiftUp(char* text, int shift);

char *shiftUpRead(char* text);

#endif
