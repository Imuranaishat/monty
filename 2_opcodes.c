#include "opcodes.h"
/**
 * mull - function multiplies the first 2 elements on stack
 * @topp: pointer to address of first item in stack
 * @cmd_line: commands line
 * Return: return nothing (void)
 */
void mull(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp;
	int i;

	if (stack_len((*topp)) < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	i = ((*topp))->n;
	temp = (*topp)->next;
	temp->n = temp->n * i;
	free((*topp));
	(*topp) = temp;
}

/**
 * mode - function multiplies the first 2 elements on stack
 * @topp: pointer to address of first item in stack
 * @cmd_line: commands line
 * Return: return nothing (void)
 */
void mode(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp;
	int i;

	if (stack_len((*topp)) < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	if ((*topp)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	i = ((*topp))->n;
	temp = (*topp)->next;
	temp->n = temp->n * i;
	free((*topp));
	(*topp) = temp;
}

/**
 * pchar - function multiplies the first 2 elements on stack
 * @topp: pointer to address of first item in stack
 * @cmd_line: commands line
 * Return: return nothing (void)
 */
void pchar(stack_t **topp, unsigned int cmd_line)
{

	if ((*topp)->n < 0 && (*topp)->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	if ((*topp) == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*topp)->n);
}

/**
 * pstr - function prints cahracters from stack
 * @topp: pointer to address of first item in stack
 * @cmd_line: commands line
 * Return: return nothing (void)
 */
void pstr(stack_t **topp, unsigned int cmd_line)
{

	if ((*topp) == NULL)
		printf("\n");
	cmd_line += 1;

	while ((*topp))
	{
		if ((*topp)->n >= 0 && (*topp)->n <= 127)
		{
			if ((*topp)->n == 0)
				break;

			printf("%c", (*topp)->n);
			(*topp) = (*topp)->next;
		}
		else
			break;
	}
	cmd_line -= 1;
	printf("\n");
}

/**
 * rotr - function rotates a stack
 * @topp: pointer to address of first item in stack
 * @cmd_line: commands line
 * Return: return nothing (void)
 */
void rotr(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp;
	int i, len = stack_len((*topp));
	int *ptr;

	temp = (*topp);
	if ((*topp) != NULL)
	{
		cmd_line += 1;
		ptr = malloc(sizeof(int) * len);
		i = 0;
		while (temp)
		{
			ptr[i] = temp->n;
			temp = temp->next;
			i++;
		}
		while (temp->prev)
		{
			(*topp)->n = ptr[i];
			temp = temp->prev;
			i--;
		}
	}
	cmd_line -= 1;
}
