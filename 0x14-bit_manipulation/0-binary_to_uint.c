#include "main.h"
#include <string.h>

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string of 0 and 1 chars
 * Return: converted number or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int i, len;
	unsigned int num = 0;

	if (!b)
		return (0);
	len = strlen(b);
	for (i = 0; i < len; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		num += (unsigned int)(b[i] - '0') << (len - i - 1);
	}
	return (num);
}
