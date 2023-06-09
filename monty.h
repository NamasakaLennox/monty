#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


/* structs to use */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* operation function prototypes */
void check_opcode(char *line_read, stack_t **head, unsigned int line);
void push(stack_t **head, unsigned int num);
void push_check(stack_t **head, char **command, unsigned int line);
void pall(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);
void swap(stack_t **head, unsigned int line);
void add(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);

/* advanced tasks operations */
void sub(stack_t **head, unsigned int line);
void division(stack_t **head, unsigned int line);
void mul(stack_t **head, unsigned int line);
void mod(stack_t **head, unsigned int line);
void pchar(stack_t **head, unsigned int line);
void pstr(stack_t **head, unsigned int line);
void rotl(stack_t **head, unsigned int line);
void rotr(stack_t **head, unsigned int line);

/* other functions */
int _isdigit(int c);
void free_stack(stack_t **head);
char **split_token(char *line_read);

#endif
