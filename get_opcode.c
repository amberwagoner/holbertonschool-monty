#include "monty.h"

/**
* get_op - finds match for provided command
* @stack: pointer to the stack
* @function_name: name of the function
* @line_number: current line
* Return: appropriate function or NULL if not found
*/

void get_op(char *function_name, unsigned int line_number, stack_t **stack)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"NULL", NULL}
	};

	unsigned int i;

	for (i = 0; op_funcs[i].opcode != NULL; i++)
	{
		if (strcmp(op_funcs[i].opcode, function_name) == 0)
			op_funcs[i].f(stack, line_number);
	}
}
