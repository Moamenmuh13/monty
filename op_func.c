#include "monty.h"

/**
 * push_func_helper - Add new element to the stack
 * @num: number next to command
 * @line: Number of the line
 * @function: the function of the command
 */
void push_func_helper(char *num, unsigned int line, func function)
{
	int sign = 1, i, number;
	stack_t *node;

	if (num == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if (num[0] == '-')
	{
		num = num + 1;
		sign = -1;
	}
	for (i = 0; num[i] != '\0'; i++)
	{
		if (isdigit(num[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_stack();
			exit(EXIT_FAILURE);
		}
	}
	number = atoi(num);
	node = create_node(number * sign);
	function(&node, line);
}

/**
 * push_func - Add new element to the stack
 * @stack: Pointer to the new element
 * @line: Number of the line
 */
void push_func(stack_t **stack, unsigned int line)
{
	stack_t *stack_tmp;
	(void)line;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *stack;
		return;
	}
	stack_tmp = head;
	head = *stack;
	head->next = stack_tmp;
	stack_tmp->prev = head;
}

/**
 * pall_func - Print all element of the stack
 * @stack: Pointer to a pointer of the stack
 * @line: Number of the line
 */
void pall_func(stack_t **stack, unsigned int line)
{
	stack_t *stack_tmp;
	(void)line;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	stack_tmp = *stack;
	while (stack_tmp != NULL)
	{
		printf("%d\n", stack_tmp->n);
		stack_tmp = stack_tmp->next;
	}
}

/**
 * pint_func - prints the value at the top of the stack
 * @stack: pointer the curret node in the stack
 * @line: number of line
 */
void pint_func(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_from_stack - Remove an element from the stack
 * @stack: Pointer of the pointer of the stack
 * @line: Number of the line
 */
void pop_from_stack(stack_t **stack, unsigned int line)
{
	stack_t *stack_tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_stack();
		exit(EXIT_FAILURE);
	}

	stack_tmp = *stack;
	*stack = stack_tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(stack_tmp);
}
