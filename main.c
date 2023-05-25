#include "monty.h"

/**
 * main - the driver function of the program
 * @argc: the number of arguments provided
 * @argv: string of arguments provided
 *
 * Return: returns 0 on success
 */
int main(int argc, char **argv)
{
	FILE *f_open;
	char *line_read = NULL;
	size_t len = 0, line_number = 0;
	stack_t *head = NULL;

	/* if invalid number of arguments provided */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open file as read only */
	f_open = fopen(argv[1], "r");
	if (!f_open) /* if failed to open file */
	{
		/* prints file name entered */
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* read the file line by line */
	while (getline(&line_read, &len, f_open) != -1)
	{
		line_number++;
		/* if (line_read[0] != '#') */
		check_opcode(line_read, &head, line_number);
	}

	fclose(f_open);
	if (line_read)
		free(line_read);
	free_stack(&head);
	return (0);
}
