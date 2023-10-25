#include "main.h"
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;
	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		format++;
	}
	return (i);
}
