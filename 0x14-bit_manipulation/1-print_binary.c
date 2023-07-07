#include "main.h"
#include <stdio.h>
/**
 * _print_binary -recursively print rightmost bit of non_zero number
 * in its binary representation.
 * @n: number to print
 */
void _print_binary(unsigned long int n)
{
	if (n > 1)
	{
		print_binary(n >> 1);
	}
	_putchar((n & 1) + '0');
}
