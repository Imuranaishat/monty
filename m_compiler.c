#include "monty.h"
#include "opcodes.h"
#include "strings.h"
/**
 * process_cmd - function processes command
 * by deasmond and aishat
 * @cmds: command arguments
 * @top: pointer to address of recent node on stack
 * @line_num: command line nuumber
 * Return: return 0 on success
 */
int process_cmd(char **cmds, stack_t **top, unsigned int line_num)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", push}, {"pop", pop}, {"div", divi},
		{"pall", pall}, {"swap", swap}, {"mul", mull},
		{"pint", pint}, {"add", add}, {"mod", mode},
		{"nop", nop}, {"sub", sub}};

	if (cmds[1])
		data_element = atoi(cmds[1]);

	while (i < 8)
	{
		if (str_compare(cmds[0], opcodes[i].opcode) == -1)
		{
			if ((i + 1) > 8)
			{
				dprintf(2, "L%d: unknown instruction %s\n", line_num, cmds[0]);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		else
		{
			opcodes[i].f(top, line_num);
			break;
		}
	}
	return (0);
}
