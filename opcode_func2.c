#include"monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * @value: variable
 * Return: address of new element
 */
void push(stack_t **stack, unsigned int line_num, int value)
{
	stack_t *tmp_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
	tmp_node = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	tmp_node->prev = NULL;
	tmp_node->n = value;
	tmp_node->next = *(stack)->next;
	if (*(stack)->next)
		*(header)->next->prev = tmp_node;
	*(stack)->next = tmp_node;
}

/**
 * pushint - int for push opcode
 * @list: the content of the file
 * @line_num: line number
 * Return: the number
 */

int pushint(char *list, int line_num)
{
	char *oper_code = "push";

	while (*list != '\0')
	{
		if (*oper_code == *list)
		{
			oper_code++;
			list++;
			if (*oper_code == '\0')
				while (*list)
				{
					if ((*list >= '0' && *list <= '9') || *list == '-')
					{
					combination_finder(list, line_num);
					return (atoi(list));
					}
					else if (*list == ' ')
					list++;
					else
					{
					fprintf(stderr, "L%d: usage: push integer\n", line_num);
					exit(EXIT_FAILURE);
					}
				}
		}
		else
		list++;
	}
	return (0);
}

/**
 * combination_finder - finds nonnumbers and number combinations
 * @list: the string
 * @line_num: line number
 * Return: 1
 */

int combination_finder(char *list, int line_num)
{
	int x = 1;

	while (list[x])
	{
		if (list[x] == '\0' || list[x] == '\n')
			break;
		if ((list[x] >= '0' && list[x] <= '9') || list[x] == ' ')
			x++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

/**
 * new_line_finder - finds newline
 * @list: the string to find \n
 * Return: 1 || 0
 */

int new_line_finder(char *list)
{
	char *cmd = "\n";

	while (*list != '\0')
	{
		if (*cmd == *list)
		{
			cmd++;
			list++;
			if (*cmd == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}
