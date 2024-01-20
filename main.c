#include "monty.h"
/**
 * main - main function
 * by desmond and aishat
 * @argc: argument count
 * @argv: argument vector
 * Return: return  0 on success
 */
int main(int argc, char **argv)
{
	stack_t *temp,  *stack = NULL;

	if (argc < 2 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		open_file(argv[1], &stack);
	}
	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	return (0);
}
