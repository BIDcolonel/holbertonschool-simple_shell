#include "shell.h"

/**
 * readInput - Reads an input line from stdin.
 * Return: The line read
 */
char *readInput(void)
{
	char *inputLine = NULL;
	size_t inputSize = 0;
	ssize_t lineSize = getline(&inputLine, &inputSize, stdin);

	if (lineSize == -1)
	{
		free(inputLine);
		return (NULL);
	}

	inputLine[lineSize - 1] = '\0';
	return (inputLine);
}
