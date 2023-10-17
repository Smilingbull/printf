#ifndef _PRINTF_H
#define _PRINTF_H

/**
 *  Include necessary header files.
 */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/**
 *  Define constants.
 */

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define FIELD_BUF_SIZE 50
#define NULL_STRING "(null)"

/** 
 * Define a macro to initialize a `ParamsStruct` struct.
 */

#define PARAMS_INITIAL_STATE {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 *  Define flags that can be used to modify the format of output.
 */

#define CONVERT_LOWER_CASE 1
#define CONVERT_AS_UNSIGNED 2

/**
 *  Define a `ParamsStruct` struct to store format parameters.
 */

typedef struct Parameters
{
  unsigned int isUnsigned : 1;
  unsigned int hasPlusFlag : 1;
  unsigned int hasSpaceFlag : 1;
  unsigned int hasHashTagFlag : 1;
  unsigned int hasZeroFlag : 1;
  unsigned int hasMinusFlag : 1;
  unsigned int width;
  unsigned int precision;
  unsigned int hasHModifier : 1;
  unsigned int hasLModifier : 1;
} ParamsStruct;

/**
 * Define a `SpecifierStruct` struct to store a format specifier and its associated function.
 */
typedef struct Specifier
{
  char *formatSpecifier;
  int (*functionPointer)(va_list, ParamsStruct *);
} SpecifierStruct;

/**
 * Declare functions.
 */
int printString(char *str);
int printChar(int character);
int printInteger(va_list arguments, ParamsStruct *parameters);
int printUnsigned(va_list arguments, ParamsStruct *parameters);
int printAddress(va_list arguments, ParamsStruct *parameters);
int printFromTo(char *start, char *stop, char *exception);
int printReverse(va_list arguments, ParamsStruct *parameters);
int printRot13(va_list arguments, ParamsStruct *parameters);
int printHex(va_list arguments, ParamsStruct *parameters);
int printBinary(va_list arguments, ParamsStruct *parameters);
int printOctal(va_list arguments, ParamsStruct *parameters);
int getPrintFunction(char *string, va_list arguments, ParamsStruct *parameters);
int getFlag(char *string, ParamsStruct *parameters);
int getModifier(char *string, ParamsStruct *parameters);
char *getWidth(char *string, ParamsStruct *parameters, va_list arguments);
char *getPrecision(char *pointer, ParamsStruct *parameters, va_list arguments);
int isDigit(int character);
int stringLength(char *string);
void initializeParams(ParamsStruct *parameters, va_list arguments);
int printfFormatted(const char *format, ...);

#endif
