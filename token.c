#include "monty.h"

/**
 * split_token - splits a token into separate command arguments
 * @line_read: the current line containing the command to perform
 *
 * Return: returns the split command
 */
char **split_token(char *line_read)
{
	char **command, *token;
	char *delim = " \t\n";
	int i = 0;

	/* allocate memory for commands */
	command = malloc(sizeof(char *) * 3);
	if (!command) /* allocation failed */
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line_read);
		exit(EXIT_FAILURE);
	}

	/* split the current line into commands */
	token = strtok(line_read, delim);
	while (token && i < 2)
	{
		command[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	command[i] = NULL;

	return (command);
}
