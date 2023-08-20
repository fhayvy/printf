#include "main.h"


/**
 * _printf - function that produces output accoring to a format
 * @format: formats to follow
 * Return: returns the number of integers
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0;
	int dig;
	char *int_buffer;

	va_start(arg, format);

	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;
				switch (format[i])
				{
					case 'd':
					case 'i':
						dig = va_arg(arg, format);
						int_buffer = (char *)malloc(sizeof(int_buffer) + 1);

						if (int_buffer)
						{
							snprintf(int_buffer, sizeof(int_buffer) + 1, "%d", dig);
							write(1, int_buffer, strlen(int_buffer));
							free(int_buffer);
						}
					default:
						break;
				}
			}
			else
			{
				write(1, format + i, 1);
			}
			i++;
		}
	}
	va_end(arg);
	return (i);
}
