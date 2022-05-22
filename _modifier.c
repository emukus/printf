#include "main.h"

/**
 * get_modifier - function that turns on flags for modifier functions
 * @s: the format string
 * @f: the parameters struct
 *
 * Return: if modifier was valid
 */

int get_modifier(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
	case 'h':
		i = f->h_mod = 1;
		break;
	case 'l':
		i = f->l_mod = 1;
		break;
	}

	return (i);
}

/**
 * get_width - function that gets the width from the format string
 * @s: the format string
 * @f: pointer to the struct flags which contains the flags to turn on
 * @l: the argument pointer
 *
 * Return: new pointer
 */

char *get_width(char *s, flags_t *f, va_list l)
/* should this function use char **s and modify the pointer? */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(l, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	f->width = d;
	return (s);
}
