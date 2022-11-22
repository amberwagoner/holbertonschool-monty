#include "monty.h"

/**
* free_stack - frees the stack
* @stack: stack to be freed
* Return: void
*/

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *freenode;

	while (current)
	{
		freenode = current;
		current = current->prev;
		free(freenode);
	}
return;
}
