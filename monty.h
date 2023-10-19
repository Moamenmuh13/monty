#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*func)(stack_t **, unsigned int);

/* file functions */
void excute_file(FILE *fd);
void find_func(char *command, char *num, int line);
void excute_func(char *command, func function, char *num, unsigned int line);
void free_stack(void);
stack_t *create_node(int number);

/* opcode functions */
void push_func(stack_t **stack, unsigned int line);
void push_func_helper(char *num, unsigned int line, func function);
void pall_func(stack_t **stack, unsigned int line);
void pint_func(stack_t **stack, unsigned int line);
void pop_from_stack(stack_t **stack, unsigned int line);
void nop_func(stack_t **stack, unsigned int line);
void add_func(stack_t **stack, unsigned int line);
void sub_func(stack_t **stack, unsigned int line);
void swap_func(stack_t **stack, unsigned int line);
void div_func(stack_t **stack, unsigned int line);
void mul_func(stack_t **stack, unsigned int line);
void mod_func(stack_t **stack, unsigned int line);
void pchar_func(stack_t **stack, unsigned int line);
void pstr_func(stack_t **stack, unsigned int line);

#endif
