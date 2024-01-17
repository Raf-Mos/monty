#include"monty.h"

/**
 * splitter - split the string to array of char
 * @str: string to split
 * 
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
    free(str), str = NULL;;
    return (NULL);
    }
    token = strtok(str, " \t\n");
    while (token)
    {
    tokens[i] = _strdup(token);
    token = strtok(NULL, " \t\n");
    i++;
    }
    free (str), str = NULL;
    tokens[i] = NULL;
    return (tokens);
}

/**
* _strcmp - comp two string with n char
* @s1: 1st string
* @s2: 2nd string
*
* Return: the comp string
*/

int _strncmp(const char *s1, const char *s2, size_t n) 
{
    while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
        n--;
    }
    return (0);
}
