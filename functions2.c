#include "main.h"
/**
 * printPointer - function to print value of a pointer
 * @args_list: list of arguments
 * @buffer_: array to store format
 * @flags_: to deduce flags
 * @width_: to deduce width
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int printPointer(va_list args_list, char buffer_[], int flags_,
		int width_, int precision_, int size_);
{
	char extra_c = 0, padd = '';
	int indx = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *ptr = va_arg(args_list, void *);

	UNUSED(width_);
	UNUSED(size_);

	if (ptr == NULL)
		return (write(1, "(nil)", 5));

	buffer_[BUFF_SIZE - 1] = '\0';
	UNUSED(precision_);

	num_address = (unsigned long)ptr;

	while (num_address > 0)
	{
		buffer_[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = '', length++;

	indx++;
	return (write_pointer(buffer_, indx, length,
				width_ flags_, extra_c, padd_start));
}
/**
 * print_non_printable - print ascii codes in hexa of non printable chars
 * @args_list: list of arguments
 * @buffer_: array to store format
 * @flags_: to deduce flags
 * @width_: to deduce width
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int print_non_printable(va_list args_list, char buffer_[], int flags_,
	int width_, int precision_, int size_)
{
	int i = 0, offset = 0;
	char *ptr = va_arg(args_list, char *);

	UNUSED(flags_);
	UNUSED(width_);
	UNUSED(precision_);
	UNUSED(size_);

	if (ptr == NULL)
	{
		return (write(1, "(null)", 6));
	}

	while (ptr[i] != '\0')
	{
		if (is_printable(ptr[i]))
			buffer_[i + offset] = ptr[i];
		else
			offset += append_hexa_code(ptr[i], buffer_, i + offset);
		i++;
	}
	buffer_[i + offset] = '\0';
	return (write(1, buffer_, i + offset));
}
/**
 * printCReverse - function to print a character
 * @args_list: list of arguments
 * @buffer_: array to store format
 * @flags_: to deduce flags
 * @width_: to deduce width
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int printReverse(va_list args_list, char buffer_[], int flags_,
		int width_, int precision_, int size_)
{
	char *ptr;
	int i, count = 0;

	UNUSED(buffer_);
	UNUSED(flags_);
	UNUSED(width_);
	UNUSED(size_);

	ptr = va_arg(args_list, char *);

	if (ptr == NULL)
	{
		UNUSED(precision_);

		ptr = ")Null(";
	}

	for (i = 0; ptr[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = ptr[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - function to print a character
 * @args_list: list of arguments
 * @buffer_: array to store format
 * @flags_: to deduce flags
 * @width_: to deduce width
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int print_rot13string(va_list args_list, char buffer_[], int flags_,
		int width_, int precision_, int size_)
{
	char x, in[], out[], *ptr;
	unsigned int i, j;
	int count = 0;

	in = "ABCDEFJHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	out = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ptr = va_arg(args_list, char *);

	UNUSED(buffer_);
	UNUSED(flags_);
	UNUSED(width_);
	UNUSED(precision_);
	UNUSED(size_);

	if (ptr == NULL)
		ptr = "((AHYY)";

	for (i = 0; ptr[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == prt[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}

		if (!in[j])
		{
			x = ptr[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
