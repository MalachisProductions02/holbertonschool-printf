#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: The format string containing specifiers
 * 
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i;
    char *str;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++; /* Move to specifier */
            if (format[i] == 'c') /* Character */
                count += _putchar(va_arg(args, int));
            else if (format[i] == 's') /* String */
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                    count += _putchar(*str++);
            }
            else if (format[i] == '%') /* Print % */
                count += _putchar('%');
            else /* Invalid specifier, print as-is */
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
        }
        else
            count += _putchar(format[i]);
    }

    va_end(args);
    return (count);
}
