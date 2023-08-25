#include "shell.h"

/**
 * readInput - Lit une ligne d'entrée depuis stdin.
 * Return: La ligne lue.
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
