#include "monty.h"
/**
 * _sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: number of the line we are at
 * Return: Nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
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
	second->n -= (*stack)->n;
	*stack = second;
	free(second->next);
	second->next = NULL;
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: number of the line we are at
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line_number)
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
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	second->n /= (*stack)->n;
	*stack = second;
	free(second->next);
	second->next = NULL;
}

/**
 * _mul - The opcode mul
 * @stack: pointer to the top of the stack
 * @line_number: number of the line we are at
 * Return: Nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
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
	second->n *= (*stack)->n;
	*stack = second;
	free(second->next);
	second->next = NULL;
}

/**
 * _mod -  computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: number of the line we are at
 * Return: Nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
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
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	second->n %= (*stack)->n;
	*stack = second;
	free(second->next);
	second->next = NULL;
}
