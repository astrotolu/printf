#include "main.h"
/**
 * Done by astro
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @lists: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flag: Calculates active flags
 * @breath: get breath.
 * @accur: Precision specification
 * @sizes: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list lists, char buffer[],
	int flag, int breath, int accur, int sizes)
{
	int x, unknow_len = 0, counted_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (x = 0; fmt_types[i].fmt != '\0'; x++)
		if (fmt[*ind] == fmt_types[x].fmt)
			return (fmt_types[x].fn(lists, buffer, flags, breath, accur, sizes));

	if (fmt_types[x].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (breath)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (counted_chars);
}
