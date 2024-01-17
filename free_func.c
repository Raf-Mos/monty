#include"monty.h"

/**
 * free_anything - frees getline list
 * @str: pointer to array of strings
 * Return: Nothing
 */

void free_anything(char *str[])
{
	int i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

/**
 * freed_stack - frees the singly linked list
 * @head: pointer to list
 * Return: Nothing
 */

void freed_stack(stack_t *head)
{
	stack_t *cmd;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		cmd = head;
		head = head->next;
		free(cmd);
	}
}
