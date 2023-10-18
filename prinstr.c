#include "main.h"

/**
 * _puts - prints a string with a newline
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int _puts(char *str)
{
	char *start = str;

	while (*str)
		_putchar(*str++);
	return (str - start);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int counter;
	static char buffer[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || counter >= OUTPUT_BUF_SIZE)
	{
		write(1, buffer, counter);
		counter = 0;
	}

	if (c != BUF_FLUSH)
		buffer[counter++] = c;
	return (1);
}

