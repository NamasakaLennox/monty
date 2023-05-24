#include "monty.h"

/**
 * pint - prints the top element of the stack
 * @head: the top element in the stack
 * @line: the line number of the current command
 */
void pint(stack_t **head, unsigned int line)
{
	/* if NULL address is provided */
	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	/* if the list is empty */
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	/* print top element */
	printf("%d\n", (*head)->n);
}
