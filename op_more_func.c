#include "monty.h"
/**
 * add_func - add two numbers in stack
 * @stack: pointer the curret node in the stack
 * @line: number of line
*/
void add_func(stack_t **stack, unsigned int line)
{
	int sum = 0;

	if (!stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_func - sub two numbers in stack
 * @stack: pointer the curret node in the stack
 * @line: number of line
*/
void sub_func(stack_t **stack, unsigned int line)
{
	int sub = 0;

	if (!stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
