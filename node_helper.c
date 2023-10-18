#include "monty.h"
/**
 * free_stack - free memory
 * Return: nothing in case of success
 */
void free_stack(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
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
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = number;
	return (node);
}
