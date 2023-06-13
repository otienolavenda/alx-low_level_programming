#include "main.h"

/**
 * _errors - print error
 * @error: exit value
 * @s: filename
 * @fd: fildes
 * Return: 0
 */
int _errors(int error, char *s, int fd)
{
	switch (error)
	{
		case 97:
			fprintf(stderr, "Usage: cp file_from file_to\n");
			exit(error);
		case 98:
			fprintf(stderr, "Error: Can't read from file %s\n", s);
			exit(error);
		case 99:
			fprintf(stderr, "Error: Can't write to %s\n", s);
			exit(error);
		case 100:
			fprintf(stderr, "Error: Can't close fd %d\n", fd);
			exit(error);
		default:
			return (0);
	}
}

/**
 * buffering - allocate space
 * @file: file
 * Return: buffer
 */
char *buffering(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		_errors(99, file, 0);
	return (buffer);
}

/**
 * close_file - close
 * @fc: file
 * Reurn: int
 */
void close_file(int fc)
{
	int c;

	c = close(fc);
	if (c == -1)
		_errors(100, NULL, fc);
}

/**
 * main - copy
 * @argc: num of args
 * @argv: vector
 * Return: int
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, reed, rite;
	char *buffer;
	mode_t mode = umask(0);

	mode = 0664;

	if (argc != 3)
		_errors(97, NULL, 0);

	buffer = buffering(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	reed = read(file_from, buffer, 1024);

	while (rite > 0)
	{
		if (file_from == -1 || reed == -1)
		{
			free(buffer);
			_errors(98, argv[1], 0);
		}

		rite = write(file_to, buffer, reed);
		if (file_to == -1 || rite == -1)
		{
			free(buffer);
			_errors(99, argv[2], 0);
		}

		reed = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	}

	close_file(file_from);
	close_file(file_to);
	return (0);
}
