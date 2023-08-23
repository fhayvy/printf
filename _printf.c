#include "main.h"


/**
 * _printf - Produces an output according to a format
 * @format: A character string
 * Return: The number of characters printed
 */


int _printf(const char *format, ...)
{
	int printed = 0, ch;
	va_list args_list;

	if (format == NULL)
		return (-1);
	va_start(args_list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				ch = va_arg(args_list, int);
				write(1, &ch, 1);
				printed++;
			}
			else if (*format == 's')
			{
				sh = va_arg(args_list, char *);
				write(1, sh, strlen(sh));
				printed += strlen(sh);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				printed++;
			}
		}
		else
		{
			write(1, format, 1);
			printed++;
		}
		format++;
	}
	va_end(args_list);
	return (printed);
}
