#include <stdio.h>
include "main.h"

/**
 * flip_bits - returns the number of bits to flip so as to get
 * from one number to another
 * @n: number
 * @m: number
 * Return: number of bits to flip
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
