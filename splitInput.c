#include "shell.h"

/**
 * splitInput - Découpe une ligne en arguments.
 * @inputLine: La ligne à découper.
 * @argCount: Pointeur vers la variable qui stockera le nombre d'arguments
 * Return: Un tableau d'arguments.
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
