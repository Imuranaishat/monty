#include "opcodes.h"
/**
 * stack_len - function gets length of stack
 * @head: pointer to first node
 * Return: returrn size of stack
 */
int stack_len(stack_t *head)
{
	int i = 0;

	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
/**
 * swap - function swaps the last item on tack with item after it
 * @topp:pointer to address of node at top of stack
 * @cmd_line: commands line
 * Return: return nothing (void)
 */
void swap(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp, *top_next;
	int i;

	if (stack_len((*topp)) < 2)
	{
		dprintf(2, "l%d: can't swap, stack too short\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	i = (*topp)->n;
	temp = (*topp);
	top_next = temp->next;
	temp->n = top_next->n;
	top_next->n = i;
	(*topp) = temp;
}


/**
 * add - function adds the topmost two elemtents
 * @topp: pointer to address of top item
 * @cmd_line: commands line
 * Return: return nothing
 */
void add(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp;
	int i;

	if (stack_len((*topp)) < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	i = (*topp)->n;
	temp = (*topp)->next;
	temp->n = temp->n + i;
	free(*topp);
	(*topp) = temp;
}

/**
 * sub - function subtracts the topmost two elemtents
 * @topp: pointer to address of top item
 * @cmd_line: commands line
 * Return: return nothing
 */
void sub(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp;
	int i;

	if (stack_len((*topp)) < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	i = (*topp)->n;
	temp = (*topp)->next;
	temp->n = temp->n - i;
	free((*topp));
	(*topp) = temp;
}

/**
 * divi - function divide the topmost two elemtents
 * @topp: pointer to address of top item
 * @cmd_line: commands line
 * Return: return nothing
 */
void divi(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp;
	int i;

	if (stack_len((*topp)) < 2)
	{
		dprintf(2, "L%d: can't div stack too short\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	if ((*topp)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", cmd_line);
		exit(EXIT_FAILURE);
	}

	i = (*topp)->n;
	temp = (*topp)->next;
	temp->n = temp->n / i;
	free((*topp));
	(*topp) = temp;
}

