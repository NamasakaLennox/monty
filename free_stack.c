#include "monty.h"

/**
 * free_stack - frees a stack
 * @head: first element in the list
 */
void free_stack(stack_t **head)
{
	stack_t *temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
