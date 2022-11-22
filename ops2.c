#include "monty.h"

/**
* add - add top two elements of the stack
* @stack: pointer to the stack
* @line_number: current line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);
	int length = 0;
	int sum = 0;

	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = sum;
		pop(stack, line_number);
	}
}

/**
* nop - doesn't do anything
* @stack: pointer to the stack
* @line_number: current line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
