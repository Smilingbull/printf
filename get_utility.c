#include "main.h"

/**
 * is_printable - Checks if a character is printable.
 *
 * @c: The character to check.
 *
 * Returns: 1 if the character is printable, 0 otherwise.
 */
int is_printable(char c) {
  return (c >= 32 && c < 127);
}

/**
 * append_hexa_code - Appends the hexadecimal code of a character to a buffer.
 *
 * @buffer: The buffer to append the hexadecimal code to.
 * @i: The index in the buffer to start appending at.
 * @ascii_code: The ASCII code of the character.
 *
 * Returns: 3, which is the length of the hexadecimal code.
 */
int append_hexa_code(char ascii_code, char buffer[], int i) {
  char map_to[] = "0123456789ABCDEF";

  buffer[i++] = '\\';
  buffer[i++] = 'x';

  buffer[i++] = map_to[ascii_code / 16];
  buffer[i] = map_to[ascii_code % 16];

  return 3;
}

/**
 * is_digit - Checks if a character is a digit.
 *
 * @c: The character to check.
 *
 * Returns: 1 if the character is a digit, 0 otherwise.
 */
int is_digit(char c) {
  return (c >= '0' && c <= '9');
}

/**
 * convert_size_number - Casts a number to the specified size.
 *
 * @num: The number to cast.
 * @size: The size to cast the number to.
 *
 * Returns: The casted number.
 */
long int convert_size_number(long int num, int size) {
  switch (size) {
    case S_LONG:
      return num;
    case S_SHORT:
      return (short)num;
    default:
      return (int)num;
  }
}

/**
 * convert_size_unsigned - Casts an unsigned number to the specified size.
 *
 * @num: The unsigned number to cast.
 * @size: The size to cast the unsigned number to.
 *
 * Returns: The casted unsigned number.
 */
long int convert_size_unsigned(unsigned long int num, int size) {
  switch (size) {
    case S_LONG:
      return num;
    case S_SHORT:
      return (unsigned short)num;
    default:
      return (unsigned int)num;
  }
}

