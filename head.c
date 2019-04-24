#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int checkFilePath(char *path);
void imprime(char* s);
char** getArgs(char** args, char* entrada, int *size);
char **getRedirect(char **args, int size, int* redirectSize);
int checkRedirect(char **args, int size);
char** getArgsSemRedirect(char** args, char** args_sem_redirect, int size, int*args_sem_redirect_size);