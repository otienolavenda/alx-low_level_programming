#include "main.h"

/**
 * read_textfile - read file
 * @filename: file pointer
 * @letters: num of elements
 * Return: num of elements
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fc;
	char *buffer;
	ssize_t write, read;

	if (!filename)
		return(0);

	buffer = malloc(sizeof(char) * letters);
	fc = open(filename, 0);

	if (!buffer || !fc)
		return (0);

	read = read(fc, buffer , letters);
	write = write(STDOUT_FILENO, buffer , read);

	if (rite == -1 || read == -1)
	{
		free(buffer);
		close(fc);
		return (0);
	}
	
	close(fc);
	return(read);
}



