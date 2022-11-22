#include "monty.h"

/**
* add - add top two elements of the stack
* @stack: pointer to the stack
* @line_number: current line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int x, y;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		arg = "error";
		return;
	}

	current = *stack;
	x = current->n;
	current = current->prev;

	if (!current)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		arg = "error";
		return;
	}

	y = current->n;
	current->n = (x + y);
	*stack = current;
	current = current->next;
	free(current);
}

/**
* nop - doesn't do anything
* @stack: pointer to the stack
* @line_number: current line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
