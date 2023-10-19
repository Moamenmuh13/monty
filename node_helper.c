#include "monty.h"

/**
 * free_stack - free memory
 * Return: nothing in case of success
 */
void free_stack(void)
{
	stack_t *temp;

	if (!head)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * create_node - create a new node
 * @number: the number inside the node
 * Return: new node
 */
stack_t *create_node(int number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		free(node);
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = number;
	return (node);
}
