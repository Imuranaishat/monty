#include "opcodes.h"
#include "monty.h"

/**
 * push - function inserts data element to strack
 * by desmond and aishat
 * @topp: ponter to address of last item on stack
 * @cmd_line: command line
 * Return: nothing (void function)
 */
void push(stack_t **topp, unsigned int cmd_line)
{
	stack_t *new_node;
	if (sizeof(int) != 4)
	{
		dprintf(2, "L%d: usage: push integer", cmd_line);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = data_element;
	new_node->next = NULL;
	new_node->prev = NULL;

	if ((*topp) != NULL)
	{
		(*topp)->prev = new_node;
	}
	new_node->next = (*topp);
	(*topp) = new_node;
}

/**
 * pall - function prints stack top to bottom
 * @topp: pointer to address of last inserted item
 * @cmd_line: command line
 * Return: nothing
 */
void pall(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp = (*topp);

	if (data_element != -1235321)
	{
		dprintf(2, "L%d: require no args \n", cmd_line);
		exit(EXIT_FAILURE);
	}
	if (sizeof(data_element) != 4)
	{
		dprintf(2, "L%d: usage: pall\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - function prints data_element at the top of stack
 * @topp: pointer to address of firsr node
 * @cmd_line: command line
 * Return: nothing
 */
void pint(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp = (*topp);

	if ((*topp) == NULL)
	{
		dprintf(2, "L%d: cant't pint, stack empty\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
 * pop - function removes tha last node from stack
 * @topp: tointer to address of topmost element in stack
 * @cmd_line: commands line
 */
void pop(stack_t **topp, unsigned int cmd_line)
{
	stack_t *temp;

	if ((*topp) == NULL)
	{
		dprintf(2, "L%d: cant pop an empty stack\n", cmd_line);
		exit(EXIT_FAILURE);
	}
	temp = (*topp);
	(*topp) = temp->next;;
	free(temp);
}
void nop(stack_t **topp, unsigned int cmd_line)
{
	while ((*topp) || cmd_line)
	{
		break;
	}	
}
