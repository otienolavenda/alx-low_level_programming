#include <stdio.h>
#include "main.h"
/**
 * flip_bits - number of bits to flip
 * @n: first number
 * @m: second number
 *
 * return: number of bits that differ
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int b = 0;

	n = n ^ m;
	while (n)
	{
		n &= (n - 1);
		++b;
	}
		return (b);
}
