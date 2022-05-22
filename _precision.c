#include "main.h"

/**
 * get_precision - function that gets the precision from the format string
 * @p: the format string
 * @f: ptr to the struct flags that contains flags to switch on
 * @l: the argument pointer
 *
 * Return: new pointer
 */

char *get_precision(char *p, flags_t *f, va_list l)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(l, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	f->precision = d;
	return (p);
}
