#include "shell.h"

/**
 * tokenizeInput - Tokenizes the input line into arguments.
 * @inputLine: The input line to tokenize.
 * @argCount: A pointer to store the number of arguments.
 * Return: An array of pointers to the arguments.
 */
char **tokenizeInput(char *inputLine, size_t *argCount)
{
	char **args = (char **)malloc(sizeof(char *));
	char *token;
	size_t argIndex;

	if (!args)
	{
		perror("Memory allocation error");
		exit(1);
	}

	token = strtok(inputLine, " ");
	argIndex = 0;

	while (token != NULL)
	{
		args[argIndex] = token;
		argIndex++;
		args = (char **)realloc(args, (argIndex + 1) * sizeof(char *));
		if (!args)
		{
			perror("Memory allocation error");
			exit(1);
		}
		token = strtok(NULL, " ");
	}
	args[argIndex] = NULL;
	*argCount = argIndex;

	return (args);
}

/**
 * handleCdCommand - Handles the "cd" command.
 * @args: The arguments passed to the "cd" command.
 */
void handleCdCommand(char **args)
{
	if (args[1] != NULL)
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}

/**
 * executeExternalCommand - Executes external commands.
 * @args: The arguments passed to the command.
 */
void executeExternalCommand(char **args)
{
	char *cmdPath = findPathInShell(args[0]);

	if (cmdPath != NULL)
	{
		pid_t childPid = fork();

		if (childPid == 0)
		{
			execve(cmdPath, args, environ);
			perror("execve");
			exit(1);
		}
		else
		{
			int exit_status;

			wait(&exit_status);
		}

		free(cmdPath);
	}
	else
	{
		printf("Command not found: %s\n", args[0]);
	}
}

/**
 * main - The main function of the shell program.
 * Return: The exit status of the shell.
 */
int main(void)
{
	char *inputLine = NULL;
	size_t inputSize = 0;
	ssize_t lineSize = 0;
	size_t argCount;
	int exit_status = 0;
	char **args;

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		lineSize = getline(&inputLine, &inputSize, stdin);
		if (lineSize == -1 || strcmp("exit\n", inputLine) == 0)
		{
			free(inputLine);
			break;
		}
		inputLine[lineSize - 1] = '\0';

		if (emptyLine(inputLine))
		{
			exit_status = 0;
			continue;
		}

		args = tokenizeInput(inputLine, &argCount);

		if (strcmp(args[0], "cd") == 0)
		{
			handleCdCommand(args);
		}
		else
		{
			executeExternalCommand(args);
		}
		free(args);
	}
	return (exit_status);
}
