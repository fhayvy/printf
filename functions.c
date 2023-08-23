#include "main.h"
/**
 * printChar - function to print a character
 * @args_list: list of arguments
 * @buffer_: array to store format
 * @flags_: to deduce flags
 * @width_: to deduce width
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int printChar(va_list args_list, char buffer_[], int flags_,
		int width_, int precision_, int size_)
{
	char va_extract;

	va_extract = va_arg(args_list, int);
	return (charHandler(va_extract, buffer_, flags_, width_, precision_, size_));
}
/**
 * printString - function to print a character
 * @args_list: first variable
 * @buffer_: array to store foramt
 * @flags_: third vairable
 * @width_: fourth variable
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int printString(va_list args_list, char buffer_[], int flags_, int width_, int precision_, int size_)
{
	UNUSED(buffer_);
	UNUSED(flags_);
	UNUSED(width_);
	UNUSED(precision_);
	UNUSED(size_);

	int length = 0, i;
	char *str_extract;

	str_extract = va_arg(args_list, char *);

	if (str_extract == NULL)
	{
		str_extract = "(null)";
		if (precision_ >= 6)
		{
			str_extract = " ";
		}
	}

	while (str_extract[length] != '\0')
	{
		length++;
	}

	if (width_ > length)
	{
		if (flags_ & F_MINUS)
		{
			write(1, &str_extract[0], length);
			for (i = width_ - length; i > 0; i--)
				write(1, " ", 1);
			return (width_);
		}
		else
		{
			for (i = width_ - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str_extract[0], length);
			return (width_);
		}
	}
	return (write(1, str_extract, length));
}
/**
 * printPercent - function to print a character
 * @args_list: list of arguments
 * @buffer_: array to store format
 * @flags_: to deduce flags
 * @width_: to deduce width
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int printPercent(va_list args_list, char buffer_[], int flags_,
		int width_, int precision_, int size_)
{
	UNUSED(args_list);
	UNUSED(buffer_);
	UNUSED(flags_);
	UNUSED(width_);
	UNUSED(precision_);
	UNUSED(size_);
	return (write(1, "%%", 1));
}
/**
 * printInt - function to print a character
 * @args_list: list of arguments
 * @buffer_: array to store format
 * @flags_: to deduce flags
 * @width_: to deduce width
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int printInt(va_list args_list, char buffer_[], int flags_,
		int width_, int precision_, int size_)
{
	int i = BUFF_SIZE - 2, is_negative = 0;
	long int n = va_arg(args_list, long int);
	unsigned long int num;

	n = convert_size_number(n, size_);

	if (n == 0)
	{
		buffer_[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		butffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	int write_numbers = write_number(is_negative, i, buffer_, flags_,
			width_, precision_, size_);

	return (write_numbers);
}
/**
 * printBinary - function to print a character
 * @args_list: list of arguments
 * @buffer_: array to store format
 * @flags_: to deduce flags
 * @width_: to deduce width
 * @precision_: to check precision spec
 * @size_: to get size of array
 * Return: to return numbers of characters printed
 */
int printBinary(va_list args_list, char buffer_[], int flags_,
		int width_, int precision_, int size_)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer_);
	UNUSED(flags_);
	UNUSED(width_);
	UNUSED(precision_);
	UNUSED(size_);

	n = va_arg(args_list, unsigned int);
	m = 2147483648;
	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0; sum = 0; count = 0; i < 32; i++)
	{
		sum += a[i];

		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
