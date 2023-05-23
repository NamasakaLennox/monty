#define _GNU_SOURCE
#include "monty.h"

int main(int argc, char **argv)
{
	FILE *f_open;
        char *line_read = NULL;
        size_t len = 0;
	ssize_t chars_read;

	/* remember to change errors to use strlen */
	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	f_open = fopen(argv[1], "r");
	if (!f_open)
	{
		/* remember to tokenize path and print file name */
		write(STDERR_FILENO, "Error: Can't open file <file>\n", 30);
		exit(EXIT_FAILURE);
	}
	while ((chars_read = getline(&line_read, &len, f_open)) != -1)
	{
		printf("%s", line_read);
	}

	fclose(f_open);
	if (line_read)
		free(line_read);

	return (0);
}

/* notes *
 * create separate functions for errors
 */
