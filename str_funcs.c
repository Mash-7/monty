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

/**
 * _sch - Checks if a char is inside a string
 * @s: string to review
 * @c: char to find
 *
 * Return: On success, 1
 * On failure, 0
 */
int _sch(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			break;
		}
		i++;
	}
	if (s[i] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - Cuts a string into tokens depending of the delimit
 * @s: string to cut
 * @d: delimiters
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ult;
	int j = 0, k = 0;

	if (!s)
		s = ult;
	while (s[j] != '\0')
	{
		if (_sch(d, s[j]) == 0 && s[j + 1] == '\0')
		{
			ultimo = s + j + 1;
			*ultimo = '\0';
			s = s + k;
			return (s);
		}
		else if (_sch(d, s[j]) == 0 && _sch(d, s[j + 1]) == 0)
			i++;
		else if (_sch(d, s[j]) == 0 && _sch(d, s[j + 1]) == 1)
		{
			ult = s + j + 1;
			*ult = '\0';
			ult++;
			s = s + k;
			return (s);
		}
		else if (_sch(d, s[j]) == 1)
		{
			k++;
			j++;
		}
	}
	return (NULL);
}
