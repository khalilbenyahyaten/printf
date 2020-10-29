#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * _printf - produces output according to a format.
 * @format : const char
 */
int _printf(const char *format, ...)
{
char *string, ch, ch1, *sinteger;
int i, l = 0, n, integer;
va_list valist;
if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);
va_start(valist, format);
for (i = 0; format[i] != '\0'; )
{
if (format[i] != '%')
{
_putchar(format[i]);
i++;
l++;
}
else
{
if (format[i + 1] != '%' && format[i + 1] != 's' && format[i + 1] != 'c')
{
_putchar('%');
i++;
l++;
}
else
{
i++;
ch = format[i];
if (ch == 's')
{
string = va_arg(valist, char *);
if (string == NULL)
string = "(null)";
for (n = 0; string[n] != '\0'; n++)
{
l++;
_putchar(string[n]);
}
i++;
}
else if (ch == 'c')
{
l++;
ch1 = va_arg(valist, int);
_putchar(ch1);
i++;
}
else if (ch == 'd')
{
integer = va_arg(valist, int);
itoa(integer, sinteger, 10);
for (n = 0; sinteger[n] != '\0'; n++)
{
l++;
_putchar(sinteger[n]);
}
i++;
}
}
}
}
return (l);
}
