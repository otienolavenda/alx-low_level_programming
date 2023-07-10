#include "main.h"

/**
 * main - copies the content of one file to another
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */


int main(int argc, char **argv)
{
	int fd_from, fd_to, r, w;
	char buf[BUF_SIZE];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2],
		     O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR |
		     S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	if (argc == 4)
	{
		if (argv[3][0] != '1')
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}
	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}
	if (r == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			argv[1]),
		    exit(98);
	if (close(fd_from) == -1)

		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);
	return (0);
}
