#include "main.h"

/**
 * _printf - Funcion imitadora a printf
 * @format: Parametro
 * Return: Resultado
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int i = 0;

				if (!str)
					str = "(null)";
				while (str[i])
					count += _putchar(str[i++]);
			}
			else if (*format == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else
			count += _putchar(*format);

		format++;
	}

	va_end(args);
	return (count);
}
