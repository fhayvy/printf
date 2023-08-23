#include "main.h"

void print_buffer(char buffer[], int *buff_index);


/**
 * _printf - Produces an output according to a format
 * @format: A character string
 * Return: The number of characters printed
 */


int _printf(const char *format, ...)
{
	int a, printed = 0, chars_printed = 0;
	int flags_, width_, precision_, size_, buff_index = 0;
	va_list args_list;
	char BUFFER[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args_list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buffer_index++] = format[a];
			if (buffer_index == BUFF_SIZE)
				printBuffer(buffer, &buffer_index);
			chars_printed++;
		}
		else
		{
			printBuffer(buffer, &buff_index);
			flags_ = get_flags(format, &a);
			width_ = get_width(format, &a, args_list);
			precision_ = get_precision(format, &a, args_list);
			size_ = get_size(format, &a);
			++a;
			printed = handle_print(format, &a, args_list, buffer,
				flags_, width_, precision_, size_);
			if (printed == -1)
				return (-1);
			chars_printed += printed;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(args_list);
	return (chars_printed);
}


/**
 * print_buffer - Prints the content of the buffer
 * @buffer: An array of characters
 * @buff_index: Index at which to add next char, represents the length
 */


void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}
