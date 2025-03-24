#include <unistd.h>

/**
 * _putchar - Imprime un caracter
 * @c: Caracter
 * Return: 1 exito, -1 error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
