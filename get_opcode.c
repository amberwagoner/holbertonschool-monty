#include "monty.h"

/**
* get_opcode - finds match for provided command
* @stack: pointer to the stack
* @cmd: current token from main
* @line_number: current line
* Return: appropriate function or NULL if not found
*/

void get_opcode(stack_t **stack, char *cmd, unsigned int line_number)
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

	if (cmd == NULL)
		return;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(op_funcs[i].opcode, cmd) == 0)
		{
			op_funcs[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	arg = "error";
}
