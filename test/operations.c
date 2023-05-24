#include "monty.h"

/* haven't handled errors yet */
/* edit functions to comply with prototype */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	if (!head)
		return;
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return;

	new->n = n;
	if (*head)
		(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

void pall(const stack_t *head, unsigned int line_number)
{
	stack_t *temp = (stack_t *)head;

	(void)line_number;
	if (head == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void pint(const stack_t *head, unsigned int line_number)
{
	(void)line_number;
	if (head == NULL)
	{
		/* print error */
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

void pop(const stack_t *head, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
        if (head == NULL)
        {
                /* print error */
                exit(EXIT_FAILURE);
        }
        temp = head;
	head = head->next;
	free(temp);
}
