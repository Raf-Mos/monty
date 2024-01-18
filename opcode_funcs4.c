#include "monty.h"

/**
* pchar - Prints the Ascii value.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void pchar(stack_t **stack, unsigned int line_num)
{
	int variable;
	(void)line_num;

	if (stack == NULL || *stack == NULL)
		string_err_func(11, line_num);

	variable = (*stack)->n;
	if (variable < 0 || variable > 127)
		string_err_func(10, line_num);
	printf("%c\n", variable);
}

/**
* pstr - Prints a string.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	int variable;
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp_node = *stack;
	while (tmp_node != NULL)
	{
	variable = tmp_node->n;
	if (variable <= 0 || variable > 127)
		break;
	printf("%c", variable);
	tmp_node = tmp_node->next;
	}
	printf("\n");
}

/**
* rotl - Rotates the first node of the stack to the bottom.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp_node = *stack;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *stack;
	(*stack)->prev = tmp_node;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
* rotr - Rotates the last node of the stack to the top.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp_node = *stack;

	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *stack;
	tmp_node->prev->next = NULL;
	tmp_node->prev = NULL;
	(*stack)->prev = tmp_node;
	(*stack) = tmp_node;
}
