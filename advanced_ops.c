#include "monty.h"
/**
 * pchar - prints the character at the top of the stack
 * @head: the top element of the stack
 * @line: the line number of the current command
 */
void pchar(stack_t **head, unsigned int line)
{
	int ascii;

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	ascii = (*head)->n;
	if (ascii >= 0 && ascii <= 127)
		printf("%c\n", ascii);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range,\n",
			line);
		exit(EXIT_FAILURE);
	}
}
