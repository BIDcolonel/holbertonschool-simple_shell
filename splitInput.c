#include "shell.h"

/**
 * splitInput - Splits a line into arguments.
 * @inputLine: The line to split.
 * @argCount: Pointer to the variable that will store the number of arguments.
 * Return: An array of arguments.
 */
char **splitInput(char *inputLine, int *argCount)
{
	char *token;
	char **args;
	int argIndex = 0;

	args = (char **)malloc(MAX_ARGS * sizeof(char *));
	if (args == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}

	token = strtok(inputLine, " ");
	while (token != NULL)
	{
		args[argIndex] = token;
		argIndex++;
		token = strtok(NULL, " ");
	}
	args[argIndex] = NULL;

	*argCount = argIndex;
	return (args);
}
