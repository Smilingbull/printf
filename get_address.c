#include "main.h"

/**
 * print_from_to - Prints a range of characters from start
 * to stop except for a specific address
 * @start: Starting address
 * @stop: Stopping address
 * @except: Excepted address
 *
 * Return: The number of bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - Prints a string in reverse order
 * @argPointer: String
 * @parameters: The parameters struct
 *
 * Return: Number of bytes printed
 */
int print_rev(va_list argPointer, params_t *parameters)
{
	int length, sum = 0;
	char *str = va_arg(argPointer, char *);
	(void)parameters;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; length--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - Prints a string in Rot13 encoding
 * @argPointer: String
 * @parameters: The parameters struct
 *
 * Return: Number of bytes printed
 */
int print_rot13(va_list argPointer, params_t *parameters)
{
	int i, index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(argPointer, char *);
	(void)parameters;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}

