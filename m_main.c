#include "monty.h"

char **op_toks = NULL;

/**
 * main - Entry point for monty.
 * @argc: Count of arguments passed to the program.
 * @argv: Pointer to an array of char pointers to arguments.
 *
 * Return: On success, (EXIT_SUCCESS)
 * On failure, (EXIT_FAILURE).
 */
int main(int argc, char **argv)
{
	FILE *script = NULL;
	int exit_code = EXIT_SUCCESS;
	
	if (argc != 2)
		return (usage_error());
	
	script = fopen(argv[1], "r");
	if (script == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
