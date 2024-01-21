#include "opcodes.h"
#include "monty.h"
/**
 * free_stack - function deletes the stack
 * @top: pointer to first node
 * Return: nothing (void)
 */
void free_stack(stack_t *top)
{
	stack_t *temp = top;

	if (top != NULL)
	{
		while (top)
		{
			temp = top->next;
			free(top);
			top = temp;
		}
	}
}
