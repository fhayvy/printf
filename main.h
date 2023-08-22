#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int caseC(int count, int dig);
int caseS(int count, char *dig);
int caseMod(int count);

#endif
