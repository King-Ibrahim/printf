#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 *
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
					putchar(c);
					count++;
					break;
				}

				case 's':
				{
					char *str = va_arg(args, char *);
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				}

				case '%':
				{
					putchar('%');
					count++;
					break;
				}

				default:
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return count;
}

/**
 * main - Entry point
 * Return: Always 0
 *
 */

int main(void)
{
	_printf("Hello, %s! Today is %c.\n", "John", 'M');
	return 0;
}
