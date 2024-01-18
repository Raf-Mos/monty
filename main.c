#include "monty.h"
stack_t *head = NULL;

/**
* main - entry point
* @ac: arguments count
* @av: list of arguments
* Return: always 0
*/

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opener(av[1]);
	free_nodes();
	return (0);
}

/**
* create_new_node - Creates a node.
* @n: Number to go inside the node.
* Return: Upon sucess a pointer to the node. Otherwise NULL.
*/

stack_t *create_new_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		err_func1(4);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}

/**
* free_nodes - Frees nodes in the stack.
*/
void free_nodes(void)
{
	stack_t *new_tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		new_tmp = head;
		head = head->next;
		free(new_tmp);
	}
}

/**
* addtoqueue - Adds a node to the queue.
* @new_node: Pointer to the new node.
* @line_num: line number of the opcode.
*/
void addtoqueue(stack_t **new_node,
__attribute__((unused))unsigned int line_num)
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
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *new_node;
	(*new_node)->prev = tmp_node;
}
