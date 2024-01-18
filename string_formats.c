#include "strings.h"
/**
 * get_len - function checks lenght of string
 * by desmond and aishat
 * @str: string input
 * Return: lenght of string
 */
int get_len(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

/**
 * str_dup - function duplicates string
 * @str: original string
 * Return: return duplicate
 */
char *str_dup(char *str)
{
	int len, i;
	char *duplicate;

	len = get_len(str);
	duplicate = malloc(sizeof(char) * len);

	i = 0;
	while (str[i])
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

/**
 * str_compare - function compares two strings
 * @str1: first string
 * @str2: second string
 * Return: return 0 on success
 */
int str_compare(char *str1, char *str2)
{
	int i;

	if (get_len(str1) != get_len(str2))
		return (-1);

	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}
