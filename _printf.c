#include "main.h"

/**
 * _printf - Function to print formatted output
 * @format: format string
 *
 * Return: The number of bytes printed
 */
int _printf(const char *format, ...)
{
    int byteCount = 0;
    va_list argList;
    char *currentPointer, *startPointer;
    params_t parameters = PARAMS_INIT;

    va_start(argList, format);

    if (!format || (format[0] == '%' && !format[1]))
        return -1;

    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return -1;

    for (currentPointer = (char *)format; *currentPointer; currentPointer++)
    {
        init_params(&parameters, argList);

        if (*currentPointer != '%')
        {
            byteCount += _putchar(*currentPointer);
            continue;
        }

        startPointer = currentPointer;
        currentPointer++;

        while (get_flag(currentPointer, &parameters))
        {
            currentPointer++;
        }

        currentPointer = get_width(currentPointer, &parameters, argList);
        currentPointer = get_precision(currentPointer, &parameters, argList);

        if (get_modifier(currentPointer, &parameters))
            currentPointer++;

        if (!get_specifier(currentPointer))
            byteCount += print_from_to(startPointer, currentPointer,
                                       parameters.l_modifier || parameters.h_modifier ? currentPointer - 1 : 0);
        else
            byteCount += get_print_func(currentPointer, argList, &parameters);
    }

    _putchar(BUF_FLUSH);
    va_end(argList);
    return byteCount;
}

