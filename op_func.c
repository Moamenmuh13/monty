#include "main.h"
/**
 * push_func - Add new element to the stack
 * @new_node: Pointer to the new element
 * @line: Number of the line
 */

void push_func(stack_t **stack, unsigned int line)
{
    stack_t *tmp;
    (void)line;
    
    if (stack == NULL || *stack == NULL)
        exit(EXIT_FAILURE);

    if (head == NULL)
    {
        head = *stack;
        return;
    }
    tmp = head;
    head = *stack;
    head->next = tmp;
    tmp->prev = head;
}

/**
 * pall_func - Print all element of the stack
 * @stack: Pointer to a pointer of the stack
 * @line: Number of the line
 */
void pall_func(stack_t **stack, unsigned int line)
{
    stack_t *tmp;
    (void)line;

    if (stack == NULL)
        exit(EXIT_FAILURE);

    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
/**
 * pop_from_stack - Remove an element from the stack
 * @stack: Pointer of the pointer of the stack
 * @line: Number of the line
 */
void pop_from_stack(stack_t **stack, unsigned int line)
{
    stack_t *tmp;
    (void)line;

    if (stack == NULL || *stack != NULL)
        /*handel error message*/

        tmp = *stack;
    *stack = tmp->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(tmp);
}
