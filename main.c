#include "monty.h"
char *args[2] = {NULL, NULL};
/**
 * main - entry point of our monty interpreter
 * @argc: number of cmd line arguments
 * @argv: array of pointer of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	unsigned int line_number = 1;
	size_t n = 1024;
	char *line;
	char cmd[1024];
	stack_t *mystack = NULL, *todel;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = fgets(cmd, n, fd);
	for (; line != NULL ; line_number++)
	{
		execute(&mystack, cmd, line_number);
		line = fgets(cmd, n, fd);
	}
	fclose(fd);
	if (mystack != NULL)
	{
		while (mystack)
		{
			todel = mystack;
			mystack = mystack->prev;
			free(todel);
		}
	}
	return (0);
}
