#include "shell.h"

/**
 * concatenatePathAndCommand - Concatenates a path and a command.
 * @path: The base path.
 * @command: The command to concatenate.
 * Return: New allocated string containing the concatenated path and command.
 */
char *concatenatePathAndCommand(const char *path, const char *command)
{
	int pathLength = strlen(path);
	int commandLength = strlen(command);
	int bufferSize = pathLength + commandLength + 2;

	char *result = malloc(bufferSize);

	if (!result)
	{
		perror("Memory allocation error");
		exit(1);
	}

	strcpy(result, path);
	if (result[pathLength - 1] != '/')
	{
		strcat(result, "/");
	}
	strcat(result, command);

	return (result);
}

/**
 * findPathInShell - Finds the full path of a command in the shell's PATH.
 * @command: The command to search for.
 * Return: The full path of the command if found, NULL otherwise.
 */
char *findPathInShell(char *command)
{
	char *path = getenv("PATH");
	char *pathCopy = strdup(path);
	char *pathToken;
	struct stat info;

	if (stat(command, &info) == 0)
	{
		free(pathCopy);
		return (strdup(command));
	}

	pathToken = strtok(pathCopy, ":");
	while (pathToken)
	{
		char *pathConcatenate = concatenatePathAndCommand(pathToken, command);

		if (stat(pathConcatenate, &info) == 0)
		{
			free(pathCopy);
			return (pathConcatenate);
		}
		free(pathConcatenate);
		pathToken = strtok(NULL, ":");
	}
	free(pathCopy);
	return (NULL);
}
