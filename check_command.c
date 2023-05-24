#include "monty.h"

/**
 * check_opcode - check if command is valid
 * @line_read: the line read from the file
 * @head: the first element in the list
 * @line: the line number of the current command
 * Description: checks for a command a performs necessary operation based on
 * the called function
 */
void check_opcode(char *line_read, stack_t **head, unsigned int line)
{
	char **command;
	instruction_t op[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", division}, {"mul", mul}, {"mod", mod}, {NULL, NULL}
	};
	int i = 0, j, flag = 0, len1, len2;

	/* split the command */
	command = split_token(line_read);
	while (command[i]) /* check for operation */
	{
		j = 0;
		while (op[j].opcode)
		{
			len1 = strlen(op[j].opcode);
			len2 = strlen(command[i]);
			if (strncmp(op[j].opcode, command[i], len1) == 0 &&
			    strncmp(op[j].opcode, command[i], len2) == 0)
			{
				flag = 1;
				if (j == 0) /* command is push */
					push_check(head, command, line);
				else
					op[j].f(head, line);
				break;
			}
			j++;
		}
		if (flag == 0) /* if command was not found */
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line,
				command[i]);
			free(command);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free(command);
}
