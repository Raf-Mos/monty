#include"monty.h"

/**
 * splitter - split the string to array of char
 * @str: string to split
 * Return: array of char
*/

char **splitter(char *str[])
{
	char *token, **tokens = NULL, *buffer = NULL;
	int counter = 0, i = 0;

	if (!str[])
		return (NULL);
	buffer = _strdup(str[]);
	token = strtok(buffer, " \t\n");
	if (token == NULL)
	{
		free(str[]), str[] = NULL;
		free(buffer), buffer = NULL;
		return (NULL);
	}
	while (token)
	{
		counter++;
		token = strtok(NULL, " \t\n");
	}
	free(buffer), buffer = NULL;
	tokens = malloc(sizeof(char *) * (counter + 1));
	if (tokens == NULL)
	{
		free(str), str = NULL;
		return (NULL);
	}
	token = strtok(str, " \t\n");
	while (token)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(str), str = NULL;
	tokens[i] = NULL;
	return (tokens);
}

/**
* _strcmp - comparaison of two strings
* @s1: 1st string
* @s2: 2nd string
*
* Return: negative if s1 < s2, positive if s1 > s2,
* zero if s1 == s2
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	return (*s1 < *s2 ? -1 : 1);
}
