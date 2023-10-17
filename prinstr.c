#include "main.h"

/**
 * _prinstr - Function to print a string with a newline
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int _puts(char *str)
{
    char *start = str;

    while (*str)
        _putchar(*str++);
    return (str - start);
}

/**
 * _putchar - Function to write a character to stdout
 * @c: The character to print
 *
 * Return: On success, it returns 1.
 * On error, it returns -1 and sets errno appropriately.
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

