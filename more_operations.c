#include "monty.h"

/**
 * sub - subtracts the top two elements on a stack
 * @head: the top element on the stack
 * @line: the current line of the command in the file
 * Description: the result is stored in the second element and the top element
 * is removed
 */
void sub(stack_t **head, unsigned int line)
{
	unsigned int diff;

	/* if list is empty */
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	/* only one item in list */
	if ((*head)->next == NULL && (*head)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	diff = (*head)->next->n - (*head)->n;

	pop(head, line);
	pop(head, line);
	push(head, diff);
}

/**
 * div - divides the top two elements on a stack
 * @head: the top element on the stack
 * @line: the line number of the current command
 * Description: the result is stored in the second element and the top element
 * is removed
 */
void div(stack_t **head, unsigned int line)
{
	/* if list is empty */
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	/* only one item in list */
	if ((*head)->next == NULL && (*head)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
}

void mul(stack_t **head, unsigned int line)
{}

void mod(stack_t **head, unsigned int line)
{}
