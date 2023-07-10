#include "main.h"

/**
 * append_text_to_file - add text to file
 * @filename: file pointer
 * @text_content: string
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fc, rite, len = 0;

	if (!filename)
		return (-1);

	if (text_content)
		len = strlen(text_content);

	fc = open(filename, O_WRONLY | O_APPEND);
	rite = write(fc, text_content, len);

	if (fc == -1 || rite == -1)
	{
		close(fc);
		return (-1);
	}

	close(fc);
	return (1);
}
