#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to execute
 * @opcode: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opcode))(stack_t**, unsigned int)
{
	instruction_t instruct[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"queue", m_queue},
		{"stack", m_stack},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"mul", m_mul},
		{"div", m_div},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{NULL, NULL}
	};
	int o;

	for (o = 0; op_funcs[o].opcode; o++)
	{
		if (_strcmp(opcode, op_funcs[o].opcode) == 0)
			return (op_funcs[o].f);
	}

	return (NULL);
}
