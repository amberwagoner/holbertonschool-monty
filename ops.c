#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/**
* push - pushes a value to stack_t linked list
* @stack: pointer to top node of stack_t linked list
* @line_number: current working line number of Monty
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	int i = atoi(arg);

	if (!newNode)
	{
		free(newNode);
		fprintf(stderr, "Error: malloc failed\n");
		arg = "error"
		exit(EXIT_FAILURE);
	}
	
	while (*arg)
	{
		if (*arg == '-')
			arg++;
		if (isdigit(*arg) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			arg = "error";
			free(newNode);
			exit(EXIT_FAILURE);
		}
		arg++;
	}
	newNode->n = i;
	newNode->next = *stack;
	newNode->prev = NULL;

	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}

/**
* pall - prints all the values on the stack
* @stack: pointer to the stack
* @line_number: current line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = malloc(1 * sizeof(stack_t));

	if (!current)
	{
		free(current);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	(void) line_number;

	if (stack)
	{
		current = *stack;
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
	free(current);
}

/**
* pint - prints value at top of stack
* @stack: pointer to stack
* @line_number: line count from main
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current)
	{
		printf("%d\n", current->n);
		return;
	}
	else
	{
		fprintf(stderr, "L%d: can't print, stack empty\n", line_number);
		arg = "error"
		return;
	}
}

/**
* pop - removes top element of stack
* @stack: pointer to head of stack
* @line_number: line count from main
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		arg = "error";
		exit(EXIT_FAILURE);
	}

	current = (*stack)->prev;
	free(*stack);
	*stack = current;
	if (!*stack)
		return;
	(*stack)->next = NULL;

	return;
}

/**
* swap - swaps top two nodes of the stack
* @stack: pointer to head of the stack
* @line_number: line count from main
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int x, y;
	stak_t *current;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		arg = "error";
		return;
	}
	current = *stack;
	x = current->n;
	current = current->prev;
	if (!current)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		arg = "error";
		return;
	}
	y = current->n;
	current->n = x;
	current = current->next;
	current->n = y;

	return;
}
}
