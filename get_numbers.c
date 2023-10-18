#include "main.h"

/**
 * convert - Function to convert a number to a specified base
 * @number: The number
 * @base: The base
 * @flags: The flags
 * @parameters: The parameters struct
 *
 * Return: The converted string
 */
char *convert(long int number, int base, int flags, params_t *parameters)
{
	static char *charArray;
	static char buffer[50];
	char sign = 0;
	char *pointer;
	unsigned long num = number;
	(void)parameters;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		num = -number;
		sign = '-';
	}
	charArray = flags & CONVERT_LOWERCASE ? "0123456789abcdef"
			: "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';

	do	{
		*--pointer = charArray[num % base];
		num /= base;
	} while (num != 0);

	if (sign)
		*--pointer = sign;
	return (pointer);
}

/**
 * print_unsigned - Function to print unsigned integer numbers
 * @argPointer: The argument pointer
 * @parameters: The parameters struct
 *
 * Return: The number of bytes printed
 */
int print_unsigned(va_list argPointer, params_t *parameters)
{
	unsigned long value;

	if (parameters->l_modifier)
		value = (unsigned long)va_arg(argPointer, unsigned long);
	else if (parameters->h_modifier)
		value = (unsigned short int)va_arg(argPointer, unsigned int);
	else
		value = (unsigned int)va_arg(argPointer, unsigned int);
		parameters->unsign = 1;
	return (print_number(convert(value, 10, CONVERT_UNSIGNED, parameters),
		parameters));
}

/**
 * print_address - Function to print an address
 * @argPointer: The argument pointer
 * @parameters: The parameters struct
 *
 * Return: The number of bytes printed
 */
int print_address(va_list argPointer, params_t *parameters)
{
	unsigned long int number = va_arg(argPointer, unsigned long int);
	char *str;

	if (!number)
		return (_puts("(nil)"));

	str = convert(number, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, parameters);
	*--str = 'x';
	*--str = '0';

	return (print_number(str, parameters));
}

