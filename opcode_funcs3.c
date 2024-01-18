#include "monty.h"

/**
* mul_top_nodes - Multi the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void mul_top_nodes(stack_t **stack, unsigned int line_num)
{
	int multi;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_func2(8, line_num, "mul");

	(*stack) = (*stack)->next;
	multi = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = multi;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
* mod_top_nodes - Modulo the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void mod_top_nodes(stack_t **stack, unsigned int line_num)
{
	int modulo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_func2(8, line_num, "mod");

	if ((*stack)->n == 0)
		err_func2(9, line_num);
	(*stack) = (*stack)->next;
	modulo = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = modulo;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
