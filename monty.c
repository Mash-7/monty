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

/**
 * token_arr_len - Returns length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */

/**
 * is_empty_line - Checks if a line only contains delimiters.
 * @line: Pointer to the line.
 * @delims: String of delimiter characters.
 *
 * Return: If only delimiters, 1.
 * Else, 0.
 */

