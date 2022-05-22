#include "main.h"

/**
 * get_print - function that selects the correct print function
 * based on the conversion speficier passed to _printf()
 * @s: char that holds the conversion specifier
 *
 * Description: loops through the func_arr[] structs array
 * to find a match between specifier passed to _printf & the
 * first element of the struct to select the appropriate printing
 * function
 *
 * Return: ptr to matching print function
 */

int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex_big},
		{'S', print_bigS},
		{'p', print_address},
		{'r', print_rev},
		{'R', print_rot13},
		{'%', print_percent},
	};

	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
