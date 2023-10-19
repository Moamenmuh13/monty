#include "monty.h"

/**
 * nop_func - Remove an element from the stack
 * @stack: Pointer of the pointer of the stack
 * @line: Number of the line
 */
void nop_func(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * add_func - add two numbers in stack
 * @stack: pointer the curret node in the stack
 * @line: number of line
 */
void add_func(stack_t **stack, unsigned int line)
{
	int sum = 0;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * swap_func - swap two elements from the stack
 * @stack: pointer the curret node in the stack
 * @line: number of line
 */
void swap_func(stack_t **stack, unsigned int line)
{
	stack_t *stack_tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);

	}

	stack_tmp = (*stack)->next;
	(*stack)->next = stack_tmp->next;

	if (stack_tmp->next != NULL)
		stack_tmp->next->prev = *stack;

	stack_tmp->next = *stack;
	(*stack)->prev = stack_tmp;
	stack_tmp->prev = NULL;
	*stack = stack_tmp;
}
