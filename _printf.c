#include "main.h"
/**
 * caseC - function to write character
 * @count: numbers to track character
 * @dig: argument to store values
 * Return: returns count
 */
int caseC(int count, int dig)
{
	write(1, &dig, 1);
	return (count++);
}
/**
 * caseS - function to write string
 * @count: numbers to track character
 * @dig: pointer argument to store values
 * Return: returns count
 */
int caseS(int count, char *dig)
{
	if (dig != NULL)
	{
		write(1, dig, strlen(dig));
		return (count++);
	}
	else
	{
		write(1, "(null)", 6);
		return (count + 6);
	}
}
/**
 * caseMod - function to write %
 * @count: numbers to track character
 * Return: returns count
 */
int caseMod(int count)
{
	write(1, "%", 1);
	return (count++);
}
/**
 * _printf - Produces an output according to a format
 * @format: A character string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed = 0;
	va_list args_list;

	if (format == NULL)
		return (-1);
	va_start(args_list, format);
	while (format[printed])
	{
		if (format[printed] == '%')
		{
			printed++;
			if (format[printed] == 'c')
			{
				printed = caseC(printed, va_arg(args_list, int));
			}
			else if (format[printed] == 's')
			{
				printed = caseS(printed, va_arg(args_list, char *));
			}
			else if (format[printed] == '%')
			{
				printed = caseMod(printed);
			}
		}
		else
		{
			write(1, format + printed, 1);
			printed++;
		}
	}
	va_end(args_list);
	return (printed);
}

