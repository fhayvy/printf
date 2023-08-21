#include "main.h"
/**
 * caseD - function to print digits
 * @count: track numbers of character
 * @digs: argument to store character
 * Return: returns count
 */
int caseD(int count, int digs)
{
	char *int_buffer;
	int num_digits;

	num_digits = snprintf(NULL, 0, "%d", digs);
	int_buffer = (char *)malloc(num_digits + 1);

	if (int_buffer == NULL)
	{
		return (-1);
	}
	else
	{
		snprintf(int_buffer, num_digits + 1, "%d", digs);
		write(1, int_buffer, num_digits);
		free(int_buffer);
	}

	return (count + num_digits);
}
/**
 * _printf - function that produces output accoring to a format
 * @format: formats to follow
 * Return: returns the number of integers
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0;

	va_start(arg, format);

	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == 'd')
					i = caseD(i, va_arg(arg, int));
				else if (format[i] == 'i')
					i = caseD(i, va_arg(arg, int));
			}
			else
			{
				write(1, format + i, 1);
				i++;
			}
		}
	}
	va_end(arg);
	return (i);
}
