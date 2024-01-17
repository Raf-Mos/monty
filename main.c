#include"monty.h"

/**
 * main - monty interperter
 * @ac: the number of arguments
 * @av: the arguments
 * Return: void
 */

int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	char *string[1024] = NULL;
	size_t size_str = 1024;
	int i = 0;
	FILE *fd;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILLURE);
	}
	fd = open(av[1], "r");
	if (fd == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILLURE);
	}

	for (n = 0; getline(&(string[n]), &size_str, stdin) > 0; n++)
		;
	executer(string, stack);
	free_anything(string);
	fclose(fd);
	return (0);
}
