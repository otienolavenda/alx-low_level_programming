#include "main.h"

/**
 * create_file - create file
 * @filename: file pointer
 * @text_content: string
 * Return: 1 or -1
 */
int create_file(const char *filename, char *text_content)
{
	int fc, rite, len = 0;
	mode_t mode = 0000600;

	if (!filename)
		return (-1);
	if (text_content)
		len = strlen(text_content);

	fc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
	rite = write(fc, text_content, len);
	if (fc == -1 || rite == -1)
	{
		close(fc);
		return (-1);
	}

	close(fc);
	return (1);
}
