#include "monty.h"


/**
* push - Adds a node to the stack.
* @new_node: Pointer to the new node.
* @ln: Interger representing the line number of of the opcode.
*/
void push(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp_node;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp_node = head;
	head = *new_node;
	head->next = tmp_node;
	tmp_node->prev = head;
}


/**
* pall - Adds a node to the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: line number of  the opcode.
*/
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp_node;
	(void) line_num;

	if (stack == NULL)
	exit(EXIT_FAILURE);
	tmp_node = *stack;
	while (tmp_node != NULL)
	{
		printf("%d\n", tmp_node->n);
		tmp_node = tmp_node->next;
	}
}

/**
* pop - Adds a node to the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL)
		err_func2(7, line_num);

	tmp_node = *stack;
	*stack = tmp_node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp_node);
}

/**
* pint - Prints the top node of the stack.
* @stack: Pointer to a pointer pointing to top node of the stack.
* @line_num: Interger representing the line number of of the opcode.
*/
void pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		err_func2(6, line_num);
	printf("%d\n", (*stack)->n);
}
