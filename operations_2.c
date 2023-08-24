#include "monty.h"
/**
 * add -  adds the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: number of the line we are at
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *second = *stack;
	int n = 0;

	for (; second != NULL; second = second->prev)
	{
		n++;
		if (n == 2)
			break;
	}
	if (n < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	second->n += (*stack)->n;
	*stack = second;
	free(second->next);
	second->next = NULL;
}

/**
 * nop - doesn’t do anything.
 * @stack: pointer to the top of the stack
 * @line_number: number of the line we are at
 */
void nop(stack_t **stack, unsigned int line_number)
{
	*stack = *stack;
	line_number = line_number;
}

