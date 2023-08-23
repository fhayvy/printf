#include "main.h"
/**
 * get_flags - function to calculate flags
 * @format: first argument that contains formatted strings
 * @i: takes a paramete
 * Return: to return flags
 */
int get_flags(const char *format, int *i)
{
	int j, current_indx, flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_SPACE, 0};

	for (current_indx = *i + 1; format[current_indx] != '\0'; current_indx++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[current_indx] == FLAGS_CH[J])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = current_indx - 1;
	return (flags);
}
