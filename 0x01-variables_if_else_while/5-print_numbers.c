#include <stdio.h>

/**
 * main - print single digits from 0 to 10 followed by a newline
 *
 * Return: 0 always
 */
int main(void)
{
	char c = '0';

	while (c <= '9')
		putchar(c++);
	putchar('\n');
	return (0);
}
