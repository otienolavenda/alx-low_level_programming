#include <stdio.h>
#include "main.h"
/**
 * binary_to_uint -convert string representation of binary number to uint
 * @b:binary num
 * return: the converted num, or 0 if 'b' is NULL or contains
 * sysmbols besides 0 or 1.
 * return :int
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
