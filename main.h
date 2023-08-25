#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handlePrint(const char *fmt, int *i,
va_list args_list, char buffer_[], int flags_, int width_, int precision_, int size_);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int printChar(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int printString(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int printPercent(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);

/* Functions to print numbers */
int printInt(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int printBinary(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int printUnsigned(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int printOctal(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int printHexadecimal(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int print_hexa_upper(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);

int printHexa(va_list args_list, char map_to[],
char buffer_[], int flags_, char flag_ch, int width_, int precision_, int size_);

/* Function to print non printable characters */
int print_non_printable(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);

/* Funcion to print memory address */
int print_pointer(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int printReverse(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);

/*Function to print a string in rot 13*/
int print_rot13string(va_list args_list, char buffer_[],
	int flags_, int width_, int precision_, int size_);

/* width handler */
int handle_write_char(char c, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int write_number(int is_positive, int ind, char buffer_[],
	int flags_, int width_, int precision_, int size_);
int write_num(int ind, char bff[], int flags_, int width_, int precision_,
	int length, char padd, char extra_c);
int write_pointer(char buffer_[], int ind, int length,
	int width_, int flags_, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer_[],
	int flags_, int width_, int precision_, int size_);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);



#endif
