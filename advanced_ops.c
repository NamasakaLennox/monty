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
		/* need to free command */
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	ascii = (*head)->n;
	if (ascii >= 0 && ascii <= 127)
		printf("%c\n", ascii);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range,\n",
			line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting from top of stack
 * @head: the top element of the stack
 * @line: the line number of the current command
 */
void pstr(stack_t **head, unsigned int line)
{
	stack_t *temp;

	(void)line;

	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
