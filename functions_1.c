#include "monty.h"
/**
 * is_valide - determine whether a opcode is valide or not
 * Return: 1 if it is validated, -1 if the cmd is wrong and 0 if args is empty
 */
int is_valide(void)
{
	int i = 0;
	int is_valide = -1;
	char *availables[11] = {
		"push", "pall", "pint", "pop",
		"swap", "add", "nop", "sub",
		"div", "mul", "mod"
	};

	if (args[0] == NULL)
		return (0);
	for (; i < 11; i++)
	{
		if (strcmp(args[0], availables[i]) == 0)
		{
			is_valide = 1;
		}
	}
	return (is_valide);
}
/**
 * tokenise - retrive the opcode and his argument from the string cmd
 * @args: array of string
 * @cmd: the commande typed
 * Return: Nothing
 */
void tokenise(char **args, char *cmd)
{
	args[0] = strtok(cmd, " ");
	args[1] = strtok(NULL, " ");
}

/**
 * execute - execute the monty opcode typed
 * @cmd: the commande typed
 * @n: line of the monty code
 * @h: pointer to the head of the stack;
 * Return: 0 on success
 */
int execute(stack_t **h, char *cmd, unsigned int n)
{
	char *cp_cmd = cmd;
	int len = strlen(cp_cmd), validated;
	instruction_t opcode[11] = {
		{"push", &push}, {"pall", &pall},
		{"pint", &pint}, {"pop", &pop},
		{"swap", &swap}, {"add", &add},
		{"nop", &nop}, {"sub", &_sub},
		{"div", &_div}, {"mul", &_mul},
		{"mod", &_mod}
	};

	for (; len >= 1; len--)
	{
		if (*cp_cmd == '\n' && len == 1)
			*cp_cmd = '\0';
		if (len == 1)
			break;
		cp_cmd++;
	}
	tokenise(args, cmd);
	validated = is_valide();
	if (validated == 0)
		return (-1);
	if (validated == -1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", n, args[0]);
		exit(EXIT_FAILURE);
	}
	for (validated = 0; validated < 11; validated++)
	{
		if (!strcmp(args[0], (opcode[validated]).opcode))
		{
			(*((opcode[validated]).f))(h, n);
			break;
		}
	}
	return (0);
}
