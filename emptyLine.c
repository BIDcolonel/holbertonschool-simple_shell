#include "shell.h"

/**
 * isWhitespace - Checks if a character is a whitespace character.
 * @c: The character to be checked.
 * Return: 1 if the character is a whitespace character, 0 otherwise.
 */
int isWhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

/**
 * emptyLine - Checks if a string contains only whitespace characters.
 * @buff: The string to be checked.
 * Return: 1 if the string contains only whitespace characters, 0 otherwise.
 */
int emptyLine(char *buff)
{
	int index;

	for (index = 0; buff[index] != '\0'; index++)
	{
		if (!isWhitespace(buff[index]))
		{
			return (0);
		}
	}
	return (1);
}
