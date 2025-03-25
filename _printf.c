#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * _printf - Imprime
 * @format: Parametro
 * Return: Devuelve el resultado
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
            i++;
            if (format[i] == '\0')
                return (-1);
            else if (format[i] == 'c')
                count += _putchar(va_arg(args, int));
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                    count += _putchar(*str++);
            }
            else if (format[i] == '%')
                count += _putchar('%');
            else
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
