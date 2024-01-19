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
		dprintf(2, "L%d: can't mul, stack too short\n", cmd_line);
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
