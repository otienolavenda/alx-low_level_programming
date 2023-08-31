#include "main.h"

/**
 * flip_bits - returns the number of bits to flip so as to get
 * from one number to another
 * @n: number
 * @m: number
 * Return: number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int i = 1, j = 0, num = 0;

	while (j <= 63)
	{
		if ((n & i) != (m & i))
			num++;
		i = i << 1;
		j++;
	}
	return (num);
}
