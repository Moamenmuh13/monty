#include "main.h"
/**
 * main - entry point
 * @argc: number of arguments passed to the main func
 * @argv: array of argumetns passed
 * Return: 0 in case of success
*/
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	char *file_name = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (argv[1])
		file_name = argv[1];

	fd = fopen(file_name, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (EXIT_FAILURE);
	}
	excute_file(fd);
	fclose(fd);
	return(0);
}
