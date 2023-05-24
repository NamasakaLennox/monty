#include "monty.h"

/**
 * push - pushes an element to the top of the stack
 * @head: the top element of the list
 * @num: the number to add to the stack
 */
void push(stack_t **head, unsigned int num)
{
	stack_t *new;

	/* allocate memory space for the new element */
	new = malloc(sizeof(stack_t));
	if (!new) /* if malloc fails */
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->prev = NULL;
	new->next = *head;
	if (*head) /* element is not the first in list */
		(*head)->prev = new;
	*head = new;
}

/**
 * push_check - checks if the number to push is a valid integer
 * @head: the top element in the stack
 * @command: the tokenized command of the push command
 * @line: the line of the current command
 */
void push_check(stack_t **head, char **command, unsigned int line)
{
	int i = 0;
	char *check;

	/* if no integer is provided */
	if (command[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free(command);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	check = command[1];
	while (check[i]) /* check if the number is a valid integer */
	{
		if (i == 0 && check[i] == '-')
			i++;
		if (_isdigit(check[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free(command);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	push(head, atoi(check));
}

/**
 * pall - prints all elements in the list
 * @head: the top element in the list
 * @line: the line number of the current command
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *temp;

	(void)line;

	temp = *head;
	if (!temp)
		return;
	/* print elements */
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _isdigit - check if the number provided is a digit
 * @c: the digit provided
 *
 * Return: returns 1 on success, 0 on failure
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
