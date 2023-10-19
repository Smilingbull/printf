#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a character.
 *
 * @c: The character to print.
 * @buffer: The buffer to print the character to.
 * @flags: The flags controlling how the character is printed.
 * @width: The minimum width of the output.
 * @precision: The precision of the output.
 * @size: The size of the character type.
 *
 * Returns: The number of characters printed.
 */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size) {
  // Store the character at the left of the buffer and pad the right with spaces.
  int i = 0;
  char padd = ' ';

  UNUSED(precision);
  UNUSED(size);

  if (flags & F_ZERO) {
    padd = '0';
  }

  buffer[i++] = c;
  buffer[i] = '\0';

  if (width > 1) {
    buffer[BUFF_SIZE - 1] = '\0';
    for (i = 0; i < width - 1; i++) {
      buffer[BUFF_SIZE - i - 2] = padd;
    }

    if (flags & F_MINUS) {
      return (write(1, &buffer[0], 1) +
              write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
    } else {
      return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
              write(1, &buffer[0], 1));
    }
  }

  return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a number.
 *
 * @is_negative: Whether the number is negative.
 * @ind: The index in the buffer where the number starts.
 * @buffer: The buffer to print the number to.
 * @flags: The flags controlling how the number is printed.
 * @width: The minimum width of the output.
 * @precision: The precision of the output.
 * @size: The size of the number type.
 *
 * Returns: The number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size) {
  int length = BUFF_SIZE - ind - 1;
  char padd = ' ', extra_ch = 0;

  UNUSED(size);

  if ((flags & F_ZERO) && !(flags & F_MINUS)) {
    padd = '0';
  }
  if (is_negative) {
    extra_ch = '-';
  } else if (flags & F_PLUS) {
    extra_ch = '+';
  } else if (flags & F_SPACE) {
    extra_ch = ' ';
  }

  return (write_num(ind, buffer, flags, width, precision,
                   length, padd, extra_ch));
}

/**
 * write_num - Prints a number using a buffer.
 *
 * @ind: The index in the buffer where the number starts.
 * @buffer: The buffer to print the number to.
 * @flags: The flags controlling how the number is printed.
 * @width: The minimum width of the output.
 * @prec: The precision of the output.
 * @length: The length of the number.
 * @padd: The padding character.
 * @extra_c: The extra character (e.g., '+', '-').
 *
 * Returns: The number of characters printed.
 */
int write_num(int ind, char buffer[], int flags, int width, int prec,
              int length, char padd, char extra_c) {
  int i, padd_start = 1;

  if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0) {
    return (0); /* printf(".0d", 0)  no char is printed */
  }
  if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0') {
    buffer[ind] = padd = ' '; /* width is displayed with padding '

