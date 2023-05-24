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

/**
 * pop - removes the top element in the list
 * @head: the top element in the list
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
	if (temp->next == NULL)
	{
		*head = NULL;
		free(temp);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
	}
}

/**
 * swap - swaps the top two items on the stack
 * @head: the first element in the list
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
