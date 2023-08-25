#include "shell.h"

/**
 * executeCMD - Executes a command and waits for it to complete.
 * @args: The array of arguments for the command.
 * Return: The exit status of the executed command.
 */
int executeCMD(char **args)
{
	int childPid = fork();
	int status;

	if (childPid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
	}
	return (status);
}
