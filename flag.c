#include "main.h"

/**
 * Done by astro
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flag:
 */
int get_flag(const char *format, int *x)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int y, curr_x;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_x = *x + 1; format[curr_x] != '\0'; curr_x++)
	{
		for (y = 0; FLAG_CH[j] != '\0'; y++)
			if (format[curr_x] == FLAGS_CH[y])
			{
				flag |= FLAG_ARR[y];
				break;
			}

		if (FLAG_CH[y] == 0)
			break;
	}

	*x = curr_x - 1;

	return (flag);
}
