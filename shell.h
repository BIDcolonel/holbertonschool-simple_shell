#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int isWhitespace(char c);
int emptyLine(char *buff);

int executeCMD(char **args);

char *concatenatePathAndCommand(const char *path, const char *command);
char *findPathInShell(char *command);

char **tokenizeInput(char *inputLine, size_t *argCount);
void handleCdCommand(char **args);
void executeExternalCommand(char **args);

#define MAX_ARGS 100

extern char **environ;

#endif
