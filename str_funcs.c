#include "monty.h"

/**
 * _strcmp - Compares two strings.
 * @s1: first string.
 * @s2: second tring.
 *
 * Return: if s1 == s2, 0.
 * If not, different value.
 */
int _strcmp(char *s1, char *s2)
{
	int s;

	for (s = 0; s1[s] == s2[s] && s1[s]; s++)
		;
	if (s1[s] > s2[s])
		return (1);
	if (s1[s] < s2[s])
		return (-1);

	return (0);
}

