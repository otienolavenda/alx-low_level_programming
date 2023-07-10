#include "main.h"

/**
 * _errors - print error
 * @error: exit value
 * @s: filename
 * @fd: file descriptor
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
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - close
 * @fc: file
 * Return: int
 */
void close_file(int fc)
{
	int c;

	c = close(fc);
	if (c == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", fc);
		exit(100);
	}
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
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = buffering(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	reed = read(file_from, buffer, 1024);
	while (rite > 0)
	{
		if (file_from == -1 || reed == -1)
		{
			fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		rite = write(file_to, buffer, reed);
		if (file_to == -1 || rite == -1)
		{
			fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		reed = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	}
	free(buffer);
	close_file(file_from);
	close_file(file_to);
	return (0);
}
