#include "main.h"
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int x, counted = 0, counted_chars = 0;
	int flag, breath, accur, sizes, buff_ind = 0;
	va_list lists;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (x = 0; format && format[x] != '\0'; i++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			counted_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flag(format, &x);
			breath = get_breath(format, &x, lists);
			accur = get_accur(format, &x, lists);
			sizes = get_sizes(format, &x);
			++x;
			counted = handle_print(format, &x, lists, buffer,
				flag, breath, accur, sizes);
			if (counted == -1)
				return (-1);
			counted_chars += counted;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(lists);

	return (counted_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

