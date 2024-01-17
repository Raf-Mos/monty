#include "monty.h"

/**
 * pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */

void pall(stack_t **stack, int line_num)
{
	stack_t *tmp = (*stack)->next;
	(void)line_num;
	
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
 
void pint(stack_t **stack, int line_num)
{
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->next->n)
}

/**
 * pop - removes the top element of the stack.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
 
void pop(stack_t **stack, int line_num)
{
	stack_t *tmp = NULL;

	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next->next;
	free((*stack)->next);
	if (tmp)
		tmp->prev = *stack;
	(*stack)->next = tmp;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
 
void swap(stack_t **stack, int line_num)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
