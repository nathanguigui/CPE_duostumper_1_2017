/*
** EPITECH PROJECT, 2017
** infin_put
** File description:
** infin_put
*/

#include "my.h"
#include <stdarg.h>

void infin_put(int len, ...)
{
	va_list ap;
	int i = 0;
	char *buff;

	va_start(ap, len);
	while (i < len) {
		buff = va_arg(ap, char *);
		my_putstr(buff);
		i = i + 1;
	}
}

void infin_puterr(int len, ...)
{
	va_list ap;
	int i = 0;
	char *buff;

	va_start(ap, len);
	while (i < len) {
		buff = va_arg(ap, char *);
		my_puterr(buff);
		i = i + 1;
	}
}
