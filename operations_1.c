#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: pointer to the top of the stack
 * @line_number: the command line number
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int data;

	if (args[1] == NULL || atoi(args[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(args[1]);
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		*stack = tmp;
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (tmp != NULL)
		tmp->next = *stack;
	(*stack)->n = data;
	(*stack)->prev = tmp;
	(*stack)->next = NULL;
}

/**
 * pall -  prints all the values on the stack
 * starting from the top of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: the command line number in the byte code
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cp_stack = *stack;
	unsigned int n = line_number;

	if (cp_stack != NULL)
	{
		while (cp_stack)
		{
			printf("%i\n", (cp_stack)->n);
			cp_stack = cp_stack->prev;
		}
		n++;
	}
}

/**
 * pint - prints the value at the top of the stack
 * followed by a new line.
 * @stack: pointer to the top of the stack
 * @line_number: number of the line we are at
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: the line we are at in the code
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *todel = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->prev;
	free(todel);
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: number of the line we are at
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = second->n;
	second->n = n;
}

