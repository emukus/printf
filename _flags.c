#include "main.h"

/**
 * get_flag - function that turns on flags whenever _printf finds a
 * flag modifier in the format string
 * @s: char that hold the flag specifier
 * @f: pointer to the struct flags which contains the flags to turn on
 *
 * Return: 1 if flag is turned on, or 0 otherwise
 */

int get_flag(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
		case '-':
			f->minus = 1;
			i = 1;
			break;
		case '0':
			f->zero = 1;
			i = 1;
			break;
	}

	return (i);
}
