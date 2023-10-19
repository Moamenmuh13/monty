#include "monty.h"
/**
 * div_func - add two numbers in stack
 * @stack: pointer the curret node in the stack
 * @line: number of line
 */
void div_func(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if ((*stack)->prev->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_func - add two numbers in stack
 * @stack: pointer the curret node in the stack
 * @line: number of line
 */
void mul_func(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_func - add two numbers in stack
 * @stack: pointer the curret node in the stack
 * @line: number of line
 */
void mod_func(stack_t **stack, unsigned int line)
{
	int result = 0;

	if (!stack || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if ((*stack)->prev->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
