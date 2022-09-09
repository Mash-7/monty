#include "monty.h"
#include <string.>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t ft = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[ft]; ft++)
		free(op_toks[ft]);

	free(op_toks);
}

/**
 * token_arr_len - Returns length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int token_arr_len(void)
{
	unsigned int len = 0;

	while (op_toks[len])
		toks_len++;
	return (len);
}

/**
 * is_empty_line - Checks if a line only contains delimiters.
 * @line: Pointer to the line.
 * @delims: String of delimiter characters.
 *
 * Return: If only delimiters, 1.
 * Else, 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}
