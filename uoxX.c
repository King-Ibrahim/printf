#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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

			case 'd':
			case 'i':
			{
				int num = va_arg(args, int);
				printf("%d", num);

				/* Count the number of digits in the integer */
				int temp = num;
				if (temp < 0)
				{
					temp = -temp;
					count++; /* Account for the negative sign */
				}
				do
				{
					temp /= 10;
					count++;
				} while (temp != 0);
				break;
			}

			case 'u':
			{
				unsigned int num = va_arg(args, unsigned int);
				printf("%u", num);

				/* Count the number of digits in the unsigned integer */
				unsigned int temp = num;
				do
				{
					temp /= 10;
					count++;
				} while (temp != 0);
				break;
			}

			case 'o':
			{
				unsigned int num = va_arg(args, unsigned int);
				printf("%o", num);

				/* Count the number of digits in the octal number */
				unsigned int temp = num;
				do
				{
					temp /= 8;
					count++;
				} while (temp != 0);
				break;
			}

			case 'x':
			{
				unsigned int num = va_arg(args, unsigned int);
				printf("%x", num);

				/* Count the number of digits in the hexadecimal number */
				unsigned int temp = num;
				do
				{
					temp /= 16;
					count++;
				} while (temp != 0);
				break;
			}

			case 'X':
			{
				unsigned int num = va_arg(args, unsigned int);
				printf("%X", num);

				/* Count the number of digits in the hexadecimal number */
				unsigned int temp = num;
				do
				{
					temp /= 16;
					count++;
				} while (temp != 0);
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

