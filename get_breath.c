#include "main.h"

/**
 * Done by astro
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_breath(const char *format, int *x, va_list list)
{
	int curr_x;
	int breath = 0;

	for (curr_x = *x + 1; format[curr_x] != '\0'; curr_x++)
	{
		if (is_digit(format[curr_x]))
		{
			breath *= 10;
			breath += format[curr_x] - '0';
		}
		else if (format[curr_x] == '*')
		{
			curr_x++;
			breath = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*x = curr_x - 1;

	return (breath);
}
