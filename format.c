#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, the number of characters written is returned.
 *         On error, -1 is returned.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */

			/* Handle conversion specifiers */
			switch (*format)
			{
			case 'c':
			{
				int c = va_arg(args, int);
				count += _putchar(c);
				break;
			}

			case 's':
			{
				char *str = va_arg(args, char *);
				int i = 0;
				while (str[i] != '\0')
				{
					count += _putchar(str[i]);
					i++;
				}
				break;
			}

			case '%':
			{
				count += _putchar('%');
				break;
			}

			default:
				break;
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);
	return count;
}
