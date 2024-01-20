#include "monty.h"
#include "opcodes.h"
#include "strings.h"

char *is_int(char *str);
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
	int len, i = 0;
	instruction_t opcodes[] = {
		{"push", push}, {"pop", pop}, {"div", divi},
		{"pall", pall}, {"swap", swap}, {"mul", mull},
		{"pint", pint}, {"add", add}, {"mod", mode},
		{"nop", nop}, {"sub", sub}};

	if (cmds == NULL)
		return (-2);
	if (!cmds[1])
		data_element = -1235321;
	else
	{
		if (str_compare(is_int(cmds[1]), "no") == -1)
			data_element = atoi(cmds[1]);
		else
		{
			dprintf(2, "L%d:usage: push integer\n", line_num);
			return (-1);
		}
	}

	len = (sizeof(opcodes) / sizeof(opcodes[0]));
	while (i < len)
	{
		if (str_compare(cmds[0], opcodes[i].opcode) == 0)
		{
			opcodes[i].f(top, line_num);
			return (0);
		}
		i++;

	}
	dprintf(2, "L%d: unknown instruction %s\n", line_num, cmds[0]);
	return (-1);
}

/**
 * is_int - function checks if string is avalid integer
 * @str: sting input
 * Return : return string to confirm
 */
char *is_int(char *str)
{
	int num, i = 0;

	while (str[i])
	{
		num = str[i] - 0;
		if (num >= 48 && num <= 57)
		{
			i++;
			continue;
		}
		else
			return ("no");
	}
	return ("yes");
}
