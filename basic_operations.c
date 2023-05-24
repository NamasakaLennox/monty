#include "monty.h"

/**
 * pint - prints the top element of the stack
 * @head: the top element on the stack
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

/**
 * pop - removes the top element in the list
 * @head: the top element on the stack
 * @line: the current line of the current command
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *temp;

	temp = *head;
	if (!temp) /* if the list is empty */
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	/* if only one element present */

	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two items on the stack
 * @head: the top element on the stack
 * @line: the line which the error occured
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *new1_next, *new2_prev, *new2_next;

	/* if list is empty */
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	/* only one item in list */
	if ((*head)->next == NULL && (*head)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	/* swapping the top two items */
	new1_next = *head;
	new2_prev = (*head)->next;
	new2_next = (*head)->next->next;

	*head = new2_prev;
	(*head)->prev = NULL;
	(*head)->next = new1_next;
	(*head)->next->prev = *head;
	(*head)->next->next = new2_next;
}

/**
 * add - adds the top two elements on the stack
 * @head: the top element on the stack
 * @line: the line containing the current command
 * Description: the result is stored in the second element of the stack and the
 * top element is removed
 */
void add(stack_t **head, unsigned int line)
{
	unsigned int sum;

	/* if list is empty */
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	/* only one item in list */
	if ((*head)->next == NULL && (*head)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	sum = (*head)->n + (*head)->next->n;

	pop(head, line);
	pop(head, line);
	push(head, sum);
}

/**
 * nop - does not do anything
 * @head: the top element on the stack
 * @line: the current line with command
 */
void nop(stack_t **head, unsigned int line)
{
	head = head;
	line = line;
}
