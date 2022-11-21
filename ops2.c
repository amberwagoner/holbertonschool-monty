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
		arg = "error"
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

/**
 * free_stack - frees the stack
 * @stack: the stack to be freed
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
}

/**
 * executor - finds a match for the provided command and associates it
 * with a function name.
 * @stack: Pointer to the stack
 * @cmd: The current token from main
 * @lncnt: The current line count
 * Return: the approprate function, or NULL if not found
 */

void executor(stack_t **stack, char *cmd, unsigned int lncnt)
{
	int x;
	instruction_t function[] = CODES;

	if (cmd == NULL)
		return;
	for (x = 0; function[x].opcode; x++)
	{
		if (strcmp(function[x].opcode, cmd) == 0)
		{
			function[x].f(stack, lncnt);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lncnt, cmd);
	arg = "error";
}
