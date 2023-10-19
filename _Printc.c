#include "main.h"

/**
 * handle_print - Prints an argument based on its type.
 *
 * @fmt: The format string in which to print the arguments.
 * @list: The list of arguments to be printed.
 * @ind: The current index in the format string.
 * @buffer: The buffer array to handle the print.
 * @flags: The active flags.
 * @width: The width of the field.
 * @precision: The precision specification.
 * @size: The size specifier.
 *
 * Returns: The number of characters printed, or -1 if an error occurred.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	// Create a lookup table of format types and their corresponding print functions.
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	// Iterate over the format string, looking for the next format type.
	for (int i = 0; fmt_types[i].fmt != '\0'; i++) {
		if (fmt[*ind] == fmt_types[i].fmt) {
			// Call the corresponding print function for the format type.
			return fmt_types[i].fn(list, buffer, flags, width, precision, size);
		}
	}

	// If no matching format type was found, print the character as-is.
	if (fmt_types[i].fmt == '\0') {
		if (fmt[*ind] == '\0') {
			return -1;
		}

		// Write the character to the buffer.
		int unknow_len = write(1, &fmt[*ind], 1);

		// If the previous character was a space and the width flag is set,
		// write the remaining spaces to the buffer.
		if (fmt[*ind - 1] == ' ' && width) {
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%') {
				--(*ind);
			}
			if (fmt[*ind] == ' ') {
				--(*ind);
			}

			return 1;
		}

		return unknow_len;
	}

	// Return an error if no format type was found and the end of the format string was not reached.
	return -1;
}
