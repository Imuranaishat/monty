#include "monty.h"
/**
 * open_file - function opens a file and read content by lines
 * by desmond and aishat
 * @file_name: file to be opend
 * @stack_head: pointer to address fo last item in stack
 * Return: return 0 on success
 */
int open_file(char *file_name, stack_t **stack_head)
{
	FILE *fd;
	char *line = NULL;
	size_t n = 1;
	char **cmd;
	unsigned int line_count = 0;

	fd = fopen(file_name, "r");
	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &n, fd) > 0)
	{
		line_count++;
		cmd = split_line(line);
		process_cmd(cmd, stack_head, line_count);
	}
	fclose(fd);
	exit(EXIT_SUCCESS);
}
