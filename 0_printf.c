#include <unistd.h>
#include <string.h>
#include <stdlib.h>


/**
 * _printf - Produces output according to a format
 * @format: A character string
 * Return: The number of characters printed
 */


int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;
	char ch;
	char *sh;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				ch = va_arg(args, int);
				write(1, &ch, 1);
				printed++;
			}
			else if (*format == 's')
			{
				sh = va_arg(args, char *);
				write(1, sh, strlen(sh));
				printed++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
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
	va_end(arg);
	return (printed);
}
