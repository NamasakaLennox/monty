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

/**
 * rotl - rotates the stack at the top
 * @head: the top of the stack
 * @line: the line number of current command
 * Description: the top element of the stack becomes the last element and the
 * second one becomes the new head
 */
void rotl(stack_t **head, unsigned int line)
{
	stack_t *temp = *head, *new_head;

	(void)line;
	if (!(*head))
		return;
	if ((*head)->next == NULL)
		return;

	new_head = (*head)->next;
	new_head->prev = NULL;

	/* find last element */
	while(temp->next)
		temp = temp->next;

	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	/* change head to previous second element */
	(*head) = new_head;
}

/**
 * rotr - rotates the stack to the bottom
 * @head: the top of the stack
 * @line: the current line number
 * Description: the last element of the stack becomes the top element
 */
void rotr(stack_t **head, unsigned int line)
{
	stack_t *temp;

	(void)line;
	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
		return;

	/* I'll try using push and pop if it fails */
	/* find last element */
	while(temp->next)
		temp = temp->next;
	/* make the list cyclic and split before the last element to rotate */
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	/* change head to new head */
	*head = temp;
}
