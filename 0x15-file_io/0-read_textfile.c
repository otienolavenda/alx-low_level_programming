#include "main.h"

/**
 * read_textfile - read fiile
 * @filename: file pointer
 * @letters: num of elements
 *
 * Return: num of elements
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fc;
	char *buffer;
	ssize_t rite, reed;

	if (!filename)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	fc = open(filename, 0);

	if (!buffer || !fc)
		return (0);

	reed = read(fc, buffer, letters);
	rite = write(STDOUT_FILENO, buffer, reed);

	if (rite == -1 || reed == -1)
	{
		free(buffer);
		close(fc);
		return (0);
	}

	close(fc);
	return (reed);
}
