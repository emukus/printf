#ifndef _PRINT_F_
#define _PRINT_F_

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing the flags to "turn on" when
 * a flag specifier is passed to the _printf() function
 * @plus: flag for the '+' character
 * @space: flag for the ' ' char
 * @hash: flag for the '#' char
 * @zero: flag for the '0' char
 * @minus: flag for the '-' char
 *
 * @width: specified fied width
 * @precision: specified field precision
 *
 * @h_mod: turns on if h_mod is specified
 * @l_mod: turns of if l_mod is specified
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;

	int width;
	int precision;

	int h_mod;
	int l_mod;
} flags_t;

/**
 * struct printHandler - a struct for choosing the right function
 * depending on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to correct printing function
 */

typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* _print f */
int _printf(const char *format, ...);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* get_flag */
int get_flag(char s, flags_t *f);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_modifier */
int get_modifier(char s, flags_t *f);
char *get_width(char *s, flags_t *f, va_list l);

/* prints_nums */
int _isdigit(int c);
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* print_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* print_alpha */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* get_precision */
char *get_precision(char *p, flags_t *f, va_list l);

/* print_address */
int print_address(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

#endif
