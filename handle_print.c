#include "main.h"
/**
 * handle_print - function that prints arguments based on its type
 * @format: array that takes formatted string
 * @args_list: list of arguments
 * @indx_: index of formats in array
 * @buffer_: buffer array
 * @flags_: to get active flags
 * @width_: get width
 * @precision_: Precision spec
 * @size_: Size specifier
 * Return: returns
 */
int handle_print(const char *format, int *indx_, va_list args_list,
		char buffer_[], int flags_, int width_,
		int precision_, int size_)
{
	int i, length = 0, printed_chars = -1;

	fmt_t fmt_types[] = {
		{'c', printChar}, {'s', printString}, {'%', printPercent},
		{'i', printInt}, {'d', printInt}, {'b', printBinary},
		{'u', printUnsigned}, {'o', printOctal}, {'x', printHexadecimal},
		{'X', print_hexa_upper}, {'p', printPointer}, {'S', print_non_printable},
		{'r', printReverse}, {'R', print_rot13string}, {'\0', NULL}
	}
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (format[*indx_] == fmt_types[i].fmt)
		{
			return (fmt_types[i].fn(args_list, buffer_, flags_,
						width_, precision_, size_));
		}
	}
	if (fmt_types[i].fmt == '\0')
	{
		if (format[*indx_] == '\0')
			return (-1);
		length += write(1, "%%", 1);

		if (format[*indx_] == '\0')
			length += write(1, " ", 1);
		else
		{
			--(*indx_);
			while (format[*indx_] != ' ' && format[*indx_] != '%')
			{
				--(*indx_);
				if (format[*indx_] == ' ')
					--(*indx_);
				return (1);
			}
			length += write(1, &format[*indx_], 1);
			return (length);
		}
	}
	return (printed_chars);
}
