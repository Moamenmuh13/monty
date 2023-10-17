#define _GNU_SOURCE
#include "main.h"
#include <stdlib.h>
/**
 * excute_file - to excute already opened file
 * @fd: file_discr of the opened file
 * Return: none
*/
void excute_file(FILE *fd)
{
	char *line = NULL, *command = NULL, *num = NULL;
	size_t length = 0;
	int i;

	for (i = 0; getline(&line, &length, fd) != -1; i++)
	{
		if (line == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		command = strtok(line, " \n");
		if (command == NULL)
			return;
		num = strtok(NULL, " \n");

		find_func(command, num, i);
	}
	free(line);

}

/**
 * find_func - to find the right fucntion and excute it
 * @command: the opcode
 * @num: the number next to the command
 * @line: line number
 * Return: none
*/
void find_func(char *command, char *num, int line)
{
	int i, flag = 0;
	instruction_t functions[] = {{"push", push_func}, {"pall", pall_func}};

	for (i = 0; i < 2; i++)
	{
		if (strcmp(functions[i].opcode, command) == 0)
		{
			excute_func(functions[i].f, num);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s", line, command);
		exit(EXIT_FAILURE);
	}
}
