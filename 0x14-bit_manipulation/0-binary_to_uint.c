#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string of 0 and 1 chars
 * Return: converted number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (!b)
		return (n);
	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		n *= 2;
		n += *b - '0';
		++b;
	}
	return (n);
}
