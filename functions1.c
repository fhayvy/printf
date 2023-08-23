#include "main.h"


/**
 * printUnsigned - Prints an unsigned number
 * @types_: Lists of an argument
 * @buffer_: Buffer array to handle print
 * @flags_: Calculates active flags
 * @width_: get width
 * @precision_: Precision specification
 * @size_: Size specifier
 * Return: Number of characters printed
 */


int printUnsigned(va_list types_, char buffer_[], int flags_, int width_,
		int precision_, int size_)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types_, unsigned long int);

	num = convert_size_unsgnd(num, size_);

	if (num == 0)
		buffer_[i--] = '0';

	buffer_[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer_, flags_, width_, precision_, size_));
}



/**
 * printOctal - Prints an unsigned number in octal notation
 * @types_: Lists of an argument
 * @buffer_: Buffer array to handle print
 * @flags_: Calculates active flags
 * @width_: get width
 * @precision_: Precision specification
 * @size_: Size specifier
 * Return: Number of characters printed
 */


int printOctal(va_list types_, char buffer_[], int flags_, int width_,
		int precision_, int size_)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types_, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width_);

	num = convert_size_unsgnd(num, size_);

	if (num == 0)
		buffer_[i--] = '0';

	buffer_[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags_ & F_NASH && init_num != 0)
		buffer_[i--] = '\0';
	i++;

	return (write_unsgnd(0, i, buffer_, flags_, width_, precision_, size_));
}



/**
 * printHexadecimal - Prints an unsigned number in hexadecimal notation
 * @types_: Lists of an argument
 * @buffer_: Buffer array to handle print
 * @flags_: Calculates active flags
 * @width_: get width
 * @precision_: Precision specifier
 * @size_: Size specifier
 * Return: Number of characters printed
 */


int printHexadecimal(va_list types_, char buffer_[], int flags_,
		int width_, int precision_, int size_)
{
	return (print_hexa(types_, "0123456789abcdef", buffer_, flags_, 'x',
				width_, precision_, size_));
}



/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types_: List of arguments
 * @buffer_: Buffer array to handle print
 * @flags_: Calculates active flags
 * @width_: get width
 * @precision_: Precision specification
 * @size_: Size specifier
 * Return: Number of chars printed
 */



int print_hexa_upper(va_list types_, char buffer_[], int flags_,
		int width_, int precision_, int size_)
{
	return (print_hexa(types_, "0123456789abcdef", buffer_, flags_, 'X',
				width_, precision_, size_));
}



/**
 * print_hexa - Prints a hexadecimal number in upper or lower
 * @types_: Lists of an argument
 * @map_to_: Array of values to map the number to
 * @buffer_: Buffer array to handle print
 * @flags_: Calculates active flags
 * @width_: get width
 * @flags_ch_: Calculates active flags
 * @precision_: Precision specifier
 * @size_: Size specifier
 * Return: Number of chars printed
 */


int print_hexa(va_list types_, char map_to_[], char buffer_[], int flags_,
		char flags_ch_, int width_, int precision_, int size_)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types_, unsigned long int);

	unsigned long init init_num = num;

	UNUSED(width_);

	num = convert_size_unsgnd(num, size_);

	if (num == 0)
		buffer_[i--] = '0';
	buffer_[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_[i--] = map_to_[num % 16];
		num /= 16;
	}
	if (flags_ & F_HASH && init_num != 0)
	{
		buffer_[i--] = flag_ch_;
		buffer_[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buffer_, flags_, width_, precision_, size_));
}
