#include "main.h"


/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evluated
 * Return: 1 if c is printable, 0 otherwise
 */


int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}



/**
 * append_hexa_code - Append ascii in hexadecimal code to buffer
 * @buffer_: Array of characters
 * @i: Index at which to start appending
 * @ascii_code: ASSCI code
 * Return: Always 3
 */


int append_hexa_code(char ascii_code, char buffer_[], int i)
{
	char map_to_[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer_[i++] = '\\';
	buffer_[i++] = 'x';

	buffer_[i++] = map_to_[ascii_code / 16];
	buffer_[i] = map_to_[ascii_code % 16];

	return (3);
}



/**
 * is_digit - Verifies if char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */


int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}



/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: Casted value of num
 */


long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}



/**
 * convert_size_unsgnd - Casts a number to a specified size
 * @num: Number to be casted
 * @size: Number indicating type to be casted
 * Return: Casted value of num
 */


long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
