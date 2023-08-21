#include "main.h"
/**
 * caseC - function to write single character
 * @count: numbers to track character
 * @dig: argument to store values
 * Return: returns count
 */
int caseC(int count, int dig)
{
	write(1, &dig, 1);
	return (count);
}
/**
 * caseS - function to write string
 * @count: numbers to tract character
 * @dig: pointer argument to store values
 * Return: returns count
 */
int caseS(int count, char *dig)
{
	if (dig != NULL)
	{
		write(1, dig, strlen(dig));
		return (count + strlen(dig));
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
	return (cont + 1);
}
/**
 * _printf - Produces output according to a format
 * @format: A character string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int dig, i = 0;
	char *dig2;

	va_start(args, format);

	if (format)
	{
		while (format[i])
		{
			if (*format[i] == '%')
			{
				i++;
				if (*format == 'c')
					i = caseC(i, va_arg(arg, int));
				else if (*format == 's')
					i = caseC(i, va_arg(arg, char *));
				else if (*format == 'c')
					i = caseMod(i);
			}
			else
			{
				write(1, format, 1);
				i++;
			}
		}
	}
	va_end(args);
	return (printed);
}
