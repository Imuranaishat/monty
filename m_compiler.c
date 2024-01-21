#include "monty.h"
#include "opcodes.h"
#include "strings.h"

int is_int(char *str);
int power(int num);
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


	if (!cmds[1])
		data_element = -1235321;
	else
	{
		if (is_int(cmds[1]) != -1235321)
			data_element = is_int(cmds[1]);
		else
		{
			dprintf(2, "L%d:usage: push integer\n", line_num);
			return (-1);
		}
	}
	command = cmds;
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
 * Return: return string to confirm
 */
int is_int(char *str)
{
	int num, i = 0;
	int len, real_num = 0;
	int number = 0;

	len = get_len(str);
	if (str[0] == 45)
	{
		i++;
		len--;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			num = str[i] - 48;
			if (power(len - 1) != 0)
				number = num * power(len - 1);
			else
				number = num + power(len - 1);
			len--;
			real_num += number;
			i++;
		}
		else
			return (-1235321);
	}
	if (str[0] == 45)
		real_num = 0 - real_num;
	return (real_num);
}

/**
 * power - function rais 10 to a power
 * @num: number
 * Return: return power of 10 to num
 */
int power(int num)
{
	int i = 1;

	if (num == 0)
		return (0);
	while (num > 0)
	{
		i *= 10;
		num--;
	}
	return (i);
}
