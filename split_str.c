#include "monty.h"
#include "strings.h"
/**
 * split_line - function tokenizes string input
 * by desmond and aishat
 * @string: string input
 * Return: pointer to array of strings
 */
char **split_line(char *string)
{
	char **ptr;
	char *token, *tok;
	int i = 0;
	char *dup = str_dup(string);

	if (string == NULL)
		return (NULL);
	tok = strtok(dup, " $\n\t");
	while (tok)
	{
		i++;
		tok = strtok(NULL, " $\n\t");
	}
	i++;

	ptr = malloc(sizeof(char *) * i);
	if (!ptr)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	i = 0;
	token = strtok(string, " $%\n\t");
	while (token)
	{
		ptr[i] = token;
		token = strtok(NULL, " $\n\t");
		i++;
	}
	free(dup);
	return (ptr);
}
