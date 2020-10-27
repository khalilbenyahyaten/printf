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
char *string , ch, ch1;
int i, l = 0, n;
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
i++;
ch =format[i];
if (ch == '%')
{
_putchar(ch);
i++;
l++;
}
else if (ch == 's')
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
}
}
return (l);
}
