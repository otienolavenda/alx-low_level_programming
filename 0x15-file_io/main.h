#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define BUF_SIZE 1024
#define ERR_MSG_LEN 50
#define MAGIC_LEN 4
#define ELF_HEADER_SIZE 52

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int remove_file(const char *filename);
int _putchar(char c);

#endif
