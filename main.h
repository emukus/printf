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
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
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

/* prints_nums */
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

/* print_address */
int print_address(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

#endif
