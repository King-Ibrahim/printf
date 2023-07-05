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
                
                case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    unsigned int mask = 1 << (sizeof(num) * 8 - 1);
                    int printed = 0;
                    
                    /* Output the binary representation */
                    while (mask != 0)
                    {
                        if ((num & mask) != 0)
                        {
                            putchar('1');
                            count++;
                            printed = 1;
                        }
                        else if (printed)
                        {
                            putchar('0');
                            count++;
                        }
                        
                        mask >>= 1;
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
    unsigned int binary = 42;
    _printf("The binary representation of %d is %b.\n", binary, binary);
    return 0;
}
