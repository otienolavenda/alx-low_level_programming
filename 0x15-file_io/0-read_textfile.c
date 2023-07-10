#include "main.h"

/**
 * read_textfile - reads a text file and prints to
 * POSIX standard output
 * @filename: file to be read
 * @letters: number of letters to read and print
 * Return: number of letters read and printed or 0 if it fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t readd, written;
	char *buff;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		buff = malloc(sizeof(char) * letters);
		if (buff == NULL)
			return (0);
		readd = read(fd, buff, letters);
		if (readd == -1)
			return (0);
		written = write(STDOUT_FILENO, buff, readd);
		if (written != readd)
			return (0);
		close(fd);
		free(buff);
		return (written);
	}
	return (0);
}
