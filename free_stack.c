#include "monty.h"

/**
* free_stack - frees the stack
* @stack: stack to be freed
* Return: void
*/

void free_stack(stack_t **stack)
{
	stack_t *ptr, *tmp;

	ptr = *stack;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
	}
}
