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
void termenate(char **string);
void create_buff(char **buffer);
void divide_buffer(char **words, char *buffer, char p);
void c_strcpy(char *source, char **dest, int c);
void terminatewnull(char **words);
int interactive(char **);
void handleslash(char **);
int ifexit(char *str);
int ifcommandexsist(char *cmd);
void freeo(char **, char **);
#endif
