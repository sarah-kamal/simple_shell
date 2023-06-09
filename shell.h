#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
int printenv(char *arr);
int create_buff(char **);
void sighandler(int sig_num);
char* customstrtok(char *buff,char );
void putword(char *word);
int custom_fgetc(FILE *stream);
void stringcopy(char *dest, const char *src);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void stringcat(char *dest, const char *src);
int stringcompare(const char *str1, const char *str2);
int exitcode(char *arr, char *code);
void handle_error(char *fname, int linecount, int n);
void tostring(char str[], int num);
#endif
