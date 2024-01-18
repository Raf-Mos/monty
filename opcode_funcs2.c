#include "monty.h"

/**
* nop - Does nothing.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void nop(stack_t **stack, unsigned int line_num)
{
(void)stack;
(void)line_num;
}


/**
* swap - Swaps the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_func2(8, line_number, "swap");
	tmp_node = (*stack)->next;
	(*stack)->next = tmp_node->next;
	if (tmp_node->next != NULL)
		tmp_node->next->prev = *stack;
	tmp_node->next = *stack;
	(*stack)->prev = tmp_node;
	tmp_node->prev = NULL;
	*stack = tmp_node;
}

/**
* add_top_nodes - Adds the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void add_top_nodes(stack_t **stack, unsigned int line_num)
{
	int addition;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_func2(8, line_num, "add");

	(*stack) = (*stack)->next;
	addition = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = addition;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* sub_top_nodes - Adds the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void sub_top_nodes(stack_t **stack, unsigned int line_num)
{
	int subtsra;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err_func2(8, line_num, "sub");


	(*stack) = (*stack)->next;
	subtsra = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = subtsra;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
* div_top_nodes - Divis the top two elements of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void div_top_nodes(stack_t **stack, unsigned int line_num)
{
	int Divis;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_func2(8, line_num, "div");

	if ((*stack)->n == 0)
		err_func2(9, line_num);
	(*stack) = (*stack)->next;
	Divis = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = Divis;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
