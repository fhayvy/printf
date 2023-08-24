#include "main.h"
/**
 * get_width - function to deduce the width
 * @format: first argument that contains formated string
 * @i: position of format arguments to be printed
 * @args_list: list of argument
 * Return: returns width
 */
int get_width(const char *format, int *i, va_list args_list)
{
	int current_indx;
	int width = 0;

	for (current_indx = *i + 1; format[current_indx] != '\0'; current_indx++)
	{
		if (is_digit(format[current_indx]))
		{
			width *= 10;
			width += format[current_indx] - '0';
		}
		else if (format[current_indx] == '*')
		{
			current_indx++;
			width = va_arg(args_list, int);
			break;
		}
		else
			break;
	}
	*i = current_indx - 1;
	return (width);
}
