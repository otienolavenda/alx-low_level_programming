#include "main.h"

/**
 * _putchar - writes character c to stdout
 * @c: The character to print
 *
 * Return: On successs 1.
 * On error, -1 is returnes, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
