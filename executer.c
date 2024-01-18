#include "monty.h"

/**
* opener - opens a file
* @fn: the file namepath
* Return: void
*/

void opener(char *fn)
{
	FILE *fd = fopen(fn, "r");

	if (fn == NULL || fd == NULL)
		err_func1(2, fn);

	reader(fd);
	fclose(fd);
}


/**
* reader - reads a file
* @fd: pointer to file descriptor
* Return: void
*/

void reader(FILE *fd)
{
	int line_num, tokens = 0;
	char *string = NULL;
	size_t size_str = 0;

	for (line_num = 1; getline(&string, &size_str, fd) != -1; line_num++)
	{
		tokens = splitter(string, line_num, tokens);
	}
	free(string);
}


/**
* splitter - Separates each line into tokens to determine
* which function to call
* @str: line from the file
* @line_num: line number
* @format:  storage format. If 0 Nodes will be entered as a stack.
* if 1 nodes will be entered as a queue.
* Return: Returns 0 if the opcode is stack. 1 if queue.
*/

int splitter(char *str, int line_num, int format)
{
	char *opcode, *val;

	if (str == NULL)
		err_func1(4);

	opcode = strtok(str, " \t\n");
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, " \t\n");

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	func_finder(opcode, val, line_num, format);
	return (format);
}

/**
* func_finder - find the appropriate function for the opcode
* @opcode: opcode
* @val: argument of opcode
* @format:  storage format. If 0 Nodes will be entered as a stack.
* @line_num: line number
* if 1 nodes will be entered as a queue.
* Return: void
*/
void func_finder(char *opcode, char *val, int line_num, int format)
{
	int x;
	int op_flag;

	instruction_t fl[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add_top_nodes},
		{"sub", sub_top_nodes},
		{"div", div_top_nodes},
		{"mul", mul_top_nodes},
		{"mod", mod_top_nodes},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (op_flag = 1, x = 0; fl[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, fl[x].opcode) == 0)
		{
			func_caller(fl[x].f, opcode, val, line_num, format);
			op_flag = 0;
		}
	}
	if (op_flag == 1)
		err_func1(3, line_num, opcode);
}


/**
* func_caller - Calls the required function.
* @f: Pointer to the function that is about to be called.
* @op: string representing the opcode.
* @val: string representing a numeric value.
* @line_num: line numeber for the instruction.
* @format: Format specifier. If 0 Nodes will be entered as a stack.
* if 1 nodes will be entered as a queue.
*/
void func_caller(opcode_func f, char *op, char *val, int line_num, int format)
{
	stack_t *new_node;
	int op_flag;
	int x;

	op_flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			op_flag = -1;
		}
		if (val == NULL)
			err_func1(5, line_num);
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
				err_func1(5, line_num);
		}
		new_node = create_new_node(atoi(val) * op_flag);
		if (format == 0)
			f(&new_node, line_num);
		if (format == 1)
			addtoqueue(&new_node, line_num);
	}
	else
		f(&head, line_num);
}
